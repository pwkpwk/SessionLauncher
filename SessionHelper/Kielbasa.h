#pragma once
#include <mstsax_h.h>
#include "ClientSiteEvents.h"
#include "ThreadWindow.h"

namespace SessionHelper
{
	typedef HRESULT(WINAPI* pfnDllGetClaimsToken)(
		__in BSTR bstrClaimsHint,
		__in_opt BSTR bstrUserHint,
		__in_opt BSTR bstrUserDomainHint,
		__in BOOL bForceAdalPwdPrompt,
		__in_opt HWND hwndCredUiParent,
		__deref_out BSTR *pbstrAccessToken,
		__deref_out BSTR *pbstrAdalUserHint,
		LPRECT pParentRect,
		__in_opt BSTR bstrWindowTitle
		);

	typedef HRESULT(WINAPI* pfnDllLogoffClaimsToken)();
	typedef HRESULT(WINAPI* pfnDllCancelADALAuthentication)();
	typedef HRESULT(WINAPI* pfnDllSetAdalProperties)(__in HWND hwndParentWindow);

	public ref class Kielbasa sealed : ClientSiteEvents
	{
	private:
		HMODULE					m_clientAx;
		IMsRdpClient			*m_rdpClient;
		DWORD					m_callbackCookie;
		HWND					m_hwndMain;
		pfnDllGetClaimsToken	m_dllGetClaimsToken;
		pfnDllSetAdalProperties	m_dllSetAdalProperties;

	public:
		static Kielbasa ^Create();
		virtual ~Kielbasa();

		void SetWindow(System::Windows::Interop::WindowInteropHelper ^window);
		void Authenticate();
		void LaunchSession(System::String ^machineName);
		void LaunchProgram();
		ThreadWindow ^CreateThreadWindow();
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
