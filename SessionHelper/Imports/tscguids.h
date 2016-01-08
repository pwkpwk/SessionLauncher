//
// Copyright (c) 1998-2002  Microsoft Corporation. All Rights Reserved.
//
// Module Name:
//
//      tscguids.h
//
// Abstract:
//
//      Internal GUIDS
//
//@@BEGIN_MSINTERNAL
//
// Author: Nadim Abdo
//
// Revision History:
//
//      8/17/2002 Created - NadimA
//
//@@END_MSINTERNAL
// 

#ifndef __TSC_GUIDS_H__
#define __TSC_GUIDS_H__

//
// Internal GUID range
// Starting from   {7272b107-c627-40dc-bb13-57da13c395f0}
// Ending at       {7272d817-c627-40dc-bb13-57da13c395f0}
//

//
// Bring in platform guids
//
#pragma warning (push)
#pragma warning (disable:4305)
#pragma warning (disable:4309)

#define DEFINE_TSC_GUID(guidname, id)   \
DEFINE_GUID(guidname, 0x7272b107 + id, 0xc627, 0x40dc, 0xbb, 0x13, 0x57, 0xda, 0x13, 0xc3, 0x95, 0xf0);

///////////////////////////////////////////////////////////////////////////////
//
// Start PLUGUID marker
//
DEFINE_TSC_GUID(PLUGUID_TSC_START_RANGE, 0);

//
// TCP Name Resolver
//
DEFINE_TSC_GUID(PLUGUID_TCP_Name_Resolver, 1);

//
// TCP Reverse Connection Name Resolver
//
DEFINE_TSC_GUID(PLUGUID_TCP_Reverse_Name_Resolver, 2);

//
// TCP Transport
//
DEFINE_TSC_GUID(PLUGUID_TCP_Transport, 3);

//
// RDPDR plugin
//
DEFINE_TSC_GUID(PLUGUID_RDPDR, 4);

//
// ITSVirtualChannel plugin IID
//
DEFINE_TSC_GUID(IID_ITSVirtualChannelPlugin, 5);

//
// ITSNameResolver plugin IID
//
DEFINE_TSC_GUID(IID_ITSNameResolver, 6);

//
// ITSTransport plugin IID
//
DEFINE_TSC_GUID(IID_ITSTransport, 7);

//
// Client Plugin interface
//
DEFINE_TSC_GUID(IID_ITSClientPlugin, 8);

//
// Sample Client Plugin
//
DEFINE_TSC_GUID(PLGUID_PLUGIN_SAMPLE, 9);

//
// Null client plugin
//
DEFINE_TSC_GUID(PLGUID_PLUGIN_NULL, 10);

//
// ITSWin32Transport plugin IID
//
DEFINE_TSC_GUID(IID_ITSWin32Transport, 11);

//
// Platform Specific Core API root interface
//
DEFINE_TSC_GUID(IID_ITSWin32CoreApi, 12);

//
// Core API events interface
//
DEFINE_TSC_GUID(IID_ITSCoreApiNotifySink, 13);

//
// Core API root interface
//
DEFINE_TSC_GUID(IID_ITSCoreApi, 14);

//
// Scriptable VC layer plugin
//
DEFINE_TSC_GUID(PLGUID_SCRIPT_VC_API, 15);

//
// Multimedia AV (MediaFoundation Base) Plugin
//
DEFINE_TSC_GUID(PLUGUID_MEDIA_AUDIOVIDEO, 16);

//
// Multimedia plugin host GUID
//
DEFINE_TSC_GUID(IID_ITSMultimediaPluginHost, 17);

#ifdef ENABLE_LIE
//
// Lie Plugin
//
DEFINE_TSC_GUID(PLGUID_PLUGIN_LIE, 18);
#endif // ENABLE_LIE

//
// ITSInstance interface
//
DEFINE_TSC_GUID(IID_ITSInstance, 19);

//
// ITSTransportEventsNotifySink interface
//
DEFINE_TSC_GUID(IID_ITSTransportEventsNotifySink, 20);

//
// PROXY Name Resolver
//
DEFINE_TSC_GUID(PLUGUID_PROXY_Name_Resolver, 21);

//
// PROXY Transport
//
DEFINE_TSC_GUID(PLUGUID_HTTP_PROXY_Transport, 22);

//
// ITSCapabilities interface
//
DEFINE_TSC_GUID(IID_ITSCapabilities, 23);

//
// ITSConnectionStack interface
//
DEFINE_TSC_GUID(IID_ITSConnectionStack, 25);

//
// ITSProtocolHandler interface
//
DEFINE_TSC_GUID(IID_ITSProtocolHandler, 26);

//
// ITSNetBuffer interface
//
DEFINE_TSC_GUID(IID_ITSNetBuffer, 27);

