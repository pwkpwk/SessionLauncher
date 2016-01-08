//
// Copyright (c) 1998-2005  Microsoft Corporation. All Rights Reserved.
//
// Module Name:
//
//      tscwkspinternal.h
//
// Abstract:
//
//      Private internal use interface for MstscaAx
//
// Author: alhen
//
// Revision History:
//
//      01/25/2008 added workspace extension - alhen
//

#ifndef _TSCWKSPINTERNAL_H_
#define _TSCWKSPINTERNAL_H_

///////////////////////////////////////////////////////////////////////////////
//
// IMstscAxInternal: 
//

class ITsWkspInternal: public IUnknown
{

public:    
    STDMETHOD(InitWorkspaceExtension)(
         BOOL isWebHosted,
         __in LPCTSTR workspaceId,
         __in LPCTSTR logonUsername,
         __in_bcount_opt(cbPublisherThumbPrint) PBYTE pbPublisherThumbPrint,
         DWORD cbPublisherThumbPrint,
         BOOL fUseCredMan) PURE;

    STDMETHOD(set_SupportsReconnect)(
         BOOL fEnableWorkspaceReconnect) PURE;
};


#endif // _TSCWKSPINTERNAL_H_