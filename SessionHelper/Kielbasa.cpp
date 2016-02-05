#include "stdafx.h"
#include "Kielbasa.h"
#include "SessionCallback.h"
#include "ClientSite.h"

namespace SessionHelper
{
	Kielbasa ^Kielbasa::Create()
	{
		Kielbasa ^kielbasa = gcnew Kielbasa();

		if (!kielbasa->Initialize() || !kielbasa->CreateControl())
		{
			kielbasa->~Kielbasa();
			kielbasa = nullptr;
		}

		return kielbasa;
	}

	Kielbasa::Kielbasa()
	:	m_clientAx(NULL),
		m_rdpClient(nullptr),
		m_callbackCookie(0),
		m_hwndMain(NULL),
		m_dllGetClaimsToken(nullptr),
		m_dllSetAdalProperties(nullptr)
	{
	}

	Kielbasa::~Kielbasa()
	{
		if (m_rdpClient)
		{
			if (UnregisterCallback(m_rdpClient, m_callbackCookie))
				m_callbackCookie = 0;

			m_rdpClient->Disconnect();

			LPOLEOBJECT oobj;

			if (SUCCEEDED(m_rdpClient->QueryInterface(&oobj)))
			{
				oobj->Close(OLECLOSE_NOSAVE);
				oobj->Release();
			}

			m_rdpClient->Release();
			m_rdpClient = nullptr;
		}

		m_dllGetClaimsToken = nullptr;
		m_dllSetAdalProperties = nullptr;
		::FreeLibrary(m_clientAx);
	}

	void Kielbasa::SetWindow(System::Windows::Interop::WindowInteropHelper ^window)
	{
		if (nullptr == window)
		{
			m_hwndMain = NULL;
		}
		else
		{
			m_hwndMain = reinterpret_cast<HWND>((HANDLE)window->EnsureHandle());
			if (!::IsWindow(m_hwndMain))
			{
				m_hwndMain = NULL;
			}
		}
	}

	void Kielbasa::Authenticate()
	{
		using namespace ATL;

		CComBSTR	claimsHint(OLESTR("Authority=https://login.windows.net/common;Client=69b68004-6f36-421c-9d9a-3f202cb8df47;Redirect=urn:ietf:wg:oauth:2.0:oob;Resource=https://remoteapp.windowsazure.com;Site=501413"));
		CComBSTR	userHint(OLESTR("pakarpen@microsoft.com"));
		CComBSTR	domainHint(OLESTR("microsoft.com"));
		CComBSTR	bstrTitle(OLESTR("Invoke ADAL"));
		RECT		rect[1];
		BSTR		bstrToken;
		BSTR		bstrUser;

		(*m_dllSetAdalProperties)(m_hwndMain);

		::GetWindowRect(m_hwndMain, rect);

		HRESULT hr = (*m_dllGetClaimsToken)
		(
			claimsHint,
			userHint,
			domainHint,
			TRUE,
			m_hwndMain,
			&bstrToken,
			&bstrUser,
			rect,
			bstrTitle
		);

		if (SUCCEEDED(hr))
		{
			System::Diagnostics::Trace::WriteLine("Succeeded!");
		}
		else
		{
			System::Diagnostics::Trace::WriteLine("Failed!");
		}
	}