//
// ITSClientPlatformInstance interface
//
DEFINE_TSC_GUID(IID_ITSClientPlatformInstance, 28);

DEFINE_TSC_GUID(IID_ITSVirtualChannel, 29);
DEFINE_TSC_GUID(IID_ITSVirtualChannelEx, 30);

//
// Clipboard plugin GUIDS
//
DEFINE_TSC_GUID(PLGUID_CLIPBOARD, 31);
DEFINE_TSC_GUID(IID_ITSClipPlugin, 32);

//
// Drag and drop plugin GUIDS
//
DEFINE_TSC_GUID(PLGUID_DRAGDROP, 33);
DEFINE_TSC_GUID(IID_ITSDragDropPlugin, 34);

//
// Drive Redirection
//
DEFINE_TSC_GUID(IID_ITSDriveCollection, 35);

//
// Device Redirection Config
//
DEFINE_TSC_GUID(IID_IRdpDeviceRedirectionConfig, 36);

//
// MSCOMVC plugin
//
DEFINE_TSC_GUID(PLGUID_PLUGIN_MSCOMVC, 40);
DEFINE_TSC_GUID(IID_ITSMsComVcPlugin, 41);

//
// CompDesk plugin
//
#ifdef ENABLE_COMPDESK
DEFINE_TSC_GUID(PLGUID_PLUGIN_COMPDESK, 42);
#endif // ENABLE_COMPDESK

//
// ITscAuthInfo interface
//
DEFINE_TSC_GUID(IID_ITscAuthInfo, 43);

//
// ITSCoreObject interface
//
DEFINE_TSC_GUID(IID_ITSCoreObject, 44);

//
//  PNPRDR plugin
//
DEFINE_TSC_GUID( PLUGUID_PNPRDR, 45 );

//
// Rdp Multi Transport Resolver
//
DEFINE_TSC_GUID(PLUGUID_RdpMT_Name_Resolver, 46);

//
// Rdp Multi Transport
//
DEFINE_TSC_GUID(PLUGUID_RdpMT_Transport, 47);

//
// Core API internal interface
//
DEFINE_TSC_GUID(IID_ITSCoreApiInternal, 48);
DEFINE_TSC_GUID(IID_ITSCLX, 49);

//
// Core Virtual Channel API callback
//
DEFINE_TSC_GUID(IID_ITSCoreVirtualChannel, 50);

//
// Core API server addresses property interface
//
DEFINE_TSC_GUID(IID_ITSTransportAddresses, 55);

//
// Windowing plugin
//
#ifdef ENABLE_WND
DEFINE_TSC_GUID(PLGUID_PLUGIN_WND, 100);
DEFINE_TSC_GUID(IID_ITSWindowInformation, 102);
DEFINE_TSC_GUID(IID_ITSShellNotifyInformation, 103);
DEFINE_TSC_GUID(IID_ITSWndBase, 104);
DEFINE_TSC_GUID(IID_ITSZOrder, 105);
DEFINE_TSC_GUID(IID_ITSWndPlugin, 106);
DEFINE_TSC_GUID(IID_ITSEnumWndBase, 107);
#endif // ENABLE_WND

#ifdef ENABLE_RAIL
//
// RAIL Plugin
//
DEFINE_TSC_GUID(PLGUID_PLUGIN_RAIL, 120);
DEFINE_TSC_GUID(IID_ITSRailPlugin, 121);
DEFINE_TSC_GUID(IID_ITSRailApp, 122);
DEFINE_TSC_GUID(IID_ITSRailCore, 123);
DEFINE_TSC_GUID(IID_ITSRailVC, 124);
DEFINE_TSC_GUID(IID_IRemoteAppCoreInternal, 215);
DEFINE_TSC_GUID(IID_IRdpWinLanguageEvents, 400);
#endif // ENABLE_RAIL

//
// PAL interfaces
//
DEFINE_TSC_GUID(IID_ITSGraphics, 125);
DEFINE_TSC_GUID(IID_ITSGraphicsSurface, 126);
DEFINE_TSC_GUID(IID_ITSGraphicsBitmap, 127);
DEFINE_TSC_GUID(IID_ITSGraphicsBrush, 128);
DEFINE_TSC_GUID(IID_ITSGraphicsPen, 129);
DEFINE_TSC_GUID(IID_ITSGraphicsPalette, 130);

DEFINE_TSC_GUID(IID_ITSGraphicsEx, 131);
DEFINE_TSC_GUID(IID_ITSGraphicsSurfaceEx, 132);

