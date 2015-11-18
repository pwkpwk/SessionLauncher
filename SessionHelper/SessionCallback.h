#pragma once
#include <mstsax_h.h>

class ATL_NO_VTABLE SessionCallback : public ATL::CComObjectRoot, public IMsTscAxEvents
{
public:
	SessionCallback();

	BEGIN_COM_MAP(SessionCallback)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(IMsTscAxEvents)
	END_COM_MAP()

private:
	STDMETHODIMP GetTypeInfoCount(__RPC__out UINT *pctinfo);
	STDMETHODIMP GetTypeInfo(UINT iTInfo, LCID lcid, __RPC__deref_out_opt ITypeInfo **ppTInfo);
	STDMETHODIMP GetIDsOfNames(__RPC__in REFIID riid, __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
		__RPC__in_range(0, 16384) UINT cNames, LCID lcid, __RPC__out_ecount_full(cNames) DISPID *rgDispId);
	STDMETHODIMP Invoke(_In_  DISPID dispIdMember, _In_  REFIID riid, _In_  LCID lcid,
		_In_  WORD wFlags, _In_  DISPPARAMS *pDispParams, _Out_opt_  VARIANT *pVarResult,
		_Out_opt_  EXCEPINFO *pExcepInfo, _Out_opt_  UINT *puArgErr);

private:
	void OnConnecting();
	void OnDisconnecting();
	void OnDisconnected(LONG code);
	void OnLoginComplete();
	void OnRequestEnterFullScreen();
	void OnRequestLeaveFullScreen();
	void OnFatalError(LONG code);
	void OnWarning(LONG code);
	void OnRemoteDesktopSizeChange(LONG cx, LONG cy);
	void OnIdleTimeoutNotification();
	void OnRequestContainerMinimize();
	bool OnConfirmClose();
	void OnServiceMessageReceived(BSTR message);
	void OnInternalDialogDisplayed();
	void OnInternalDialogDismissed();
	void OnRemoteProgramResult(BOOL isExecutable, LONG error, BSTR application);
	void OnRemoteProgramDisplayed(BOOL applicationDisplayed, LONG displayInformation);
	void OnRemoteWindowDisplayed(BOOL windowDisplayed, LONG hwnd, LONG windowInformation);
	void OnLogonError(LONG code);
	void OnFocusReleased(LONG direction);
	void OnUserNameAcquired(BSTR userName);
	void OnStatusInfo(LONG statusCode);
	void OnConnectionBarPullDown();
	void OnConnectionBarDevices();
	void OnAutoReconnecting();
	void OnAutoReconnected();
};
