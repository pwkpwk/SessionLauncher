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

//
// IOleClientSite
//

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

//
// IOleWindow
//

STDMETHODIMP ClientSite::GetWindow(__RPC__deref_out_opt HWND *phwnd)
{
	return E_NOTIMPL;
}

STDMETHODIMP ClientSite::ContextSensitiveHelp(BOOL fEnterMode)
{
	return S_OK;
}

//
// IOleInPlaceSite
//

STDMETHODIMP ClientSite::CanInPlaceActivate()
{
	return S_OK;
}

STDMETHODIMP ClientSite::OnInPlaceActivate()
{
	return S_OK;
}

STDMETHODIMP ClientSite::OnUIActivate()
{
	return S_OK;
}

STDMETHODIMP ClientSite::GetWindowContext(
	__RPC__deref_out_opt IOleInPlaceFrame **ppFrame,
	__RPC__deref_out_opt IOleInPlaceUIWindow **ppDoc,
	__RPC__out LPRECT lprcPosRect,
	__RPC__out LPRECT lprcClipRect,
	__RPC__inout LPOLEINPLACEFRAMEINFO lpFrameInfo)
{
	return E_NOTIMPL;
}

STDMETHODIMP ClientSite::Scroll(SIZE scrollExtant)
{
	return S_OK;
}

STDMETHODIMP ClientSite::OnUIDeactivate(BOOL fUndoable)
{
	return S_OK;
}

STDMETHODIMP ClientSite::OnInPlaceDeactivate()
{
	return S_OK;
}

STDMETHODIMP ClientSite::DiscardUndoState()
{
	return S_OK;
}

STDMETHODIMP ClientSite::DeactivateAndUndo()
{
	return S_OK;
}

STDMETHODIMP ClientSite::OnPosRectChange(__RPC__in LPCRECT lprcPosRect)
{
	return S_OK;
}

//
// IOleInPlaceSiteEx
//

STDMETHODIMP ClientSite::OnInPlaceActivateEx(__RPC__out BOOL *pfNoRedraw, DWORD dwFlags)
{
	HRESULT hr = S_OK;

	if (!pfNoRedraw)
	{
		hr = E_POINTER;
	}
	else
	{
		*pfNoRedraw = TRUE;
	}

	return hr;
}

STDMETHODIMP ClientSite::OnInPlaceDeactivateEx(BOOL fNoRedraw)
{
	return S_OK;
}

STDMETHODIMP ClientSite::RequestUIActivate()
{
	return S_OK;
}
