#include "stdafx.h"
#include "SessionCallback.h"

SessionCallback::SessionCallback()
{
}

STDMETHODIMP SessionCallback::GetTypeInfoCount(__RPC__out UINT *pctinfo)
{
	HRESULT hr = S_OK;

	if (!pctinfo)
		hr = E_POINTER;
	else
		*pctinfo = 0;

	return hr;
}

STDMETHODIMP SessionCallback::GetTypeInfo(UINT iTInfo, LCID lcid, __RPC__deref_out_opt ITypeInfo **ppTInfo)
{
	return E_NOTIMPL;
}

STDMETHODIMP SessionCallback::GetIDsOfNames(__RPC__in REFIID riid, __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
	__RPC__in_range(0, 16384) UINT cNames, LCID lcid, __RPC__out_ecount_full(cNames) DISPID *rgDispId)
{
	return E_NOTIMPL;
}

STDMETHODIMP SessionCallback::Invoke(_In_  DISPID dispIdMember, _In_  REFIID riid, _In_  LCID lcid,
	_In_  WORD wFlags, _In_  DISPPARAMS *pDispParams, _Out_opt_  VARIANT *pVarResult,
	_Out_opt_  EXCEPINFO *pExcepInfo, _Out_opt_  UINT *puArgErr)
{
	HRESULT hr = S_OK;

	ATLTRACE("SessionCallback::Invoke(dispIdMember=%d)\n", dispIdMember);

	switch (dispIdMember)
	{
	case DISPID_CONNECTING:
		OnConnecting();
		break;

	case DISPID_CONNECTED:
		OnConnected();
		break;

	case DISPID_DISCONNECTED:
		if (1 != pDispParams->cArgs)
			hr = E_UNEXPECTED;
		else
			OnDisconnected(V_I4(pDispParams->rgvarg));
		break;

	case DISPID_LOGINCOMPLETE:
		OnLoginComplete();
		break;

	case DISPID_REQUESTGOFULLSCREEN:
		OnRequestEnterFullScreen();
		break;

	case DISPID_REQUESTLEAVEFULLSCREEN:
		OnRequestLeaveFullScreen();
		break;

	case DISPID_FATALERROR:
		if (1 != pDispParams->cArgs)
			hr = E_UNEXPECTED;
		else
			OnFatalError(V_I4(pDispParams->rgvarg));
		break;

	case DISPID_WARNING:
		if (1 != pDispParams->cArgs)
			hr = E_UNEXPECTED;
		else
			OnWarning(V_I4(pDispParams->rgvarg));
		break;

	case DISPID_REMOTEDESKTOPSIZECHANGE:
		if (2 != pDispParams->cArgs)
			hr = E_UNEXPECTED;
		else
			OnRemoteDesktopSizeChange(V_I4(pDispParams->rgvarg), V_I4(pDispParams->rgvarg+1));
		break;

	case DISPID_IDLETIMEOUTNOTIFICATION:
		OnIdleTimeoutNotification();
		break;

	case DISPID_REQUESTCONTAINERMINIMIZE:
		OnRequestContainerMinimize();
		break;

	case DISPID_CONFIRMCLOSE:
		if (1 != pDispParams->cArgs || (VT_BYREF | VT_BOOL) == V_VT(pDispParams->rgvarg))
			hr = E_UNEXPECTED;
		else
			*V_BOOLREF(pDispParams->rgvarg) = OnConfirmClose() ? VARIANT_TRUE : VARIANT_FALSE;
		break;

	case DISPID_SERVICEMESSAGERECEIVED:
		if (1 != pDispParams->cArgs || VT_BSTR != V_VT(pDispParams->rgvarg))
			hr = E_UNEXPECTED;
		else
			OnServiceMessageReceived(V_BSTR(pDispParams->rgvarg));
		break;

	case DISPID_INTERNALDIALOGDISPLAYED:
		OnInternalDialogDisplayed();
		break;

	case DISPID_INTERNALDIALOGDISMISSED:
		OnInternalDialogDismissed();
		break;

	case DISPID_ONREMOTEPROGRAMRESULT:
		if (3 != pDispParams->cArgs || VT_BOOL != V_VT(pDispParams->rgvarg) || VT_I4 != V_VT(pDispParams->rgvarg + 1) || VT_BSTR != V_VT(pDispParams->rgvarg + 2))
			hr = E_UNEXPECTED;
		else
			OnRemoteProgramResult(V_BOOL(pDispParams->rgvarg), V_I4(pDispParams->rgvarg + 1), V_BSTR(pDispParams->rgvarg + 2));
		break;

	case DISPID_ONREMOTEPROGRAMDISPLAYED:
		if (2 != pDispParams->cArgs || VT_BOOL != V_VT(pDispParams->rgvarg) || VT_I4 != V_VT(pDispParams->rgvarg + 1))
			hr = E_UNEXPECTED;
		else
			OnRemoteProgramDisplayed(V_BOOL(pDispParams->rgvarg), V_I4(pDispParams->rgvarg + 1));
		break;

	case DISPID_ONREMOTEWINDOWDISPLAYED:
		if (3 != pDispParams->cArgs || VT_BOOL != V_VT(pDispParams->rgvarg) || VT_UI4 != V_VT(pDispParams->rgvarg + 1) || VT_UI4 != V_VT(pDispParams->rgvarg + 2))
			hr = E_UNEXPECTED;
		else
			OnRemoteWindowDisplayed(V_BOOL(pDispParams->rgvarg), V_UI4(pDispParams->rgvarg + 1), V_UI4(pDispParams->rgvarg + 2));
		break;

	case DISPID_LOGONERROR:
		if (1 != pDispParams->cArgs)
			hr = E_UNEXPECTED;
		else
			OnLogonError(V_I4(pDispParams->rgvarg));
		break;

	case DISPID_FOCUSRELEASED:
		if (1 != pDispParams->cArgs)
			hr = E_UNEXPECTED;
		else
			OnFocusReleased(V_I4(pDispParams->rgvarg));
		break;

	case DISPID_USERNAMEACQUIRED:
		if (1 != pDispParams->cArgs || VT_BSTR != V_VT(pDispParams->rgvarg))
			hr = E_UNEXPECTED;
		else
			OnUserNameAcquired(V_BSTR(pDispParams->rgvarg));
		break;

	case DISPID_ONSTATUSINFO:
		if(1 != pDispParams->cArgs)
			hr = E_UNEXPECTED;
		else
			OnStatusInfo(V_I4(pDispParams->rgvarg));
		break;

	case DISPID_CONNECTIONBARPULLDOWN:
		OnConnectionBarPullDown();
		break;

	case DISPID_CONNECTIONBARDEVICES:
		OnConnectionBarDevices();
		break;

	case DISPID_AUTORECONNECTING:
		OnAutoReconnecting();
		break;

	case DISPID_AUTORECONNECTED:
		OnAutoReconnected();
		break;

	case DISPID_ONNETWORKSTATUSCHANGED:
		if(3 != pDispParams->cArgs)
			hr = E_UNEXPECTED;
		else
			OnNetworkStatusChanged(V_I4(pDispParams->rgvarg), V_I4(pDispParams->rgvarg+1), V_UI4(pDispParams->rgvarg+2));
		break;

	default:
		//
		// Return E_NOTIMPL for all unsupported dispatch members
		//
		hr = E_NOTIMPL;
		break;
	}

	return hr;
}

