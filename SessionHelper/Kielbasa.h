#pragma once
#include <mstsax_h.h>
#include "ClientSiteEvents.h"

namespace SessionHelper
{
	using namespace System::Windows::Interop;

	public ref class Kielbasa sealed : ClientSiteEvents
	{
	private:
		HMODULE			m_clientAx;
		IMsRdpClient	*m_rdpClient;
		DWORD			m_callbackCookie;

	public:
		static Kielbasa ^Create();
		virtual ~Kielbasa();

		void LaunchSession(System::String ^machineName);
		//
		// ClientSiteEvents
		//
		virtual void SizeChanged(short action, short cx, short cy);

	private:
		Kielbasa();
		bool Initialize();

		bool CreateControl();
		_Success_(return)
		_Check_return_
		static bool RegisterCallback(_In_ LPUNKNOWN rdpClient, _Out_ DWORD *cookie);
		_Check_return_
		static bool UnregisterCallback(_In_ LPUNKNOWN rdpClient, DWORD cookie);
		_Check_return_
		bool SetClientSite(_In_ LPUNKNOWN rdpClient);
	};
}
