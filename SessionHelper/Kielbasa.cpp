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

						::ShowWindow(hwnd, SW_SHOW);
						::UpdateWindow(hwnd);
						
						BSTR bstrServer = reinterpret_cast<BSTR>(Marshal::StringToBSTR(machineName).ToPointer());
						m_rdpClient->put_Server(bstrServer);
						::SysFreeString(bstrServer);

						IMsRdpClientNonScriptable5 *sc5;
						if (SUCCEEDED(m_rdpClient->QueryInterface(&sc5)))
						{
							sc5->put_AllowPromptingForCredentials(VARIANT_TRUE);
							sc5->Release();
						}

						
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
					}

					ownd->Release();
				}

				site->Release();
				oleobj->Release();
			}

			obj->Release();
		}
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