void SessionCallback::OnConnecting()
{
	ATLTRACE("SessionCallback::OnConnecting()\n");
}

void SessionCallback::OnConnected()
{
	ATLTRACE("SessionCallback::OnConnected()\n");
}

void SessionCallback::OnDisconnecting()
{
	ATLTRACE("SessionCallback::OnDisconnecting()\n");
}

void SessionCallback::OnDisconnected(LONG code)
{
	ATLTRACE("SessionCallback::OnDisconnected()\n");
}

void SessionCallback::OnLoginComplete()
{
	ATLTRACE("SessionCallback::OnLoginComplete()\n");
}

void SessionCallback::OnRequestEnterFullScreen()
{
	ATLTRACE("SessionCallback::OnRequestEnterFullScreen()\n");
}

void SessionCallback::OnRequestLeaveFullScreen()
{
	ATLTRACE("SessionCallback::OnRequestLeaveFullScreen()\n");
}

void SessionCallback::OnFatalError(LONG code)
{
	ATLTRACE("SessionCallback::OnFatalError(code=0x%08X (%ld))\n", code, code);
}

void SessionCallback::OnWarning(LONG code)
{
	ATLTRACE("SessionCallback::OnWarning(code=0x%08X (%ld))\n", code, code);
}

void SessionCallback::OnRemoteDesktopSizeChange(LONG cx, LONG cy)
{
	ATLTRACE("SessionCallback::OnRemoteDesktopSizeChange(cx=%ld, cy=%ld)\n", cx, cy);
}