	void Kielbasa::LaunchSession(System::String ^machineName)
	{
		LPOLEINPLACEACTIVEOBJECT obj;

		if (SUCCEEDED(m_rdpClient->QueryInterface(&obj)))
		{
			HRESULT hr;
			LPOLEOBJECT oleobj = nullptr;

			hr = m_rdpClient->QueryInterface(&oleobj);

			if (SUCCEEDED(hr))
			{
				LPOLECLIENTSITE site = nullptr;
				LPOLEWINDOW ownd;

				oleobj->GetClientSite(&site);

				if (SUCCEEDED(site->QueryInterface(&ownd)))
				{
					HWND	hwnd;
					RECT	rc = { 0 };

					ownd->GetWindow(&hwnd);
					::GetClientRect(hwnd, &rc);

					if (SUCCEEDED(oleobj->DoVerb(OLEIVERB_PRIMARY, NULL, site, 0, hwnd, &rc)))
					{
						using namespace System::Runtime::InteropServices;
						using namespace ATL;

						::ShowWindow(hwnd, SW_SHOW);
						::UpdateWindow(hwnd);

						CComBSTR program(OLESTR("||269f0cd2-4fa7-477c-98e7-205e9eaa2174"));
						CComBSTR workDir(OLESTR(""));
						CComBSTR appName("ARA CMD");
						CComBSTR args(OLESTR(""));

						IMsRdpClientNonScriptable5 *client5;
						IMsRdpClient9 *client9 = nullptr;

						if (SUCCEEDED(m_rdpClient->QueryInterface(&client5)))
						{
							CComBSTR userName(OLESTR("pakarpen@microsoft.com"));
							CComBSTR password(OLESTR("<password>"));
							CComBSTR emptyBSTR(OLESTR(""));
							CComBSTR server(OLESTR("selfhostlive"));

							client5->put_AllowPromptingForCredentials(VARIANT_TRUE);
							client5->put_ShowRedirectionWarningDialog(VARIANT_FALSE);
							client5->put_RedirectionWarningType(RedirectionWarningTypeThirdPartySigned);
							client5->put_MarkRdpSettingsSecure(VARIANT_TRUE);
							client5->put_ShowRedirectionWarningDialog(VARIANT_FALSE);
							client5->put_RedirectionWarningType(RedirectionWarningTypeThirdPartySigned);
							client5->put_MarkRdpSettingsSecure(VARIANT_TRUE);
							client5->put_LaunchedViaClientShellInterface(VARIANT_FALSE);
							client5->put_TrustedZoneSite(VARIANT_FALSE);
							client5->put_DisableRemoteAppCapsCheck(VARIANT_FALSE);
							//client5->put_ClearTextPassword(password);
							client5->put_EnableCredSspSupport(VARIANT_TRUE);
							client5->put_PromptForCredentials(VARIANT_FALSE);
							client5->put_AllowCredentialSaving(VARIANT_FALSE);
							client5->put_PromptForCredsOnClient(VARIANT_FALSE);
							client5->put_NegotiateSecurityLayer(VARIANT_TRUE);
							client5->put_LaunchedViaClientShellInterface(VARIANT_FALSE);
							client5->put_TrustedZoneSite(VARIANT_FALSE);
							client5->put_ShowRedirectionWarningDialog(VARIANT_TRUE);
							client5->put_RedirectionWarningType(RedirectionWarningTypeThirdPartySigned);
							client5->put_MarkRdpSettingsSecure(VARIANT_TRUE);
							//
							// ???
							//
							// client5->put_PublisherCertificateChain();
							client5->put_WarnAboutClipboardRedirection(VARIANT_TRUE);
							client5->put_WarnAboutPrinterRedirection(VARIANT_TRUE);
							client5->put_WarnAboutDirectXRedirection(VARIANT_TRUE);
							client5->put_WarnAboutSendingCredentials(VARIANT_TRUE);

							IMsRdpPreferredRedirectionInfo *redirinfo;

							if (S_OK == m_rdpClient->QueryInterface(&redirinfo))
							{
								redirinfo->put_UseRedirectionServerName(VARIANT_FALSE);
								redirinfo->Release();
							}

							ITsWkspInternal *intern;

							if (S_OK == m_rdpClient->QueryInterface(IID_ITsWkspInternal, reinterpret_cast<LPVOID*>(&intern)))
							{
								BYTE tp[] = { 178, 217, 226, 66, 94, 77, 208, 54, 218, 106, 105, 127, 239, 82, 197, 244, 119, 39, 59, 85 };

								intern->InitWorkspaceExtension(FALSE,
									L"754606d9-5159-4514-8b2d-5c5a10610285",
									L"pakarpen@microsoft.com",
									tp, sizeof(tp),
									TRUE);
								intern->set_SupportsReconnect(FALSE);
								intern->Release();
							}

							client5->put_UseMultimon(VARIANT_TRUE);

							if (S_OK == m_rdpClient->QueryInterface(&client9))
							{
								client9->put_DesktopWidth(1920);
								client9->put_DesktopHeight(1024);
								client9->put_ColorDepth(32);
								client9->put_FullScreen(VARIANT_TRUE);
								client9->put_UserName(userName);
								client9->put_Domain(emptyBSTR);
								client9->put_Server(server);

								IMsRdpClientSecuredSettings2 *secset2;

								if (S_OK == client9->get_SecuredSettings3(&secset2))
								{
									secset2->put_StartProgram(program);
									secset2->put_WorkDir(workDir);
									secset2->put_KeyboardHookMode(2);
									secset2->Release();
								}

								IMsRdpClientTransportSettings4 *transport4;

								if (S_OK == client9->get_TransportSettings4(&transport4))
								{
									CComBSTR gatewayHost(OLESTR("ef643b51-ae9c-4841-b041-388104ae123a.remoteapp.windowsazure.com"));
									CComBSTR gatewayUser(userName);
									CComBSTR gatewayPassword(password);

									transport4->put_GatewayHostname(gatewayHost);
									transport4->put_GatewayUsageMethod(1);
									transport4->put_GatewayProfileUsageMethod(1);
									transport4->put_GatewayCredsSource(0);
									transport4->put_GatewayPreAuthRequirement(0);
									transport4->put_GatewayPreAuthServerAddr(emptyBSTR);
									transport4->put_GatewaySupportUrl(emptyBSTR);
									transport4->put_GatewayEncryptedOtpCookie(NULL);
									transport4->put_GatewayEncryptedOtpCookieSize(0);
									transport4->put_GatewayCredSharing(1);
									transport4->put_GatewayCredSourceCookie(0);
									transport4->put_GatewayAuthCookieServerAddr(emptyBSTR);
									transport4->put_GatewayEncryptedAuthCookie(NULL);
									transport4->put_GatewayEncryptedAuthCookieSize(0);
									transport4->put_GatewayAuthLoginPage(emptyBSTR);
									transport4->put_GatewayUsername(gatewayUser);
									transport4->put_GatewayDomain(emptyBSTR);
									//transport4->put_GatewayPassword(gatewayPassword);
									transport4->put_GatewayBrokeringType(1);

									transport4->Release();
								}

								IMsRdpClientAdvancedSettings8 *advset8;

								if (S_OK == client9->get_AdvancedSettings9(&advset8))
								{
									static const char LBINFO[] = { "MTB://lbinfo?param1=selfhostlive&param2=754606d9-5159-4514-8b2d-5c5a10610285\r\n" };
									BSTR lbInfo = ::SysAllocStringByteLen(LBINFO, sizeof(LBINFO) - sizeof(LBINFO[0]));
									CComBSTR keybLayout(OLESTR("0xffffffff"));

									advset8->put_AudioRedirectionMode(0);
									advset8->put_AudioCaptureRedirectionMode(VARIANT_TRUE);
									advset8->put_VideoPlaybackMode(1);
									advset8->put_AudioQualityMode(0);
									advset8->put_NetworkConnectionType(7); // UTREG_NETWORK_CONNECTION_AUTO_DETECT
									advset8->put_BandwidthDetection(VARIANT_TRUE);
									advset8->put_LoadBalanceInfo(lbInfo);
									advset8->put_RDPPort(3389);
									advset8->put_PCB(emptyBSTR);
									advset8->put_SmartSizing(VARIANT_TRUE);
									advset8->put_BitmapVirtualCacheSize(10);
									advset8->put_BitmapVirtualCache16BppSize(20);
									advset8->put_BitmapVirtualCache24BppSize(30);
									advset8->put_BitmapVirtualCache32BppSize(40);
									advset8->put_BitmapPersistence(1);
									advset8->put_ClientProtocolSpec(SmallCacheMode);
									advset8->put_EnableMouse(VARIANT_TRUE);
									advset8->put_Compress(TRUE);
									advset8->put_DisableCtrlAltDel(TRUE);
									advset8->put_ConnectToAdministerServer(VARIANT_FALSE);
									advset8->put_DisplayConnectionBar(VARIANT_TRUE);
									advset8->put_PinConnectionBar(VARIANT_TRUE);
									advset8->put_EnableAutoReconnect(VARIANT_TRUE);
									advset8->put_MaxReconnectAttempts(20);
									advset8->put_KeyBoardLayoutStr(keybLayout);
									advset8->put_BitmapCacheSize(1500);
									advset8->put_AuthenticationLevel(1);
									advset8->put_PublicMode(VARIANT_FALSE);
									advset8->put_EnableSuperPan(VARIANT_FALSE);
									advset8->put_SuperPanAccelerationFactor(1);
									advset8->put_PerformanceFlags(0x186);
									advset8->put_GrabFocusOnConnect(VARIANT_FALSE);
									advset8->put_ContainerHandledFullScreen(TRUE);

									advset8->Release();
									::SysFreeString(lbInfo);
								}
								ITSRemoteProgram2 *program2;

								if (SUCCEEDED(client9->get_RemoteProgram2(&program2)))
								{
									using namespace ATL;

									CComBSTR program(OLESTR("||269f0cd2-4fa7-477c-98e7-205e9eaa2174"));
									CComBSTR workDir(OLESTR(""));
									CComBSTR appName("ARA CMD");
									CComBSTR args(OLESTR(""));

									program2->put_RemoteProgramMode(VARIANT_TRUE);
									program2->put_RemoteApplicationName(appName);
									program2->put_RemoteApplicationProgram(program);
									program2->put_RemoteApplicationArgs(args);
#if 1
									program2->ServerStartProgram(
										program,
										args,
										args,
										VARIANT_FALSE,
										args,
										VARIANT_TRUE);
#endif
									program2->Release();
								}

								IMsRdpExtendedSettings *extset;

								if (S_OK == m_rdpClient->QueryInterface(&extset))
								{
									CComVariant var(OLESTR(""));

									extset->put_Property(UTREG_UI_FEDAUTH_TOKEN, &var);

									var = true;
									extset->put_Property(UTREG_UI_ENABLE_REMOTEEDGEBAR, &var);
									extset->put_Property(UTREG_GP_ENABLE_HARDWARE_MODE_GRAPHICS, &var);

									var = false;
									extset->put_Property(UTREG_UI_DISABLE_SEAMLESS_LANGUAGE_BAR, &var);
									extset->put_Property(UTREG_UI_DISABLE_TOUCH_REMOTING, &var);

									var = OLESTR("https://telemetry.remoteapp.windowsazure.com/webUpload?mohoroId=754606d9-5159-4514-8b2d-5c5a10610285");
									extset->put_Property(UTREG_EVENTLOG_UPLOAD_ADDRESS, &var);

									extset->Release();
								}
							}

							client5->Release();
						}

						m_rdpClient->Connect();

						if (client9)
							client9->Release();
					}

					ownd->Release();
				}

				site->Release();
				oleobj->Release();
			}

			obj->Release();
		}
	}

