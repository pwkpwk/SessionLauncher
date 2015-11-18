#pragma once
#include <mstsax_h.h>

namespace SessionHelper
{
	using namespace System::Windows::Interop;

	public ref class Kielbasa sealed
	{
	private:
		HMODULE						m_clientAx;
		WindowInteropHelper ^ const	m_windowHelper;
		IMsRdpClient				*m_rdpClient;
		DWORD						m_callbackCookie;

	public:
		static Kielbasa ^Create(WindowInteropHelper ^windowHelper);
		virtual ~Kielbasa();

		void LaunchSession();

	private:
		Kielbasa(WindowInteropHelper ^windowHelper);
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
