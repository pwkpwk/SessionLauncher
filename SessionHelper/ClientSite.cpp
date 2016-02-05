#include "stdafx.h"
#include "ControlHostWindow.h"
#include "ClientSite.h"

ClientSite::ClientSite()
:	m_hwnd(NULL)
{
}

ClientSite::~ClientSite()
{
}

void ClientSite::FinalRelease()
{
	if (m_hwnd)
	{
		::DestroyWindow(m_hwnd);
		m_hwnd = NULL;
	}
}

//
// IOleClientSite
//

STDMETHODIMP ClientSite::SaveObject()
{
	ATLTRACE("ClientSite::SaveObject()\n");
	return S_OK;
}

STDMETHODIMP ClientSite::GetMoniker(DWORD dwAssign, DWORD dwWhichMoniker, __RPC__deref_out_opt IMoniker **ppmk)
{
	ATLTRACE("ClientSite::GetMoniker()\n");
	return E_NOTIMPL;
}

STDMETHODIMP ClientSite::GetContainer(__RPC__deref_out_opt IOleContainer **ppContainer)
{
	ATLTRACE("ClientSite::GetContainer()\n");
	return E_NOINTERFACE;
}

STDMETHODIMP ClientSite::ShowObject()
{
	ATLTRACE("ClientSite::ShowObject()\n");
	return S_OK;
}

STDMETHODIMP ClientSite::OnShowWindow(BOOL fShow)
{
	ATLTRACE("ClientSite::OnShowWindow(fShow=%d)\n", fShow);
	return S_OK;
}

STDMETHODIMP ClientSite::RequestNewObjectLayout()
{
	ATLTRACE("ClientSite::RequestNewObjectLayout()\n");
	return E_NOTIMPL;
}

//
// IOleWindow
//

STDMETHODIMP ClientSite::GetWindow(__RPC__deref_out_opt HWND *phwnd)
{
	HRESULT hr = S_OK;

	ATLTRACE("ClientSite::GetWindow()\n");

	if (!phwnd)
	{
		hr = E_POINTER;
	}
	else
	{
		if (!m_hwnd)
		{
			m_hwnd = ControlHostWindow::Create( m_events );

			if (!m_hwnd)
			{
				hr = HRESULT_FROM_WIN32(::GetLastError());
			}
		}

		if (m_hwnd)
		{
			*phwnd = m_hwnd;
		}
	}

	return hr;
}

STDMETHODIMP ClientSite::ContextSensitiveHelp(BOOL fEnterMode)
{
	ATLTRACE("ClientSite::ContextSensitiveHelp()\n");
	return S_OK;
}

//
// IOleInPlaceSite
//

STDMETHODIMP ClientSite::CanInPlaceActivate()
{
	ATLTRACE("ClientSite::CanInPlaceActivate()\n");
	return S_OK;
}

STDMETHODIMP ClientSite::OnInPlaceActivate()
{
	ATLTRACE("ClientSite::OnInPlaceActivate()\n");
	return S_OK;
}

STDMETHODIMP ClientSite::OnUIActivate()
{
	ATLTRACE("ClientSite::OnUIActivate()\n");
	return S_OK;
}

STDMETHODIMP ClientSite::GetWindowContext(
	__RPC__deref_out_opt IOleInPlaceFrame **ppFrame,
	__RPC__deref_out_opt IOleInPlaceUIWindow **ppDoc,
	__RPC__out LPRECT lprcPosRect,
	__RPC__out LPRECT lprcClipRect,
	__RPC__inout LPOLEINPLACEFRAMEINFO lpFrameInfo)
{
	HRESULT	hr = S_OK;

	ATLTRACE("ClientSite::GetWindowContext\n");

	if (!ppFrame || !ppDoc || !lprcPosRect || !lprcClipRect)
	{
		hr = E_POINTER;
	}
	else
	{
		::GetClientRect(m_hwnd, lprcPosRect);
		*lprcClipRect = *lprcPosRect;
		*ppFrame = nullptr;
		*ppDoc = nullptr;
	}

	return hr;
}

STDMETHODIMP ClientSite::Scroll(SIZE scrollExtant)
{
	ATLTRACE("ClientSite::Scroll(%d, %d)\n", scrollExtant.cx, scrollExtant.cy);
	return S_OK;
}

STDMETHODIMP ClientSite::OnUIDeactivate(BOOL fUndoable)
{
	ATLTRACE("ClientSite::OnUIDeactivate(fUndoable=%d)\n", fUndoable);
	return S_OK;
}

STDMETHODIMP ClientSite::OnInPlaceDeactivate()
{
	ATLTRACE("ClientSite::OnInPlaceDeactivate()\n");
	return S_OK;
}

STDMETHODIMP ClientSite::DiscardUndoState()
{
	ATLTRACE("ClientSite::DiscardUndoState()\n");
	return S_OK;
}

STDMETHODIMP ClientSite::DeactivateAndUndo()
{
	ATLTRACE("ClientSite::DeactivateAndUndo()\n");
	return S_OK;
}

STDMETHODIMP ClientSite::OnPosRectChange(__RPC__in LPCRECT lprcPosRect)
{
	ATLTRACE("ClientSite::OnPosRectChange()\n");
	return S_OK;
}

//
// IOleInPlaceSiteEx
//

STDMETHODIMP ClientSite::OnInPlaceActivateEx(__RPC__out BOOL *pfNoRedraw, DWORD dwFlags)
{
	HRESULT hr = S_OK;

	ATLTRACE("ClientSite::OnInPlaceActivateEx()\n");

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
	ATLTRACE("ClientSite::OnInPlaceDeactivateEx()\n");
	return S_OK;
}

STDMETHODIMP ClientSite::RequestUIActivate()
{
	ATLTRACE("ClientSite::RequestUIActivate()\n");
	return S_OK;
}