void SessionCallback::OnIdleTimeoutNotification()
{
	ATLTRACE("SessionCallback::OnIdleTimeoutNotification()\n");
}

void SessionCallback::OnRequestContainerMinimize()
{
	ATLTRACE("SessionCallback::OnRequestContainerMinimize()\n");
}

bool SessionCallback::OnConfirmClose()
{
	ATLTRACE("SessionCallback::OnConfirmClose()\n");
	return true;
}

void SessionCallback::OnServiceMessageReceived(BSTR message)
{
	ATLTRACE("SessionCallback::OnServiceMessageReceived()\n");
}

void SessionCallback::OnInternalDialogDisplayed()
{
	ATLTRACE("SessionCallback::OnInternalDialogDisplayed()\n");
}

void SessionCallback::OnInternalDialogDismissed()
{
	ATLTRACE("SessionCallback::OnInternalDialogDismissed()\n");
}

void SessionCallback::OnRemoteProgramResult(BOOL isExecutable, LONG error, BSTR application)
{
	ATLTRACE("SessionCallback::OnRemoteProgramResult(isExecutable=%d, error=0x%08X (%ld), application=\"%ls\")\n", isExecutable, error, error, application);
}

void SessionCallback::OnRemoteProgramDisplayed(BOOL applicationDisplayed, LONG displayInformation)
{
	ATLTRACE("SessionCallback::OnRemoteProgramDisplayed(applicationDisplayed=%d, displayInformation=%ld)\n", applicationDisplayed, displayInformation);
}

void SessionCallback::OnRemoteWindowDisplayed(BOOL windowDisplayed, ULONG hwnd, ULONG windowInformation)
{
	ATLTRACE("SessionCallback::OnRemoteWindowDisplayed(windowDisplayed=%d, hwnd=0x%08lX, windowInformation=%lu)\n", windowDisplayed, hwnd, windowInformation);
}

void SessionCallback::OnLogonError(LONG code)
{
	ATLTRACE("SessionCallback::OnLogonError()\n");
}

void SessionCallback::OnFocusReleased(LONG direction)
{
	ATLTRACE("SessionCallback::OnFocusReleased()\n");
}

void SessionCallback::OnUserNameAcquired(BSTR userName)
{
	ATLTRACE("SessionCallback::OnUserNameAcquired(userName=%ls)\n", userName);
}

void SessionCallback::OnStatusInfo(LONG statusCode)
{
	ATLTRACE("SessionCallback::OnStatusInfo(statusCode=%ld)\n", statusCode);
}

void SessionCallback::OnConnectionBarPullDown()
{
	ATLTRACE("SessionCallback::OnConnectionBarPullDown()\n");
}

void SessionCallback::OnConnectionBarDevices()
{
	ATLTRACE("SessionCallback::OnConnectionBarDevices()\n");
}

void SessionCallback::OnAutoReconnecting()
{
	ATLTRACE("SessionCallback::OnAutoReconnecting()\n");
}

void SessionCallback::OnAutoReconnected()
{
	ATLTRACE("SessionCallback::OnAutoReconnected()\n");
}

void SessionCallback::OnNetworkStatusChanged(INT32 n1, INT32 n2, UINT32 n3)
{
	ATLTRACE("SessionCallback::OnNetworkStatusChanged(%d, %d, %u)\n", n1, n2, n3);
}
