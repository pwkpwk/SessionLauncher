#pragma once

class ATL_NO_VTABLE ClientSite : public ATL::CComObjectRoot, public IOleClientSite
{
public:
	ClientSite();

	BEGIN_COM_MAP(ClientSite)
		COM_INTERFACE_ENTRY(IOleClientSite)
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
};
