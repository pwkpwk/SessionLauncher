#include "stdafx.h"
#include "WorkerThreadWindow.h"

ATOM WorkerThreadWindow::sm_class = 0;

static const TCHAR CLASS_NAME[] = { TEXT("WorkerThreadWindow") };
static const DWORD WINDOW_STYLE = WS_OVERLAPPED | WS_CLIPCHILDREN | WS_MAXIMIZEBOX | WS_SIZEBOX | WS_THICKFRAME;

namespace
{
	struct THREAD_PARAMETER
	{
		IN	HANDLE				completed;	// event handle signalled when initialization of the thread has been completed.
		OUT	WorkerThreadWindow	*window;	// window object created on the thread.
	};
}

WorkerThreadWindow *WorkerThreadWindow::Create()
{
	THREAD_PARAMETER	param = { 0 };

	param.completed = ::CreateEvent(NULL, TRUE, FALSE, NULL);

	if (param.completed)
	{
		unsigned int threadId;
		HANDLE thread = reinterpret_cast<HANDLE>(_beginthreadex(nullptr, 0, ThreadStub, &param, 0, &threadId));

		if (thread)
		{
			::WaitForSingleObject(param.completed, INFINITE);

			if (!param.window)
			{
				::WaitForSingleObject(thread, INFINITE);
				::CloseHandle(thread);
			}
			else
			{
				param.window->SetThread(thread, threadId);
			}
		}

		::CloseHandle(param.completed);
	}

	return param.window;
}

void WorkerThreadWindow::CloseAndDestroy()
{
	::PostMessage(m_hwnd, WM_CLOSE, 0, 0);
	::WaitForSingleObject(m_thread, INFINITE);
	delete this;
}

WorkerThreadWindow::WorkerThreadWindow()
:	m_thread(NULL),
	m_hwnd(NULL),
	m_threadId(0)
{
}

WorkerThreadWindow::~WorkerThreadWindow()
{
}

LRESULT WorkerThreadWindow::WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	WorkerThreadWindow	*wnd;
	LRESULT				rc = 0;

	switch (message)
	{
	case WM_CREATE:
	{
		LPCREATESTRUCT pcs = reinterpret_cast<LPCREATESTRUCT>(lParam);
		LONG_PTR self = reinterpret_cast<LONG_PTR>(pcs->lpCreateParams);
		WorkerThreadWindow *window = reinterpret_cast<WorkerThreadWindow*>(self);
		window->AttachToHandle(hwnd);
		::SetWindowLongPtr(hwnd, GWLP_USERDATA, self);
	}
		break;

	default:
		wnd = reinterpret_cast<WorkerThreadWindow*>(::GetWindowLongPtr(hwnd, GWLP_USERDATA));
		if (wnd)
			rc = wnd->InternalWindowProc(hwnd, message, wParam, lParam);
		else
			rc = ::DefWindowProc(hwnd, message, wParam, lParam);
		break;
	}

	return rc;
}

LRESULT WorkerThreadWindow::InternalWindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT rc = 0;

	switch (message)
	{
	case WM_NCDESTROY:
		::PostThreadMessage(m_threadId, WM_QUIT, 0, 0);
		break;

	case WM_CLOSE:
		::DestroyWindow(hwnd);
		break;

	case WM_SIZE:
		OnSize(wParam, lParam);
		break;

	default:
		rc = ::DefWindowProc(hwnd, message, wParam, lParam);
	}

	return rc;
}

void WorkerThreadWindow::OnSize(WPARAM action, LPARAM size)
{
}

WorkerThreadWindow *WorkerThreadWindow::InternalCreateWindow()
{
	WorkerThreadWindow	*window = nullptr;
	HWND				hwnd = NULL;

	HINSTANCE hinst = ::GetModuleHandle(NULL);

	if (!sm_class)
	{
		WNDCLASSEXW wc = { 0 };

		wc.cbSize = sizeof(wc);
		wc.hInstance = hinst;
		wc.lpszClassName = CLASS_NAME;
		wc.lpfnWndProc = WindowProc;

		sm_class = ::RegisterClassEx(&wc);
	}

	if (sm_class)
	{
		window = new(std::nothrow) WorkerThreadWindow();

		if (window)
		{
			hwnd = ::CreateWindowEx(0, CLASS_NAME, CLASS_NAME, WINDOW_STYLE,
				CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
				NULL, NULL, hinst, window);

			if (!hwnd)
			{
				delete window;
				window = nullptr;
			}
			else
			{
				::ShowWindow(hwnd, SW_SHOW);
				::UpdateWindow(hwnd);
			}
		}
	}

	return window;
}

unsigned WorkerThreadWindow::ThreadStub(void *parameter)
{
	THREAD_PARAMETER	*param = reinterpret_cast<THREAD_PARAMETER*>(parameter);
	WorkerThreadWindow	*window = InternalCreateWindow();

	param->window = window;
	//
	// Signal the calling thread that thread initialization has finished.
	// This immediately invalidates the param pointer.
	//
	::SetEvent(param->completed);
	param = nullptr;

	if (window)
	{
		window->RunMessageLoop();
	}

	_endthreadex(0);
	return 0;
}

void WorkerThreadWindow::SetThread(HANDLE handle, unsigned int threadId)
{
	_ASSERTE(handle);
	_ASSERTE(!m_thread);
	m_thread = handle;
	m_threadId = threadId;
}

void WorkerThreadWindow::AttachToHandle(HWND hwnd)
{
	_ASSERTE(!m_hwnd);
	_ASSERTE(hwnd);
	_ASSERTE(::IsWindow(hwnd));

	m_hwnd = hwnd;
	::SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));
}

void WorkerThreadWindow::RunMessageLoop()
{
	MSG msg;

	while (::GetMessage(&msg, NULL, 0, 0))
	{
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
	}
}
