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
		m_callbackCookie(0)
	{
	}

	Kielbasa::~Kielbasa()
	{
		if (m_rdpClient)
		{
			if (UnregisterCallback(m_rdpClient, m_callbackCookie))
				m_callbackCookie = 0;

			LPOLEOBJECT oobj;

			if (SUCCEEDED(m_rdpClient->QueryInterface(&oobj)))
			{
				oobj->Close(OLECLOSE_NOSAVE);
				oobj->Release();
			}

			m_rdpClient->Release();
			m_rdpClient = nullptr;
		}

		::FreeLibrary(m_clientAx);
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

						if (SUCCEEDED(m_rdpClient->QueryInterface(&client5)))
						{
							CComBSTR userName(OLESTR("pakarpen@microsoft.com"));
							CComBSTR password(OLESTR("<password!>"));
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
							client5->put_ClearTextPassword(password);

							IMsRdpClient9 *client9;
							ITSRemoteProgram2 *program2 = nullptr;

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

								if (S_OK == client9->get_RemoteProgram2(&program2))
								{
									program2->put_RemoteProgramMode(VARIANT_TRUE);
									program2->put_RemoteApplicationName(appName);
									program2->put_RemoteApplicationProgram(program);
									program2->put_RemoteApplicationArgs(args);
#if 0
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

								IMsRdpClientTransportSettings4 *transport4;

								if (S_OK == client5->QueryInterface(&transport4))
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
									transport4->put_GatewayPassword(gatewayPassword);
									transport4->put_GatewayBrokeringType(1);

									transport4->Release();
								}

								IMsRdpClientAdvancedSettings8 *advset8;

								if (S_OK == client9->get_AdvancedSettings9(&advset8))
								{
									CComBSTR lbInfo("MTB://lbinfo?param1=selfhostlive&param2=754606d9-5159-4514-8b2d-5c5a10610285");
									lbInfo.Append(OLESTR("\r\n"));
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

									advset8->Release();
								}

								IMsRdpExtendedSettings *extset;

								if (S_OK == m_rdpClient->QueryInterface(&extset))
								{
									CComVariant var(OLESTR(""));

									extset->put_Property(UTREG_UI_FEDAUTH_TOKEN, &var);
									extset->Release();
								}

								client9->Release();
							}

							client5->Release();
						}

#if 0
						BSTR bstrServer = reinterpret_cast<BSTR>(Marshal::StringToBSTR(machineName).ToPointer());
						m_rdpClient->put_Server(bstrServer);
						::SysFreeString(bstrServer);
						
						IMsTscAdvancedSettings *as;
						if (SUCCEEDED(m_rdpClient->get_AdvancedSettings(&as)))
						{
							IMsRdpClientAdvancedSettings4 *as4;

							if (SUCCEEDED(as->QueryInterface(&as4)))
							{
								as4->put_AuthenticationLevel(2);
								as4->Release();
							}
							as->Release();
						}

						m_rdpClient->Connect();
#endif
					}

					ownd->Release();
				}

				site->Release();
				oleobj->Release();
			}

			obj->Release();
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
		m_clientAx = ::LoadLibrary(TEXT("rdclientax.dll"));
		return NULL != m_clientAx;
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
