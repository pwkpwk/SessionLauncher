#include "stdafx.h"
#include "ThreadWindow.h"

namespace SessionHelper
{
	ThreadWindow::ThreadWindow()
	:	m_window(WorkerThreadWindow::Create())
	{
	}

	ThreadWindow::~ThreadWindow()
	{
		if (nullptr != m_window)
		{
			m_window->CloseAndDestroy();
		}
	}
}