	void Kielbasa::LaunchProgram()
	{
		IMsRdpClient9 *client9;

		if(SUCCEEDED(m_rdpClient->QueryInterface(&client9)))
		{
			ITSRemoteProgram2 *program2;

			if (SUCCEEDED(client9->get_RemoteProgram2(&program2)))
			{
				using namespace ATL;

				CComBSTR program(OLESTR("||269f0cd2-4fa7-477c-98e7-205e9eaa2174"));
				CComBSTR workDir(OLESTR(""));
				CComBSTR appName("ARA CMD");
				CComBSTR args(OLESTR(""));

				program2->put_RemoteProgramMode(VARIANT_TRUE);
				program2->put_RemoteApplicationName(appName);
				program2->put_RemoteApplicationProgram(program);
				program2->put_RemoteApplicationArgs(args);

				program2->ServerStartProgram(
					program,
					args,
					args,
					VARIANT_FALSE,
					args,
					VARIANT_TRUE);

				program2->Release();
			}

			client9->Release();
		}
	}

	ThreadWindow ^Kielbasa::CreateThreadWindow()
	{
		return gcnew ThreadWindow();
	}

	void Kielbasa::SizeChanged(short action, short cx, short cy)
	{
		LPOLEINPLACEOBJECT inplobj;

		if (SUCCEEDED(m_rdpClient->QueryInterface(&inplobj)))
		{
			RECT rc = { 0 };

			rc.bottom = cy;
			rc.right = cx;
			inplobj->SetObjectRects(&rc, &rc);
			inplobj->Release();
		}
	}

