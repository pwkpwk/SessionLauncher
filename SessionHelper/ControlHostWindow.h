#pragma once

class ControlHostWindow
{
private:
	static ATOM sm_class;

public:
	static HWND Create();

private:
	ControlHostWindow();
	~ControlHostWindow();

	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT InternalWindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
};
