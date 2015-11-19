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
		if (3 != pDispParams->cArgs || VT_BOOL != V_VT(pDispParams->rgvarg) || VT_I4 != V_VT(pDispParams->rgvarg + 1) || VT_I4 != V_VT(pDispParams->rgvarg + 2))
			hr = E_UNEXPECTED;
		else
			OnRemoteWindowDisplayed(V_BOOL(pDispParams->rgvarg), V_I4(pDispParams->rgvarg + 1), V_I4(pDispParams->rgvarg + 2));
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
}

void SessionCallback::OnConnected()
{
}

void SessionCallback::OnDisconnecting()
{
}

void SessionCallback::OnDisconnected(LONG code)
{
}

void SessionCallback::OnLoginComplete()
{
}

void SessionCallback::OnRequestEnterFullScreen()
{
}

void SessionCallback::OnRequestLeaveFullScreen()
{
}

void SessionCallback::OnFatalError(LONG code)
{
}

void SessionCallback::OnWarning(LONG code)
{
}

void SessionCallback::OnRemoteDesktopSizeChange(LONG cx, LONG cy)
{
}

void SessionCallback::OnIdleTimeoutNotification()
{
}

void SessionCallback::OnRequestContainerMinimize()
{
}

bool SessionCallback::OnConfirmClose()
{
	return true;
}

void SessionCallback::OnServiceMessageReceived(BSTR message)
{
}

void SessionCallback::OnInternalDialogDisplayed()
{
}

void SessionCallback::OnInternalDialogDismissed()
{
}

void SessionCallback::OnRemoteProgramResult(BOOL isExecutable, LONG error, BSTR application)
{
}

void SessionCallback::OnRemoteProgramDisplayed(BOOL applicationDisplayed, LONG displayInformation)
{
}

void SessionCallback::OnRemoteWindowDisplayed(BOOL windowDisplayed, LONG hwnd, LONG windowInformation)
{
}

void SessionCallback::OnLogonError(LONG code)
{
}

void SessionCallback::OnFocusReleased(LONG direction)
{
}

void SessionCallback::OnUserNameAcquired(BSTR userName)
{
}

void SessionCallback::OnStatusInfo(LONG statusCode)
{
}

void SessionCallback::OnConnectionBarPullDown()
{
}

void SessionCallback::OnConnectionBarDevices()
{
}

void SessionCallback::OnAutoReconnecting()
{
}

void SessionCallback::OnAutoReconnected()
{
}
