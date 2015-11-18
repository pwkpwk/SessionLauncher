#include "stdafx.h"
#include "Kielbasa.h"
#include "SessionCallback.h"
#include "ClientSite.h"

namespace SessionHelper
{
	Kielbasa ^Kielbasa::Create(WindowInteropHelper ^windowHelper)
	{
		Kielbasa ^kielbasa = gcnew Kielbasa(windowHelper);

		if (!kielbasa->Initialize() || !kielbasa->CreateControl())
		{
			kielbasa->~Kielbasa();
			kielbasa = nullptr;
		}

		return kielbasa;
	}

	Kielbasa::Kielbasa(WindowInteropHelper ^windowHelper)
	:	m_clientAx(NULL),
		m_windowHelper(windowHelper),
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
			m_rdpClient->Release();
			m_rdpClient = nullptr;
		}

		::FreeLibrary(m_clientAx);
	}

	void Kielbasa::LaunchSession()
	{
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
