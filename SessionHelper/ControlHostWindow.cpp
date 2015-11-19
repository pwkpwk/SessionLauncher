#include "stdafx.h"
#include "ControlHostWindow.h"

ATOM ControlHostWindow::sm_class = 0;

static const TCHAR CLASS_NAME[] = { TEXT("ControlHostWindow") };

HWND ControlHostWindow::Create()
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
		ControlHostWindow *newWindow = new ControlHostWindow();
		hwnd = ::CreateWindowEx(0, CLASS_NAME, CLASS_NAME, WS_OVERLAPPED | WS_CLIPCHILDREN, 0, 0, 600, 320, NULL, NULL, hinst, newWindow);
	}

	return hwnd;
}

ControlHostWindow::ControlHostWindow()
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
		::SetWindowLong(hwnd, GWL_USERDATA, lParam);
		break;

	default:
		wnd = reinterpret_cast<ControlHostWindow*>(::GetWindowLong(hwnd, GWL_USERDATA));
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
		delete reinterpret_cast<ControlHostWindow*>(::GetWindowLong(hwnd, GWL_USERDATA));
		break;

	default:
		rc = ::DefWindowProc(hwnd, message, wParam, lParam);
	}

	return rc;
}