DEFINE_TSC_GUID(IID_ITSWin32Graphics, 133);
DEFINE_TSC_GUID(IID_ITSWin32GraphicsSurfacePrimary, 134);
DEFINE_TSC_GUID(IID_ITSWin32GraphicsSurface, 135);
DEFINE_TSC_GUID(IID_ITSWin32GraphicsBitmap, 136);
DEFINE_TSC_GUID(IID_ITSWin32GraphicsBrush, 137);
DEFINE_TSC_GUID(IID_ITSWin32GraphicsPen, 138);
DEFINE_TSC_GUID(IID_ITSWin32GraphicsPalette, 139);

DEFINE_TSC_GUID(IID_ITSVirtualChannelPluginLoader, 140);
DEFINE_TSC_GUID(IID_ITSWin32VirtualChannelPluginLoader, 141);

DEFINE_TSC_GUID(IID_ITSTransportStack, 142);
DEFINE_TSC_GUID(IID_ITSTransportStackFactory, 143);

DEFINE_TSC_GUID(IID_ITSInput, 145);
DEFINE_TSC_GUID(IID_ITSWin32Input, 146);
DEFINE_TSC_GUID(IID_ITSInputMouseKeyboardSink, 147);

DEFINE_TSC_GUID(IID_ITSWin32GraphicsRegion, 148);

DEFINE_TSC_GUID(IID_ITSCoreGraphicsStack, 149);

//
// IMstscAxInternal - internal AX interface
//
DEFINE_TSC_GUID(IID_IMstscAxInternal, 160);

//
// This interface exposes methods used in "SLN Complete" notification 
// processing by the subscriber.
//
DEFINE_TSC_GUID(IID_ISecLayerNegCompleteResult, 161);

//
// This interface is used to issue "SLN Complete" notification.
//
DEFINE_TSC_GUID(IID_ISecLayerNegCompleteEvent, 162);

//
// This interface exposes methods used in Service Message Received 
// notification processing by the subscriber.
// 
DEFINE_TSC_GUID(IID_IAAMsgOpEventResult, 163);

//
// This interface is used to issue Service Message Received notification.
// 
DEFINE_TSC_GUID(IID_IAAMsgOpEvent, 164);

//
// ITsWkspInternal - internal AX interface for workspaces
//
DEFINE_TSC_GUID(IID_ITsWkspInternal, 165);

//
// Surface Manager plugin
//
#ifdef ENABLE_SFM
DEFINE_TSC_GUID(PLGUID_PLUGIN_SFM, 168);
#endif // ENABLE_SFM

//
// CaGfx plugin
//
DEFINE_TSC_GUID(PLGUID_PLUGIN_CAGFX, 169);

//
// Graphics presenter interface
// 
DEFINE_TSC_GUID(IID_ITscGraphicsPresenter, 171);
DEFINE_TSC_GUID(IID_ITscGraphicsController, 172);

DEFINE_TSC_GUID(PLUGUID_EXT_Stream_Resolver, 200);
DEFINE_TSC_GUID(PLUGUID_EXT_Stream_Transport, 201);

//
// Multitransport client interfaces
//
DEFINE_TSC_GUID(IID_IRdpClientMTStackMgr, 204);
DEFINE_TSC_GUID(IID_IRdpClientMTStackMgrCallback, 205);
DEFINE_TSC_GUID(IID_IRdpClientMTStack, 206);
DEFINE_TSC_GUID(IID_IRdpMultiTransportQuery, 207);

//
//
// UDP PROXY Name Resolver
//
DEFINE_TSC_GUID(PLUGUID_UDP_PROXY_Name_Resolver, 208);

//
// UDP PROXY Transport
//
DEFINE_TSC_GUID(PLUGUID_UDP_PROXY_Transport, 209);

//
// MIL Win7 plugins
//
#ifdef ENABLE_COMPDESK
DEFINE_TSC_GUID(PLGUID_PLUGIN_COMPDESK_WIN7, 210);
#endif // ENABLE_COMPDESK

#ifdef ENABLE_SFM
DEFINE_TSC_GUID(PLGUID_PLUGIN_SFM_WIN7, 211);
#endif // ENABLE_SFM

//
// Client Utils Interface
//
DEFINE_TSC_GUID(IID_RdpInterfaceClientUtils, 212);

//
// Input and Graphics adaptors
//
DEFINE_TSC_GUID(IID_ITSInputAdaptor, 213);
DEFINE_TSC_GUID(IID_ITSGraphicsAdaptor, 214);

DEFINE_TSC_GUID(IID_ITsRdpSignature, 215);

//
// RDPDR plugin
//
DEFINE_TSC_GUID(PLUGUID_SNDVC, 216);


///////////////////////////////////////////////////////////////////////////////
// End PLUGUID marker
//
DEFINE_TSC_GUID(PLUGUID_TSC_END_RANGE, 0xFFFF);
#pragma warning (pop)

#endif //__TSC_GUIDS_H__

