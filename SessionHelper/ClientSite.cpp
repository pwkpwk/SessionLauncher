#include "stdafx.h"
#include "ClientSite.h"

ClientSite::ClientSite()
{
}

ClientSite::~ClientSite()
{
}

void ClientSite::FinalRelease()
{
}

STDMETHODIMP ClientSite::SaveObject()
{
	return S_OK;
}

STDMETHODIMP ClientSite::GetMoniker(DWORD dwAssign, DWORD dwWhichMoniker, __RPC__deref_out_opt IMoniker **ppmk)
{
	return E_NOTIMPL;
}

STDMETHODIMP ClientSite::GetContainer(__RPC__deref_out_opt IOleContainer **ppContainer)
{
	return E_NOINTERFACE;
}

STDMETHODIMP ClientSite::ShowObject()
{
	return S_OK;
}

STDMETHODIMP ClientSite::OnShowWindow(BOOL fShow)
{
	return S_OK;
}

STDMETHODIMP ClientSite::RequestNewObjectLayout()
{
	return E_NOTIMPL;
}
