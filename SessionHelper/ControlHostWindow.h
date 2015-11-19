#pragma once
#include "ClientSiteEvents.h"
#include "gcroot.h"

class ControlHostWindow
{
private:
	static ATOM sm_class;
	gcroot<SessionHelper::ClientSiteEvents ^> m_events;

public:
	static HWND Create(SessionHelper::ClientSiteEvents ^events);

private:
	ControlHostWindow(SessionHelper::ClientSiteEvents ^events);
	~ControlHostWindow();

	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT InternalWindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	void OnSize(WPARAM action, LPARAM size);
};
