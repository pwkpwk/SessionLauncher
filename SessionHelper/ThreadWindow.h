#pragma once
#include "WorkerThreadWindow.h"

namespace SessionHelper
{
	public ref class ThreadWindow sealed
	{
	private:
		WorkerThreadWindow *m_window;

	public:
		virtual ~ThreadWindow();

	internal:
		ThreadWindow();
	};
}