	bool Kielbasa::Initialize()
	{
		bool initialized = true;

		m_clientAx = ::LoadLibrary(TEXT("rdclientax.dll"));
		if (!m_clientAx)
		{
			initialized = false;
		}
		else
		{
			m_dllGetClaimsToken = reinterpret_cast<pfnDllGetClaimsToken>(::GetProcAddress(m_clientAx, "DllGetClaimsToken"));
			m_dllSetAdalProperties = reinterpret_cast<pfnDllSetAdalProperties>(::GetProcAddress(m_clientAx, "DllSetADALProperties"));

			if (!m_dllGetClaimsToken || !m_dllSetAdalProperties)
			{
				initialized = false;
				m_dllGetClaimsToken = nullptr;
				m_dllSetAdalProperties = nullptr;
				::FreeLibrary(m_clientAx);
				m_clientAx = NULL;
			}
		}

		return initialized;
	}

	bool Kielbasa::CreateControl()
	{
		bool				created = false;
		LPFNGETCLASSOBJECT	getClassObject = reinterpret_cast<LPFNGETCLASSOBJECT>(::GetProcAddress(m_clientAx, "DllGetClassObject"));

		if (getClassObject)
		{
			LPCLASSFACTORY classFactory;

			if (SUCCEEDED((*getClassObject)(CLSID_MsRdpClientNotSafeForScripting, IID_IClassFactory, reinterpret_cast<LPVOID*>(&classFactory))))
			{
				IMsRdpClient *ptr;
				if (SUCCEEDED(classFactory->CreateInstance(NULL, IID_IMsRdpClient, reinterpret_cast<LPVOID*>(&ptr))))
				{
					DWORD cookie;

					if (RegisterCallback(ptr, &cookie))
					{
						if (!SetClientSite(ptr))
						{
							UnregisterCallback(ptr, cookie);
						}
						else
						{
							m_rdpClient = ptr;
							m_callbackCookie = cookie;
						}

						created = true;
					}
					else
					{
						ptr->Release();
					}
				}

				classFactory->Release();
			}
		}

		return created;
	}

