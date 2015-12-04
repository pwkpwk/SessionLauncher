#pragma once

class WorkerThreadWindow
{
private:
	static ATOM sm_class;
	HANDLE			m_thread;
	unsigned int	m_threadId;	// thread ID for posting the WM_QUIT message.
	HWND			m_hwnd;

public:
	static WorkerThreadWindow *Create();
	void CloseAndDestroy();

private:
	WorkerThreadWindow();
	~WorkerThreadWindow();

	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT InternalWindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	void OnSize(WPARAM action, LPARAM size);

	static WorkerThreadWindow *InternalCreateWindow();
	static unsigned __stdcall ThreadStub(void *parameter);
	void SetThread(HANDLE handle, unsigned int threadId);
	void AttachToHandle(HWND hwnd);
	void RunMessageLoop();
};