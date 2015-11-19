#include "stdafx.h"
#include "ControlHostWindow.h"

ATOM ControlHostWindow::sm_class = 0;

static const TCHAR CLASS_NAME[] = { TEXT("ControlHostWindow") };
static const DWORD WINDOW_STYLE = WS_OVERLAPPED | WS_CLIPCHILDREN | WS_MAXIMIZEBOX | WS_SIZEBOX | WS_THICKFRAME;

HWND ControlHostWindow::Create(SessionHelper::ClientSiteEvents ^events)
{
	HWND hwnd = NULL;

	HINSTANCE hinst = ::GetModuleHandle(NULL);

	if(!sm_class)
	{
		WNDCLASSEXW wc = { 0 };

		wc.cbSize			= sizeof(wc);
		wc.hInstance		= hinst;
		wc.lpszClassName	= CLASS_NAME;
		wc.lpfnWndProc		= WindowProc;

		sm_class = ::RegisterClassEx(&wc);
	}

	if (sm_class)
	{
		ControlHostWindow *newWindow = new ControlHostWindow(events);
		hwnd = ::CreateWindowEx(0, CLASS_NAME, CLASS_NAME, WINDOW_STYLE, 0, 0, 1024, 800, NULL, NULL, hinst, newWindow);
	}

	return hwnd;
}

ControlHostWindow::ControlHostWindow(SessionHelper::ClientSiteEvents ^events)
:	m_events( events )
{
}

ControlHostWindow::~ControlHostWindow()
{
}

LRESULT CALLBACK ControlHostWindow::WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	ControlHostWindow	*wnd;
	LRESULT				rc = 0;

	switch (message)
	{
	case WM_CREATE:
		{
			LPCREATESTRUCT pcs = reinterpret_cast<LPCREATESTRUCT>(lParam);
			LONG_PTR self = reinterpret_cast<LONG_PTR>(pcs->lpCreateParams);
			::SetWindowLongPtr(hwnd, GWLP_USERDATA, self);
		}
		break;

	default:
		wnd = reinterpret_cast<ControlHostWindow*>(::GetWindowLongPtr(hwnd, GWLP_USERDATA));
		if (wnd)
			rc = wnd->InternalWindowProc(hwnd, message, wParam, lParam);
		else
			rc = ::DefWindowProc(hwnd, message, wParam, lParam);
		break;
	}

	return rc;
}

LRESULT ControlHostWindow::InternalWindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT rc = 0;

	switch (message)
	{
	case WM_NCDESTROY:
		delete reinterpret_cast<ControlHostWindow*>(::GetWindowLongPtr(hwnd, GWLP_USERDATA));
		break;

	case WM_SIZE:
		OnSize(wParam, lParam);
		break;

	default:
		rc = ::DefWindowProc(hwnd, message, wParam, lParam);
	}

	return rc;
}

void ControlHostWindow::OnSize(WPARAM action, LPARAM size)
{
	m_events->SizeChanged(action, LOWORD(size), HIWORD(size));
}
