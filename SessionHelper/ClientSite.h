#pragma once

class ATL_NO_VTABLE ClientSite : public ATL::CComObjectRoot, public IOleClientSite, public IOleInPlaceSiteEx
{
private:
	HWND m_hwnd;

public:
	ClientSite();

	BEGIN_COM_MAP(ClientSite)
		COM_INTERFACE_ENTRY(IOleClientSite)
		COM_INTERFACE_ENTRY(IOleInPlaceSiteEx)
		COM_INTERFACE_ENTRY(IOleInPlaceSite)
		COM_INTERFACE_ENTRY(IOleWindow)
	END_COM_MAP()

	void FinalRelease();

protected:
	~ClientSite();

private:
	//
	// IOleClientSite
	//
	STDMETHODIMP SaveObject() override;
	STDMETHODIMP GetMoniker(DWORD dwAssign, DWORD dwWhichMoniker, __RPC__deref_out_opt IMoniker **ppmk) override;
	STDMETHODIMP GetContainer(__RPC__deref_out_opt IOleContainer **ppContainer) override;
	STDMETHODIMP ShowObject() override;
	STDMETHODIMP OnShowWindow(BOOL fShow) override;
	STDMETHODIMP RequestNewObjectLayout() override;
	//
	// IOleWindow (base of IOleInPlaceSite, base of IOleInPlaceSiteEx)
	//
	STDMETHODIMP GetWindow(__RPC__deref_out_opt HWND *phwnd) override;
	STDMETHODIMP ContextSensitiveHelp(BOOL fEnterMode) override;
	//
	// IOleInPlaceSite (base of IOleInPlaceSiteEx)
	//
	STDMETHODIMP CanInPlaceActivate() override;
	STDMETHODIMP OnInPlaceActivate() override;
	STDMETHODIMP OnUIActivate() override;
	STDMETHODIMP GetWindowContext(
		__RPC__deref_out_opt IOleInPlaceFrame **ppFrame,
		__RPC__deref_out_opt IOleInPlaceUIWindow **ppDoc,
		__RPC__out LPRECT lprcPosRect,
		__RPC__out LPRECT lprcClipRect,
		__RPC__inout LPOLEINPLACEFRAMEINFO lpFrameInfo) override;
	STDMETHODIMP Scroll(SIZE scrollExtant) override;
	STDMETHODIMP OnUIDeactivate(BOOL fUndoable) override;
	STDMETHODIMP OnInPlaceDeactivate() override;
	STDMETHODIMP DiscardUndoState() override;
	STDMETHODIMP DeactivateAndUndo() override;
	STDMETHODIMP OnPosRectChange(__RPC__in LPCRECT lprcPosRect) override;
	//
	// IOleInPlaceSiteEx
	//
	STDMETHODIMP OnInPlaceActivateEx(__RPC__out BOOL *pfNoRedraw, DWORD dwFlags) override;
	STDMETHODIMP OnInPlaceDeactivateEx(BOOL fNoRedraw) override;
	STDMETHODIMP RequestUIActivate() override;
};