	_Success_(return)
	_Check_return_
	bool Kielbasa::RegisterCallback(_In_ LPUNKNOWN rdpClient, _Out_ DWORD *cookie)
	{
		bool						registered = false;
		LPCONNECTIONPOINTCONTAINER	cpc;

		if (SUCCEEDED(rdpClient->QueryInterface(&cpc)))
		{
			LPCONNECTIONPOINT cp;

			if (SUCCEEDED(cpc->FindConnectionPoint(DIID_IMsTscAxEvents, &cp)))
			{
				ATL::CComObject<SessionCallback> *callback;

				if (SUCCEEDED(ATL::CComObject<SessionCallback>::CreateInstance(&callback)))
				{
					callback->AddRef();

					if (SUCCEEDED(cp->Advise(callback, cookie)))
					{
						registered = true;
					}

					callback->Release();
				}

				cp->Release();
			}

			cpc->Release();
		}

		return registered;
	}

	_Check_return_
	bool Kielbasa::UnregisterCallback(_In_ LPUNKNOWN rdpClient, DWORD cookie)
	{
		bool						unregistered = false;
		LPCONNECTIONPOINTCONTAINER	cpc;

		if (SUCCEEDED(rdpClient->QueryInterface(&cpc)))
		{
			LPCONNECTIONPOINT cp;

			if (SUCCEEDED(cpc->FindConnectionPoint(DIID_IMsTscAxEvents, &cp)))
			{
				if (SUCCEEDED(cp->Unadvise(cookie)))
				{
					unregistered = true;
				}

				cp->Release();
			}

			cpc->Release();
		}

		return unregistered;
	}

	_Check_return_
	bool Kielbasa::SetClientSite(_In_ LPUNKNOWN rdpClient)
	{
		bool						set = false;
		ATL::CComObject<ClientSite> *site;

		if (SUCCEEDED(ATL::CComObject<ClientSite>::CreateInstance(&site)))
		{
			LPOLEOBJECT oobj;
			site->AddRef();
			site->AttachEvents(this);

			if (SUCCEEDED(rdpClient->QueryInterface(&oobj)))
			{
				if (SUCCEEDED(oobj->SetClientSite(site)))
					set = true;
				oobj->Release();
			}

			site->Release();
		}

		return set;
	}
}
