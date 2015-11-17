#include "stdafx.h"
#include "Kielbasa.h"

namespace SessionHelper
{
	Kielbasa::Kielbasa()
	{
		m_clientAx = ::LoadLibrary(TEXT("rdclientax.dll"));
		if (!m_clientAx)
		{
			DWORD error = ::GetLastError();
			printf("ERROR=%lu\n", error);
		}
	}

	Kielbasa::~Kielbasa()
	{
		::FreeLibrary(m_clientAx);
	}
}
