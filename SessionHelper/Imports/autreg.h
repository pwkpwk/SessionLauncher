//
// Copyright (c) 1997-2003  Microsoft Corporation. All Rights Reserved.
//
// Module Name:
//
//      autreg.h
//
// Abstract:
//
//      Registry and RDP file constants and strings
//
// Note:
//
//      BE VERY CAREFUL ABOUT CHANGING ANY OF THESE NAMES.
//      They might be used to refer to legacy registry entries
//      that cannot (obviously) change.
//

#ifndef _H_AUTREG
#define _H_AUTREG

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif // _MSC_VER >= 1020

#include "tsperf.h"

#define UTREG_SECTION _T("")
#define TSC_SETTINGS_REG_ROOT TEXT("Software\\Microsoft\\Terminal Server Client\\")

//
// Client group policy settings.
//
#define TSC_POLICY_KEY _T("Software\\Policies\\Microsoft\\Windows NT\\Terminal Services\\")
#define TSC_CLIENT_POLICY_KEY _T("Software\\Policies\\Microsoft\\Windows NT\\Terminal Services\\Client")
#define TSC_CRED_DELEGATION_POLICY_KEY _T("Software\\Policies\\Microsoft\\Windows\\CredentialsDelegation")
#define TSC_POLICY_DISABLE_PASSWORD_SAVING _T("DisablePasswordSaving")
#define TSC_POLICY_DISABLE_ACTIVEX_CLIENT_LAUNCH  _T("DisableClientLaunchingFromActiveXControl")
#define TSC_POLICY_PROMPT_FOR_CREDS_ON_CLIENT     _T("PromptForCredsOnClient")
#define TSC_POLICY_ENFORCE_RESTRICTED_ADMIN_MODE     _T("RestrictedRemoteAdministration")

// GP settings for RDP file signing
//
#define TSC_POLICY_ALLOW_UNSIGNED_FILES    _T("AllowUnsignedFiles")
#define TSC_POLICY_ALLOW_UNSIGNED_FILES_DFLT  1

#define TSC_POLICY_ALLOW_SIGNED_FILES    _T("AllowSignedFiles")
#define TSC_POLICY_ALLOW_SIGNED_FILES_DFLT  1

#define TSC_POLICY_TRUSTED_CERT_THUMBPRINTS    _T("TrustedCertThumbprints")

//
// Trusted sites registry key. It is either stored in Group Policy or
// under the client registry key.
//
#define UTREG_TRUSTED_SITES_SECTION  _T("TrustedSites")

//
// Ducati registry prefix.
//
#define DUCATI_REG_PREFIX      _T("SOFTWARE\\Microsoft\\Terminal Server Client\\")
#define DUCATI_REG_PREFIX_FMT  _T("SOFTWARE\\Microsoft\\Terminal Server Client\\%s")

//
// Minimum time between sending mouse events (ms)
//
#define UTREG_IH_MIN_SEND_INTERVAL          _T("Min Send Interval")
#define UTREG_IH_MIN_SEND_INTERVAL_DFLT     100

#define UTREG_IH_MIN_SEND_INTERVAL_HIGH     2000

//
// Max size of InputPDU packet (number of events)
//
#define UTREG_IH_MAX_EVENT_COUNT_DFLT       100

//
// Normal max size of InputPDU packet (number of events)
//
#define UTREG_IH_NRM_EVENT_COUNT_DFLT       10

//
// KeepAlive rate in seconds.  IH sends the mouse position at this rate to
// check that the connection is still active.  Zero = no keep-alives.
//
#define UTREG_IH_KEEPALIVE_INTERVAL_DFLT    0

//
// Indicates whether or not we are allowed to forward any input mesages we
// may receive while we don't have the focus.
//
#define UTREG_IH_ALLOWBACKGROUNDINPUT       _T("Allow Background Input")
#define UTREG_IH_ALLOWBACKGROUNDINPUT_DFLT  0

//
// Desktop Size (default 800x600)
//
#define UTREG_UI_DESKTOP_SIZEID             _T("Desktop Size ID")
#define UTREG_UI_DESKTOP_SIZEID_DFLT        1

//
// Screen Mode ID
//
#define UTREG_UI_SCREEN_MODE             _T("Screen Mode ID")
#define UTREG_UI_SCREEN_MODE_DFLT        UI_FULLSCREEN

//
// Span multiple monitors
//
#define UTREG_UI_SPAN_MONITORS           _T("Span Monitors")
#define UTREG_UI_SPAN_MONITORS_DFLT      0

//
// DesktopWidth,DesktopHeight (replace ScreenModeID)
//
#define UTREG_UI_DESKTOP_WIDTH           _T("DesktopWidth")
#define UTREG_UI_DESKTOP_WIDTH_DFLT      0
#define UTREG_UI_DESKTOP_HEIGHT          _T("DesktopHeight")
#define UTREG_UI_DESKTOP_HEIGHT_DFLT     0

#define UTREG_UI_PHYSICAL_DESKTOP_WIDTH        _T("PhysicalDesktopWidth")
#define UTREG_UI_PHYSICAL_DESKTOP_WIDTH_DFLT   0
#define UTREG_UI_PHYSICAL_DESKTOP_HEIGHT       _T("PhysicalDesktopHeight")
#define UTREG_UI_PHYSICAL_DESKTOP_HEIGHT_DFLT  0
#define UTREG_UI_DESKTOP_ORIENTATION           _T("DesktopOrientation")
#define UTREG_UI_DESKTOP_ORIENTATION_DFLT      0xffffffff
#define UTREG_UI_DESKTOP_SCALE_FACTOR          _T("DesktopScaleFactor")
#define UTREG_UI_DESKTOP_SCALE_FACTOR_DFLT     0
#define UTREG_UI_DEVICE_SCALE_FACTOR           _T("DeviceScaleFactor")
#define UTREG_UI_DEVICE_SCALE_FACTOR_DFLT      0

#define UTREG_UI_KEYBOARD_HOOK          _T("KeyboardHook")
#define UTREG_UI_KEYBOARD_HOOK_NEVER      0
#define UTREG_UI_KEYBOARD_HOOK_ALWAYS     1
#define UTREG_UI_KEYBOARD_HOOK_FULLSCREEN 2
#define UTREG_UI_KEYBOARD_HOOK_DFLT       UTREG_UI_KEYBOARD_HOOK_FULLSCREEN

#define UTREG_UI_KEYBOARD_HOOK_FIRST     UTREG_UI_KEYBOARD_HOOK_NEVER
#define UTREG_UI_KEYBOARD_HOOK_LAST      UTREG_UI_KEYBOARD_HOOK_FULLSCREEN

#define UTREG_UI_AUDIO_MODE                 _T("AudioMode")
#define UTREG_UI_AUDIO_MODE_REDIRECT         0
#define UTREG_UI_AUDIO_MODE_PLAY_ON_SERVER   1
#define UTREG_UI_AUDIO_MODE_NONE             2
#define UTREG_UI_AUDIO_MODE_DFLT          UTREG_UI_AUDIO_MODE_REDIRECT

#define UTREG_UI_AUDIO_MODE_FIRST           UTREG_UI_AUDIO_MODE_REDIRECT
#define UTREG_UI_AUDIO_MODE_LAST            UTREG_UI_AUDIO_MODE_NONE

#define TSCSETTING_AUDIOCAPTURE      _T("AudioCaptureMode")
#define TSCSETTING_AUDIOCAPTURE_DFLT        0

#define UTREG_UI_AUDIO_QUALITY            _T("AudioQualityMode")
#define UTREG_UI_AUDIO_QUALITY_DYNAMIC     0
#define UTREG_UI_AUDIO_QUALITY_MEDIUM      1
#define UTREG_UI_AUDIO_QUALITY_HIGH        2

#define UTREG_UI_AUDIO_QUALITY_DFLT        UTREG_UI_AUDIO_QUALITY_DYNAMIC

#define UTREG_UI_AUDIO_QUALITY_FIRST       UTREG_UI_AUDIO_QUALITY_DYNAMIC
#define UTREG_UI_AUDIO_QUALITY_LAST        UTREG_UI_AUDIO_QUALITY_HIGH

#define UTREG_UI_VIDEO_PLAYBACK_MODE                          _T("VideoPlaybackMode")
#define UTREG_UI_VIDEO_PLAYBACK_MODE_DISABLED                 0
#define UTREG_UI_VIDEO_PLAYBACK_MODE_REDIRECT                 1
#define UTREG_UI_VIDEO_PLAYBACK_MODE_REDIRECT_NOGDIFALLBACK   2

#define UTREG_UI_VIDEO_PLAYBACK_MODE_DFLT                     UTREG_UI_VIDEO_PLAYBACK_MODE_REDIRECT

#define UTREG_UI_VIDEO_PLAYBACK_MODE_FIRST           UTREG_UI_VIDEO_PLAYBACK_MODE_DISABLED
#define UTREG_UI_VIDEO_PLAYBACK_MODE_LAST            UTREG_UI_VIDEO_PLAYBACK_MODE_REDIRECT_NOGDIFALLBACK

#define UTREG_UI_AUDIO_PLAYBACK_DEVICE              _T("AudioPlaybackDevice")
#define UTREG_UI_AUDIO_CAPTURE_DEVICE               _T("AudioCaptureDevice")
#define UTREG_UI_AUDIO_DEVICE_DFLT                  _T("default")
#define UTREG_UI_AUDIO_DEVICE_NONE                  _T("none")

#define UTREG_UI_AUTODETECT_RTT_DFLT                _T("N/A")
#define UTREG_UI_AUTODETECT_BANDWIDTH_DFLT          _T("N/A")

#define UTREG_UI_REQUEST_SESSION_ID                 _T("RequestSessionId")
#define UTREG_UI_REMOTE_SESSION_ID                  _T("RemoteSessionId")

#define UTREG_UI_ENABLE_MEDIA_OPTIMIZATIONS         _T("EnableMediaOptimizations")

#define UTREG_UI_CONNECT_TO_CHILD_SESSION           _T("ConnectToChildSession")

#define UTREG_UI_ENABLE_REMOTEEDGEBAR               _T("EnableRemoteEdgeBar")

#define UTREG_UI_ENABLE_REMOTE_TOUCH_VISUALS        _T("EnableRemoteTouchVisuals")

#define UTREG_UI_TOUCH_DEVICE_PRESENT               _T("TouchDevicePresent")

#define UTREG_UI_MAXIMUM_TOUCH_CONTACTS             _T("MaximumTouchContacts")

#define UTREG_UI_ZOOM_LEVEL                         _T("ZoomLevel")
#define UTREG_UI_ZOOM_LEVEL_DFLT                    100

//
// Bpp selection - must be 4, 8, 15, 16, 24, or 32
//
#define UTREG_UI_SESSION_BPP             _T("Session Bpp")

//
// Full Address
//
#define UTREG_UI_FULL_ADDRESS             _T("Full Address")
#define UTREG_UI_FULL_ADDRESS_DFLT        _T("")

//
// Alternate Full Address
//
#define UTREG_UI_ALTERNATE_FULL_ADDRESS             _T("Alternate Full Address")

//
// Pre-connection blob (PCB)
//
#define UTREG_UI_PCB                        _T("PCB")
#define UTREG_UI_PCB_DFLT                   _T("")

//
// Load Balance Info
//
#define UTREG_UI_LOAD_BALANCE_INFO        _T("LoadBalanceInfo")
#define UTREG_UI_LOAD_BALANCE_INFO_DFLT   _T("")

//
//Defines for the MRU list. Should later be implemented as a single string!
//
#define UTREG_UI_SERVER_MRU_DFLT          _T("")
#define UTREG_UI_SERVER_MRU0              _T("MRU0")
#define UTREG_UI_SERVER_MRU1              _T("MRU1")
#define UTREG_UI_SERVER_MRU2              _T("MRU2")
#define UTREG_UI_SERVER_MRU3              _T("MRU3")
#define UTREG_UI_SERVER_MRU4              _T("MRU4")
#define UTREG_UI_SERVER_MRU5              _T("MRU5")
#define UTREG_UI_SERVER_MRU6              _T("MRU6")
#define UTREG_UI_SERVER_MRU7              _T("MRU7")
#define UTREG_UI_SERVER_MRU8              _T("MRU8")
#define UTREG_UI_SERVER_MRU9              _T("MRU9")

//
// Window positioning information - this consists of the following
// parameters to SetWindowPlacement:
// flags, showCmd, NormalPosition(rect)
//
#define UTREG_UI_WIN_POS_STR              _T("WinPosStr")
#define UTREG_UI_WIN_POS_STR_DFLT         _T("0,3,0,0,800,600")

//
// Flag denoting whether accelerator passthrough is enabled on startup
//
#define UTREG_UI_ACCELERATOR_PASSTHROUGH_ENABLED_DFLT  1

//
// SAS sequence: must be RNS_US_SAS_DEL
//
#define UTREG_UI_SAS_SEQUENCE_DFLT         RNS_UD_SAS_DEL

//
// Encryption 0:off 1:on
//
#define UTREG_UI_ENCRYPTION_ENABLED_DFLT   1

//
// Hatch bitmap PDU data flag
//
#define UTREG_UI_HATCH_BITMAP_PDU_DATA        _T("Hatch BitmapPDU Data")
#define UTREG_UI_HATCH_BITMAP_PDU_DATA_DFLT   0

//
// Hatch index PDU data flag
//
#define UTREG_UI_HATCH_INDEX_PDU_DATA         _T("Hatch IndexPDU Data")
#define UTREG_UI_HATCH_INDEX_PDU_DATA_DFLT    0

//
// Hatch SSB data flag
//
#define UTREG_UI_HATCH_SSB_ORDER_DATA         _T("Hatch SSB Order Data")
#define UTREG_UI_HATCH_SSB_ORDER_DATA_DFLT    0

//
// Hatch MemBlt orders flag
//
#define UTREG_UI_HATCH_MEMBLT_ORDER_DATA      _T("Hatch MemBlt Order Data")
#define UTREG_UI_HATCH_MEMBLT_ORDER_DATA_DFLT 0

//
// Label MemBlt orders flag
//
#define UTREG_UI_LABEL_MEMBLT_ORDERS          _T("Label MemBlt Orders")
#define UTREG_UI_LABEL_MEMBLT_ORDERS_DFLT     0

//
// Bitmap Cache Monitor flag
//
#define UTREG_UI_BITMAP_CACHE_MONITOR         _T("Bitmap Cache Monitor")
#define UTREG_UI_BITMAP_CACHE_MONITOR_DFLT    0

//
// Shadow bitmap flag
//
#define UTREG_UI_SHADOW_BITMAP                _T("Shadow Bitmap Enabled")
#define UTREG_UI_SHADOW_BITMAP_DFLT           1

//
// Shadow bitmap flag
//
#define UTREG_UI_USE_SHADOW_IN_FULLSCREEN      _T("UseShadowBitmapInFullScreen")
#define UTREG_UI_USE_SHADOW_IN_FULLSCREEN_DFLT 1

//
// Define the ms-wbt-server reserved port.
//
#define UTREG_UI_MCS_PORT                     _T("Server Port")
#define UTREG_UI_MCS_PORT_DFLT                0xD3D

//
// Server authentication level settings.
//
#define TSC_AUTH_LEVEL_NONE                  0
#define TSC_AUTH_REQUIRED                    1
#define TSC_AUTH_NEGOTIABLE                  2
#define TSC_AUTH_UNSPECIFIED                 3

#define UTREG_UI_AUTH_LEVEL_OVERRIDE         _T("AuthenticationLevelOverride")
#define UTREG_UI_AUTH_LEVEL_GP               _T("AuthenticationLevel")
#define UTREG_UI_AUTH_LEVEL_OVERRIDE_DFLT    TSC_AUTH_UNSPECIFIED

#define UTREG_UI_AUTH_LEVEL                  _T("Authentication Level")
#define UTREG_UI_AUTH_LEVEL_DFLT             TSC_AUTH_NEGOTIABLE
#define UTREG_UI_AUTH_LEVEL_DFLT_NO_CREDSPP  TSC_AUTH_LEVEL_NONE

//
// Authentication service class
//
#define TSC_AUTH_SERVICE_CLASS_DEFAULT      _T("TERMSRV")
#define TSC_AUTH_SERVICE_CLASS_MAX_LENGTH   256

//
// Client authentication certificate.
//
#define UTREG_UI_AUTH_CLIENT_AUTH_CERT    _T("SSLCertificateSHA1Hash")

//
// Key to enable SSL with user-auth
//
#define UTREG_UI_ENABLE_SSL_WITH_USERAUTH _T("EnableSslWithUserAuth")
#define UTREG_UI_ENABLE_SSL_WITH_USERAUTH_DFLT 0

//
// Prompt for credentials.
//
#define UTREG_UI_PROMPT_FOR_CREDS       _T("Prompt For Credentials")
#define UTREG_UI_PROMPT_FOR_CREDS_DFLT  0

//
// Prompt for credentials on the client side.
//
#define UTREG_UI_PROMPT_FOR_CREDS_ON_CLIENT       _T("Prompt For Credentials On Client")
#define UTREG_UI_PROMPT_FOR_CREDS_ON_CLIENT_DFLT  0

//
// Do not negotiate security layer.
//
#define UTREG_UI_NEG_SECURITY_LAYER       _T("Negotiate Security Layer")
#define UTREG_UI_NEG_SECURITY_LAYER_DFLT  1

//
// Enable support for the CredSSP if it is present.
//
#define UTREG_UI_ENABLE_CREDSSP_SUPPORT       _T("EnableCredSspSupport")
#define UTREG_UI_ENABLE_CREDSSP_SUPPORT_DFLT  1

//
// Use RDSTLS explicitly.
//
#define UTREG_UI_USE_RDSTLS       _T("UseRdsTls")
#define UTREG_UI_USE_RDSTLS_DFLT  0

//
// Disable delegation (sending) of user credentials to the server.
//
#define UTREG_UI_DISABLE_CREDENTIALS_DELEGATION  _T("DisableCredentialsDelegation")

//
// KDC Proxy settings.
//

//
// RD Gateway has KDC Proxy enabled.
//
#define UTREG_UI_RDG_IS_KDCPROXY       _T("RDGIsKDCProxy")
#define UTREG_UI_RDG_IS_KDCPROXY_DFLT  0

//
// KDC Proxy name.
//
#define UTREG_UI_KDCPROXY_NAME       _T("KDCProxyName")
#define UTREG_UI_KDCPROXY_NAME_DFLT  _T("")

//
// Restricted Logon enabled.
// The client will not send credentials to the server
// and the server will perform user logon using the
// network access token obtained from CredSSP.
//
#define UTREG_UI_RESTRICTED_LOGON       _T("RestrictedLogon")
#define UTREG_UI_RESTRICTED_LOGON_DFLT  0

//
// LoadSessionDiagnostics is registry-backed and determines whether the
// system menu item is shown and whether the window will be loaded.
// ShowSessionDiagnostics is an event-hooked property for showing via
// system menu.
//
#define UTREG_UI_LOADSESSIONDIAGNOSTICS       _T("LoadSessionDiagnostics")
#define UTREG_UI_LOADSESSIONDIAGNOSTICS_DFLT  0

#define UTREG_UI_SHOWSESSIONDIAGNOSTICS      _T("ShowSessionDiagnostics")
#define UTREG_UI_SHOWSESSIONDIAGNOSTICS_DFLT FALSE

#define UTREG_UI_SHOWGATEWAYINFORMATION      _T("ShowGatewayInformation")
#define UTREG_UI_SHOWGATEWAYINFORMATION_DFLT FALSE

//
// Indicate whether pointer move commands from the server should
// be ignored.
//
#define UTREG_UI_IGNORE_SERVER_MOUSE_MOVES      _T("IgnoreServerGeneratedMouseMoves")
#define UTREG_UI_IGNORE_SERVER_MOUSE_MOVES_DFLT FALSE

//
// Indicate whether the client-side mouse should be remoted.
//
#define UTREG_UI_IGNORE_CLIENTSIDE_MOUSE_INPUT      _T("IgnoreClientSideMouseInput")
#define UTREG_UI_IGNORE_CLIENTSIDE_MOUSE_INPUT_DFLT FALSE

//
// Disable clipboard or printer redirection via the registry.
//
#define UTREG_UI_DISABLE_CLIPBOARD_REDIRECTION      _T("DisableClipboardRedirection")
#define UTREG_UI_DISABLE_CLIPBOARD_REDIRECTION_DFLT 0

#define UTREG_UI_DISABLE_PRINTER_REDIRECTION        _T("DisablePrinterRedirection")
#define UTREG_UI_DISABLE_PRINTER_REDIRECTION_DFLT   0

//
// Revocation checking values read from the registry.
//
#define UTREG_UI_CERT_CHAIN_CHECK         _T("CertChainRevocationCheck")
#define UTREG_UI_CERT_CHAIN_CHECK_DFLT    1

//
// Compression flag
//
#define UTREG_UI_COMPRESS                     _T("Compression")
#define UTREG_UI_COMPRESS_DFLT                1


#define UTREG_UI_MAX_RDP_COMPRESS               _T("MaxRdpCompressionLevel")
#define UTREG_UI_MAX_RDP_COMPRESS_DFLT          PACKET_COMPR_TYPE_MAX

#define UTREG_SEND_CORRELATION_ID             _T("SendCorrelationId")
#define UTREG_SEND_CORRELATION_ID_DFLT        0

#define UTREG_STATIC_CORRELATION_ID           _T("StaticCorrelationId")
#define UTREG_STATIC_CORRELATION_ID_DFLT      _T("")

#define UTREG_DIAGNOSTICS_INFO                _T("DiagnosticsInfo")
#define UTREG_DIAGNOSTICS_INFO_DFLT           _T("")

#define UTREG_UI_BITMAP_PERSISTENCE           _T("BitmapCachePersistEnable")
#define UTREG_UI_BITMAP_PERSISTENCE_DFLT      1

//
// Timeout (in seconds) for a single transport-level connection attempt.   UI may try
// different types of transport, and could also connect to multiple IP addresses during
// a single connection attempt.
//
#define UTREG_UI_SINGLE_CONN_TIMEOUT _T("SingleConnectionTimeout")
#define UTREG_UI_SINGLE_CONN_TIMEOUT_DFLT     8

//
// Private - timeout (sec) interval for TCP-direct connection attempt.   This specify a reg-key
// to tune the single-TCP-connection timeout, and is for private usage only, should not be set
// in general shipping code.  Because once this regkey is set, it will overwrite the single-connection
// timeout, which can also be set via IMsRdpClientAdvancedSettings::put_SingleConnection.
//
#define UTREG_TIMEOUT_TCPDIRECTION_CONNECTION  _T("TimeoutTcpDirectConnection")

//
// Timeout (in seconds) to complete the licensing phase of RDP protocol
//
#define UTREG_LICENSING_TIMEOUT               _T("LicensingTimeout")
#define DEFAULT_LICENSING_TIMEOUT             150

//
// Limit timeout properties to 10 minutes
//
#define MAX_TIMEOUT_SECONDS (10*60)

//
// Overall connection timeout (seconds).  This timeout spans the RDP protocol
// negotiations till granted control PDU.
// It also includes the time required for user to enter credentials
//
#define UTREG_UI_OVERALL_CONN_TIMEOUT_DFLT   900

#define UTREG_UI_SHUTDOWN_TIMEOUT_DFLT       5

//
// Keyboard Layout
//
#define UTREG_UI_KEYBOARD_LAYOUT              _T("Keyboard Layout")
#define UTREG_UI_KEYBOARD_LAYOUT_DFLT         _T("0xffffffff")
#define UTREG_UI_KEYBOARD_LAYOUT_LEN 12

//
// Keyboard Type/Sub Type/Function Key
//
#define UTREG_UI_KEYBOARD_TYPE                _T("Keyboard Type")
#define UTREG_UI_KEYBOARD_TYPE_DFLT           4
#define UTREG_UI_KEYBOARD_SUBTYPE             _T("Keyboard SubType")
#define UTREG_UI_KEYBOARD_SUBTYPE_DFLT        0
#define UTREG_UI_KEYBOARD_FUNCTIONKEY         _T("Keyboard FunctionKeys")
#define UTREG_UI_KEYBOARD_FUNCTIONKEY_DFLT    12

//
// UH registry access parameters/defaults.
//
// Bitmap cache overall params - cache size to alloc, number of cell caches.
//
#define UTREG_UH_TOTAL_BM_CACHE _T("BitmapCacheSize") // RAM cache space
#define UTREG_UH_TOTAL_BM_CACHE_DFLT 1500             // 1500 KB

//
// Whether to scale the RAM and persistent cache sizes by the bit depth of
// the protocol.
//
#define UTREG_UH_SCALE_BM_CACHE_DFLT 1


#define TSC_BITMAPCACHE_8BPP_PROPNAME    _T("BitmapPersistCacheSize")
#define TSC_BITMAPCACHE_16BPP_PROPNAME   _T("BitmapPersistCache16Size")
#define TSC_BITMAPCACHE_24BPP_PROPNAME   _T("BitmapPersistCache24Size")
#define TSC_BITMAPCACHE_32BPP_PROPNAME   _T("BitmapPersistCache32Size")

#define TSC_BITMAPCACHEVIRTUALSIZE_8BPP           10
#define TSC_BITMAPCACHEVIRTUALSIZE_16BPP          20
#define TSC_BITMAPCACHEVIRTUALSIZE_24BPP          30
#define TSC_BITMAPCACHEVIRTUALSIZE_32BPP          40

//
// Maximum BMP cache size in MB
//
#define TSC_MAX_BITMAPCACHESIZE 48
#define TSC_MAX_BITMAPCACHESIZE_KILOBYTES 48000


#define UTREG_UH_BM_PERSIST_CACHE_LOCATION _T("BitmapPersistCacheLocation")

#define UTREG_UH_BM_NUM_CELL_CACHES_DFLT 3

//
// Cell cache defaults - proportion of cache, persistence, cell entries.
//
#define UTREG_UH_BM_CACHE1_PROPORTION_DFLT    2
#define UTREG_UH_BM_CACHE1_PERSISTENCE_DFLT   0
#define UTREG_UH_BM_CACHE1_MAXENTRIES_DFLT    120

#define UTREG_UH_BM_CACHE2_PROPORTION_DFLT    8
#define UTREG_UH_BM_CACHE2_PERSISTENCE_DFLT   0
#define UTREG_UH_BM_CACHE2_MAXENTRIES_DFLT    120

#define UTREG_UH_BM_CACHE3_PROPORTION_DFLT    90
#define UTREG_UH_BM_CACHE3_PERSISTENCE_DFLT   1
#define UTREG_UH_BM_CACHE3_MAXENTRIES_DFLT    65535

#define UTREG_UH_BM_CACHE4_PROPORTION_DFLT    0
#define UTREG_UH_BM_CACHE4_PERSISTENCE_DFLT   0
#define UTREG_UH_BM_CACHE4_MAXENTRIES_DFLT    65535

#define UTREG_UH_BM_CACHE5_PROPORTION_DFLT    0
#define UTREG_UH_BM_CACHE5_PERSISTENCE_DFLT   0
#define UTREG_UH_BM_CACHE5_MAXENTRIES_DFLT    65535

//
// Frequency with which to display output
//
#define UTREG_UH_DRAW_THRESHOLD_DFLT 25

//
// The maximum amount of time to wait for end of frame markers
// (needed on slow connections to show activity)
//
#define MAX_FRAME_UPDATE_DELAY 500      // [milliseconds]

#define UH_GLC_CACHE_MAXIMUMCELLSIZE  2048

//
// Brush support level
//
#define UTREG_UH_BRUSH_SUPPORT_DFLT            TS_BRUSH_COLOR8x8

//
// Offscreen support level
//
#define UTREG_UH_OFFSCREEN_SUPPORT                 _T("OffscreenSupportLevel")
#define UTREG_UH_OFFSCREEN_SUPPORT_DFLT            TS_OFFSCREEN_SUPPORTED

#define UTREG_UH_OFFSCREEN_CACHESIZE               _T("OffscreenCacheSize")
#define UTREG_UH_OFFSCREEN_CACHESIZE_DFLT          TS_OFFSCREEN_CACHE_SIZE_CLIENT_DEFAULT

#define UTREG_UH_OFFSCREEN_CACHEENTRIES            _T("OffscreenCacheEntries")
#define UTREG_UH_OFFSCREEN_CACHEENTRIES_DFLT       TS_OFFSCREEN_CACHE_ENTRIES_DEFAULT

#ifdef DRAW_NINEGRID
//
// DrawNineGrid support level
//
#define UTREG_UH_DRAW_NINEGRID_SUPPORT             _T("DrawNineGridSupportLevel")
#define UTREG_UH_DRAW_NINEGRID_SUPPORT_DFLT        TS_DRAW_NINEGRID_SUPPORTED_REV2

#define UTREG_UH_DRAW_NINEGRID_EMULATE             _T("DrawNineGridEmulate")
#define UTREG_UH_DRAW_NINEGRID_EMULATE_DFLT        0

#define UTREG_UH_DRAW_NINEGRID_CACHESIZE           _T("DrawNineGridCacheSize")
#define UTREG_UH_DRAW_NINEGRID_CACHESIZE_DFLT      TS_DRAW_NINEGRID_CACHE_SIZE_DEFAULT

#define UTREG_UH_DRAW_NINEGRID_CACHEENTRIES        _T("DrawNineGridCacheEntries")
#define UTREG_UH_DRAW_NINEGRID_CACHEENTRIES_DFLT   TS_DRAW_NINEGRID_CACHE_ENTRIES_DEFAULT

#endif // DRAW_NINEGRID

//
// Screen Data PDU type
//
#define UTREG_UH_ALLOW_DYNAMIC_COLOR_FIDELITY   _T("AllowDynamicColorFidelity")
#define UTREG_UH_ALLOW_COLOR_SUBSAMPLING        _T("AllowColorSubsampling")
#define UTREG_UH_MULTI_FRAGMENT_UPDATE_MAX_SIZE _T("MultiFragmentUpdateMaxSize")


//
// Disable ctrl-alt-del flag
//
#define UTREG_UI_DISABLE_CTRLALTDEL         _T("Disable CTRL+ALT+DEL")
#define UTREG_UI_DISABLE_CTRLALTDEL_DFLT    1

//
// Smart Sizing flag
//
#define UTREG_UI_SMARTSIZING                _T("Smart Sizing")
#define UTREG_UI_SMARTSIZING_DFLT           0

//
// Custom Perf Logger
//
#define UTREG_CUSTOM_PERF_LOGGER            _T("RdpPerfLogger")

//
// Allow Viewer Recording
//
#define UTREG_ALLOW_VIEWER_RECORDING        _T("RdpAllowTestRecording")

//
// Set Recording DLL Name
//
#define UTREG_CUSTOM_RECORDING_DLL          _T("RdpSetRecorderDLLName")

//
// Disable Auto Reconnect Component
//
#define UTREG_DISABLE_AUTO_RECONNECT_COMPONENT  _T("DisableAutoReconnectComponent")

//
// Disable Smart Sizing in RemoteApp details pane
//
#define UTREG_UI_DISABLE_SMARTSIZING_REMOTEAPP_DETAILS		_T("Disable Smart Sizing RemoteApp Details")
#define UTREG_UI_DISABLE_SMARTSIZING_REMOTEAPP_DETAILS_DFLT	0

//
// Connect to administrative session (replaces connect to console)
//
#define UTREG_UI_CONNECTTOADMINISTERSERVER  _T("Administrative Session")
#define UTREG_UI_CONNECTTOADMINISTERSERVER_DFLT      0

//
// Enable Windows key flag
//
#define UTREG_UI_ENABLE_WINDOWSKEY_DFLT     1

//
// Enable mouse flag
//
#define UTREG_UI_ENABLE_MOUSE               _T("Enable Mouse")
#define UTREG_UI_ENABLE_MOUSE_DFLT          1

//
// High Resolution Mouse flag
//
#define UTREG_UI_HIGHRES_MOUSE               _T("High Resolution Mouse")
#define UTREG_UI_HIGHRES_MOUSE_DFLT          0

//
// Property to show/hide the remote edge bar
//
#define UTREG_UI_SHOW_REMOTEEDGEBAR          _T("Show RemoteEdgeBar")
#define UTREG_UI_SHOW_REMOTEEDGEBAR_DFLT     1

//
// DoubleClick detect flag
//
#define UTREG_UI_DOUBLECLICK_DETECT_DFLT    0

//
// Disable connection sharing flag
//
#define UTREG_UI_DISABLE_CONNECTION_SHARING         _T("DisableConnectionSharing")
#define UTREG_UI_DISABLE_CONNECTION_SHARING_DFLT    0

//
// Maximize shell flag
//
#define UTREG_UI_MAXIMIZESHELL_DFLT         1

//
// Domain
//
#define UTREG_UI_DOMAIN                     _T("Domain")
#define UTREG_UI_DOMAIN_DFLT                _T("")

//
// UserName
//
#define UTREG_UI_USERNAME                   _T("UserName")
#define UTREG_UI_USERNAME_DFLT              _T("")

//
// Password
//
#define UTREG_UI_PASSWORD                   _T("Password")
#define UTREG_UI_PASSWORD_DFLT              _T("")
#define UTREG_UI_PASSWORD50                 _T("Password 50")
#define UTREG_UI_PASSWORD50_DFLT            _T("")
#define UI_SETTING_PASSWORD51               _T("Password 51")
#define UTREG_UI_PASSWORD_ENCRYPTED         _T("EncryptedPassword")
#define UTREG_UI_WINRT_PASSWORD_ENCRYPTED   _T("WinRTEncryptedPassword")

#define UTREG_UI_WINRT_PASSWORD_ENCODING    _T("WinRTPasswordEncoding")

//
// FedAuth token
//
#define UTREG_UI_FEDAUTH_TOKEN              _T("EndpointFedAuth")
#define UTREG_UI_FEDAUTH_TOKEN_DFLT         _T("")


//
// Salt
//
#define UTREG_UI_SALT50                     _T("Salt 50")
#define UTREG_UI_SALT50_DFLT                _T("")

//
// AlternateShell
//
#define UTREG_UI_ALTERNATESHELL             _T("Alternate Shell")
#define UTREG_UI_ALTERNATESHELL_DFLT        _T("")

//
// WorkingDir
//
#define UTREG_UI_WORKINGDIR                 _T("Shell Working Directory")
#define UTREG_UI_WORKINGDIR_DFLT            _T("")

//
// Workspaces
//
#define UTREG_WORKSPACE_ID              _T("Workspace Id")
#define UTREG_WORKSPACE_ID_DFLT         _T("")
#define UTREG_WORKSPACE_ENABLERECONNECT   _T("EnableWorkspaceReconnect")
#define UTREG_WORKSPACE_ENABLERECONNECT_DFLT 0

#define UTREG_APPCONTAINER_ID       _T("AppContainerID")

//
#ifdef ENABLE_RAIL
// REMOTEAPPLICATIONMODE
//

// Reg keys
#define UTREG_REMOTEAPPLICATION_SECTION             _T("RemoteApplications")
#define UTREG_REMOTEAPPLICATION_ICON                _T("RemoteApplicationIcon")
#define UTREG_REMOTEAPPLICATION_ICON_DFLT           _T("")

#define UTREG_REMOTEAPPLICATION_SCALABILITY_TESTS  _T("RailScalabilityTest")

// Settings store IDs

#define UTREG_UI_REMOTEAPPLICATION_PROGRAM      _T("RemoteApplicationProgram")
#define UTREG_UI_REMOTEAPPLICATION_PROGRAM_DFLT _T("")

#define UTREG_UI_REMOTEAPPLICATIONMODE        _T("RemoteApplicationMode")
#define UTREG_UI_REMOTEAPPLICATIONMODE_DFLT   0

#define UTREG_UI_REMOTEAPPLICATION_NAME        _T("RemoteApplicationName")
#define UTREG_UI_REMOTEAPPLICATION_NAME_DFLT   _T("")

#define UTREG_UI_REMOTEAPPLICATION_ICONFILE    _T("RemoteApplicationIcon")
#define UTREG_UI_REMOTEAPPLICATION_ICONFILE_DFLT _T("")

#define UTREG_UI_REMOTEAPPLICATION_GUID    _T("RemoteApplicationGuid")
#define UTREG_UI_REMOTEAPPLICATION_GUID_DFLT _T("")

#define UTREG_UI_REMOTEAPPLICATION_FILE         _T("RemoteApplicationFile")
#define UTREG_UI_REMOTEAPPLICATION_FILE_DFLT    _T("")

#define UTREG_UI_REMOTEAPPLICATION_EXTENSIONS        _T("RemoteApplicationFileExtensions")
#define UTREG_UI_REMOTEAPPLICATION_EXTENSIONS_DFLT   _T("")

#define UTREG_UI_REMOTEAPPLICATION_APPLAUNCH_TIMEOUT  _T("PostLogonErrorTimeout")
#define UTREG_UI_REMOTEAPPLICATION_APPLAUNCH_TIMEOUT_DFLT   (15 * 1000)

#define UTREG_UI_REMOTEAPPLICATION_EXPAND_CWD   _T("RemoteApplicationExpandWorkingdir")
#define UTREG_UI_REMOTEAPPLICATION_EXPAND_CWD_DFLT 0

#define UTREG_UI_REMOTEAPPLICATION_ARGUMENT    _T("RemoteApplicationCmdLine")
#define UTREG_UI_REMOTEAPPLICATION_ARGUMENT_DFLT _T("")

#define UTREG_UI_REMOTEAPPLICATION_EXPAND_ARGUMENT _T("RemoteApplicationExpandCmdLine")
#define UTREG_UI_REMOTEAPPLICATION_EXPAND_ARGUMENT_DFLT 1

#ifdef DBG
#define UTREG_RAIL_HATCH_VISIBLE                _T("RAILDBG_HATCH_VIS")
#define UTREG_RAIL_HATCH_VISIBLE_DFLT           0

#define UTREG_RAIL_HATCH_VISIBLE_WITHOUT_DATA   _T("RAILDBG_HATCH_VIS_WOUT")
#define UTREG_RAIL_HATCH_VISIBLE_WITHOUT_DATA_DFLT  0

#define UTREG_RAIL_HATCH_NON_VISIBLE            _T("RAILDBG_HATCH_NON_VIS")
#define UTREG_RAIL_HATCH_NON_VISIBLE_DFLT       0

#define UTREG_RAIL_HATCH_WINDOW                 _T("RAILDBG_HATCH_WINDOW")
#define UTREG_RAIL_HATCH_WINDOW_DFLT            0

#define UTREG_RAIL_STAY_CONNECTED_ON_LOW_CAPS       _T("RAILDBG_STAYCONNECTED")
#define UTREG_RAIL_STAY_CONNECTED_ON_LOW_CAPS_DFLT  0

#define UTREG_RAIL_FORCE_CONTAINER_VISIBLE       _T("RailDbgForceContainerVisible")
#define UTREG_RAIL_FORCE_CONTAINER_VISIBLE_DFLT  0

#endif // DBG

#define UTREG_UI_DISABLEREMOTEAPPCAPSCHECK        _T("DisableRemoteAppCapsCheck")
#define UTREG_UI_DISABLEREMOTEAPPCAPSCHECK_DFLT   0

#define UTREG_RAIL_REMOTEAPPLICATION_APPID      _T("RemoteApplicationAppID")
#define UTREG_RAIL_REMOTEAPPLICATION_APPID_DFLT    _T("")


#define UTREG_RAIL_NO_BITBLT_ON_CLX_SHADOW_VISIBLE       _T("RailNoBltOnClxShadowVisible")
#define UTREG_RAIL_NO_BITBLT_ON_CLX_SHADOW_VISIBLE_DFLT  0

#endif // ENABLE_RAIL

//
// Hotkey names
//
// Full screen VK code
#define UTREG_UI_FULL_SCREEN_VK_CODE_DFLT           VK_CANCEL
#define UTREG_UI_FULL_SCREEN_VK_CODE_NEC98_DFLT     VK_F12

#define UTREG_UI_CTRL_ESC_VK_CODE_DFLT              VK_HOME

#define UTREG_UI_ALT_ESC_VK_CODE_DFLT               VK_INSERT

#define UTREG_UI_ALT_TAB_VK_CODE_DFLT               VK_PRIOR

#define UTREG_UI_ALT_SHFTAB_VK_CODE_DFLT            VK_NEXT

#define UTREG_UI_ALT_SPACE_VK_CODE_DFLT             VK_DELETE

#define UTREG_UI_CTRL_ALTDELETE_VK_CODE_DFLT        VK_END
#define UTREG_UI_CTRL_ALTDELETE_VK_CODE_NEC98_DFLT  VK_F11

#define UTREG_UI_AX_TO_CONTAINER_LEFT_VK_CODE_DFLT  VK_LEFT
#define UTREG_UI_AX_TO_CONTAINER_RIGHT_VK_CODE_DFLT VK_RIGHT
#define UTREG_UI_AX_TO_CONTAINER_UP_VK_CODE_DFLT    VK_UP
#define UTREG_UI_AX_TO_CONTAINER_DOWN_VK_CODE_DFLT  VK_DOWN

//
// IME
//
#define UTREG_IME_MAPPING_TABLE_SECTION  _T("IME Mapping Table")
#define UTREG_IME_MAPPING_TABLE_JPN      _T("IME Mapping Table\\JPN")
#define UTREG_IME_MAPPING_TABLE_KOR      _T("IME Mapping Table\\KOR")
#define UTREG_IME_MAPPING_TABLE_CHT      _T("IME Mapping Table\\CHT")
#define UTREG_IME_MAPPING_TABLE_CHS      _T("IME Mapping Table\\CHS")

//
// Drive mapping
//
#define TSCSETTING_REDIRECTDRIVES        _T("RedirectDrives")
#define TSCSETTING_REDIRECTDRIVES_DFLT   0

#define TSCSETTING_REDIRECTPRINTERS      _T("RedirectPrinters")
#define TSCSETTING_REDIRECTPRINTERS_DFLT 1

#define TSCSETTING_REDIRECTCOMPORTS      _T("RedirectCOMPorts")
#define TSCSETTING_REDIRECTCOMPORTS_DFLT 0

#define TSCSETTING_REDIRECTCLIP          _T("RedirectClipboard")
#define TSCSETTING_REDIRECTCLIP_DFLT     1

#define TSCSETTING_REDIRECTPOSDEVICES    _T("RedirectPOSDevices")
#define TSCSETTING_REDIRECTPOSDEVICES_DFLT    0

#define TSCSETTING_REDIRECTDIRECTX       _T("RedirectDirectX")
#define TSCSETTING_REDIRECTDIRECTX_DFLT  1

//
// will hold info on specific devices to redirec
//
#define TSCSETTING_DEVICESSPECIFIED            _T("DevicesToRedirect")
#define TSCSETTING_DEVICESSPECIFIED_DFLT       _T("")
#define TSCSETTING_DEVICESSPECIFIED_PNP_USEALL _T("*")
#define TSCSETTING_DEVICESSPECIFIED_DYNAMIC    _T("DynamicDevices")
#define TSCSETTING_USBDEVICESSPECIFIED         _T("UsbDevicesToRedirect")
#define TSCSETTING_USBDEVICESSPECIFIED_DEFAULT _T("")
#define TSCSETTING_USBDEVICESSPECIFIED_USEALL  _T("*")


//
// will hold info on specific devices to redirect
// if user puts *, then it means redirect all drives
// if user puts -, then it means to use "RedirectDrives" flag
//
#define TSCSETTING_DRIVESSPECIFIED          _T("DrivesToRedirect")
#define TSCSETTING_DRIVESSPECIFIED_DFLT     _T("-")
#define TSCSETTING_DRIVESSPECIFIED_USEALL   _T("*")
#define TSCSETTING_DRIVESSPECIFIED_DYNAMIC  _T("DynamicDrives")

#define TSCSETTING_REDIRECTSCARDS        _T("RedirectSmartCards")
#define TSCSETTING_REDIRECTSCARDS_DFLT   1

#define TSCSETTING_DISPLAYCONNECTIONBAR  _T("DisplayConnectionBar")
#define TSCSETTING_DISPLAYCONNECTIONBAR_DFLT  1

#define TSCSETTING_PINCONNECTIONBAR       _T("PinConnectionBar")
#define TSCSETTING_PINCONNECTIONBAR_DFLT  1

#define UTREG_UI_SHOW_BBAR_QUALITY_BUTTON  _T("ConnectionBarShowQualityButton")

#define TSCSETTING_ENABLEAUTORECONNECT _T("AutoReconnection Enabled")
#define TSCSETTING_ENABLEAUTORECONNECT_DFLT  1

#define TSCSETTING_ARC_RETRIES         _T("AutoReconnect Max Retries")
#define TSCSETTING_ARC_RETRIES_DFLT     20

#define UTREG_DEBUG_ALLOWDEBUGIFACE    _T("AllowDebugInterface")
#define UTREG_DEBUG_ALLOWDEBUGIFACE_DFLT 0

//
// Redirection security flags
//
#define REG_SECURITY_FILTER_SECTION      _T("LocalDevices")
#define REG_SECURITY_FILTER_PUBLISHER_SECTION   _T("PublisherBypassList")
#define REDIRSEC_PROMPT_EVERYTHING       0x0000
#define REDIRSEC_DRIVES                  0x0001
#define REDIRSEC_PORTS                   0x0002
#define REDIRSEC_CLIPBOARD               0x0004
#define REDIRSEC_CREDENTIALS             0x0008
// The REDIRSEC_RESERVED flag was used for SmartCard PIN redirection
// for Windows Vista and must not be reused.
#define REDIRSEC_RESERVED                0x0010
#define REDIRSEC_DEVICES                 0x0020
#define REDIRSEC_PRINTERS                0x0040
#define REDIRSEC_AUDIOCAPTURE            0x0080
#define REDIRSEC_DIRECTX                 0x0100
#define REDIRSEC_USBDEVICES              0x0200

//
// MULTIMEDIA REG KEYS
//
#define UTREG_MULTIMEDIA_ENABLE         _T("MultimediaEnableRedirection")
#define UTREG_MULTIMEDIA_ENABLE_DFLT    0

#define UTREG_MULTIMEDIA_PLUGIN_DLLNAME         _T("MultimediaDllPluginName")
#define UTREG_MULTIMEDIA_PLUGIN_DLLNAME_DFLT    _T("System.Windows.Media.Core.dll")

//
// Direct3D remoting regkeys
//
#define UTREG_RDPD3D_ALLOWREFDEVICE       _T("Rdpd3dAllowReferenceDevice")
#define UTREG_RDPD3D_ALLOWREFDEVICE_DFLT  0

//
// Username regkeys
//
#define REG_USERNAME_HINT_ENTRY _T("UsernameHint")
#define REG_USERNAME_HINT_TYPE_ENTRY _T("UsernameHintType")

#define REG_SERVERS_SECTION _T("Servers")
#define REG_CERT_HASH_ENTRY _T("CertHash")

//
// Default number of auto-reconnection attempts.
//

#define UTREG_MAX_AUTORECONNECT_ATTEMPTS _T("MaxAutoReconnectAttempts")
#define TSC_DEFAULT_MAX_ARC_CONNECTION_ATTEMPTS   20
#define TSC_MAX_ARC_CONNECTION_ATTEMPTS_LIMIT    200

//
// Maximum # of redirection addresses sent by the server
//
#define TSC_MAX_REDIRECTED_SERVER_ADDRESSES       25
//
// CLX Command Line
//
#define UTREG_CLX_COMMANDLINE                   _T("ClxCommandLine")

#ifdef TSC_PROXY
//
// Proxy section in the registry.
//
#define UTREG_PROXY_SECTION                            _T("Gateway")

//
// Proxy Hostname
//
#define TSCSETTING_TRANSPORT_PROXYHOSTNAME             _T("GatewayHostname")
#define TSCSETTING_TRANSPORT_PROXYHOSTNAME_DFLT        _T("")

//
// Proxy User name. Applied only via RdpXClientSettings and currently not read from RDP file.
//
#define TSCSETTING_TRANSPORT_PROXYUSERNAME             _T("GatewayUsername")
#define TSCSETTING_TRANSPORT_PROXYUSERNAME_DFLT        _T("")

//
// Proxy Domain name. Applied only via RdpXClientSettings and currently not read from RDP file.
//
#define TSCSETTING_TRANSPORT_PROXYDOMAIN               _T("GatewayDomain")
#define TSCSETTING_TRANSPORT_PROXYDOMAIN_DFLT          _T("")

//
// Proxy password. Applied only via RdpXClientSettings and currently not read from RDP file.
//
#define TSCSETTING_TRANSPORT_PROXYPASSWORD             _T("GatewayPassword")
#define TSCSETTING_TRANSPORT_PROXYPASSWORD_DFLT        _T("")

//
// Proxy Usage Mode
//
#define TSCSETTING_TRANSPORT_PROXYUSAGEMETHOD          _T("GatewayUsageMethod")
#define TSCSETTING_TRANSPORT_PROXYUSAGEMETHOD_DFLT     TSC_PROXY_MODE_NONE_DETECT

//
// Proxy Credentials Type
//
#define TSCSETTING_TRANSPORT_PROXYCREDSSOURCE          _T("GatewayCredentialsSource")
#define TSCSETTING_TRANSPORT_PROXYCREDSSOURCE_DFLT     TSC_PROXY_CREDS_MODE_ANY

//
// Proxy Access Token
//
#define TSCSETTING_TRANSPORT_GATEWAYACEESSTOKEN          _T("GatewayAccessToken")
#define TSCSETTING_TRANSPORT_GATEWAYACEESSTOKEN_DFLT     _T("")


//
// Proxy Profile Usage Mode
//
#define TSCSETTING_TRANSPORT_PROXYPROFILEMETHOD        _T("GatewayProfileUsageMethod")
#define TSCSETTING_TRANSPORT_PROXYPROFILEMETHOD_DFLT   TSC_PROXY_PROFILE_MODE_DEFAULT

//
// Credential Sharing
//
#define TSCSETTING_TRANSPORT_CRED_SHARING               _T("PromptCredentialOnce")
#define TSCSETTING_TRANSPORT_CRED_SHARING_DFLT          TSC_PROXY_CRED_SHARING_OFF

//
// Proxy One Time Password Requirement
//
#define TSCSETTING_TRANSPORT_PROXYREQUIREPREAUTH        _T("Require pre-authentication")
#define TSCSETTING_TRANSPORT_PROXYREQUIREPREAUTH_DFLT   TSC_PROXY_REQUIREPREAUTH_DEFAULT

//
// Proxy pre-authentication server address
//
#define TSCSETTING_TRANSPORT_PROXYPREAUTHSERVERADDR             _T("Pre-authentication server address")
#define TSCSETTING_TRANSPORT_PROXYPREAUTHSERVERADDR_DFLT        _T("")

//
// Proxy cookie based authentication server address
//
#define TSCSETTING_TRANSPORT_PROXYAUTHCOOKIESERVERADDR          _T("Cookie based authentication server address")
#define TSCSETTING_TRANSPORT_PROXYAUTHCOOKIESERVERADDR_DFLT     _T("")

//
// Proxy cookie download login page
//
#define TSCSETTING_TRANSPORT_PROXYAUTHLOGINPAGE          _T("Login web page address")
#define TSCSETTING_TRANSPORT_PROXYAUTHLOGINPAGE_DFLT     _T("")

//
// Proxy support URL
//
#define TSCSETTING_TRANSPORT_PROXYSUPPORTURL             _T("Support URL")
#define TSCSETTING_TRANSPORT_PROXYSUPPORTURL_DFLT        _T("")

//
// Proxy brokering type
//
#define TSCSETTING_TRANSPORT_PROXYBROKERINGTYPE        _T("GatewayBrokeringType")
#define TSCSETTING_TRANSPORT_PROXYBROKERINGTYPE_DFLT   TSC_PROXY_CONTROL_BROKERING_TYPE_DEFAULT

//
// Proxy settings values currently used.
//
#define TSCSETTING_TRANSPORT_PROXYCREDS_MODE_USERPASS   TSC_PROXY_CREDS_MODE_USERPASS
#define TSCSETTING_TRANSPORT_PROXYMODE_DETECT           TSC_PROXY_MODE_DETECT
#define UTREG_UI_CONNECTION_MODE_PREFIX_TCP             _T("TCP")
#define UTREG_UI_CONNECTION_MODE_PREFIX_PROXY           _T("PROXY")

//
// Proxy related core properties. Applied only via RdpXClientSettings and currently not read from RDP file.
//
#define UTREG_UI_CONNECTION_MODE_PREFIX                 _T("ConnectModeString")
#define UTREG_UI_CONNECTION_MODE_PREFIX_DFLT            UTREG_UI_CONNECTION_MODE_PREFIX_TCP

#endif

//
// RDP file signature settings
//
#define TSCSETTING_SIGNATURE_SCOPE                  _T("SignScope")
#define TSCSETTING_SIGNATURE                        _T("Signature")

//
// Revocation checking for RDP file signing controlled by registry.
//
#define UTREG_UI_RDPSIGN_CERT_CHAIN_CHECK         _T("RdpSignCertChainRevocationCheck")
#define UTREG_UI_RDPSIGN_CERT_CHAIN_CHECK_DFLT    0


//
// Remote Sessions manager timeouts
//
#define TSC_RSESSIONSMGR_BIND_TIMEOUT_IN_MILLIS         1000
#define TSC_RSESSIONSMGR_BIND_RETRY_ATTEMPTS            5
#define TSC_RSESSIONSMGR_BIND_RETRY_TIMEOUT_IN_MILLIS   2000

//
// Windows Presentation Framework Support API
//

#define UCE_CHANNEL_NAME_A                              "uceprox"
#define DWM_CHANNEL_NAME_A                              "dwmprox"

#define UTREG_UI_DISABLE_WPF_PIPE                       _T("DisableWindowsPresentationFrameworkPipe")
#define UTREG_UI_DISABLE_WPF_PIPE_DFLT                  FALSE


//
// Enable support for not sending the SuppressOutputPDU when minimized
//
#define UTREG_UI_REMDESK_SUPPRESS_WHEN_MINIMIZED          _T("RemoteDesktop_SuppressWhenMinimized")

#define UTREG_UI_REMDESK_SUPPRESS_WHEN_MINIMIZED_DFLT     1
#define UTREG_UI_REMDESK_SUPPRESS_WHEN_MINIMIZED_AUTO     0
#define UTREG_UI_REMDESK_SUPPRESS_WHEN_MINIMIZED_ENABLE   1
#define UTREG_UI_REMDESK_SUPPRESS_WHEN_MINIMIZED_DISABLED 2

//
// Internal regkey to force RAIL to always use CredMan
//
#define UTREG_UI_REMOTEPROGRAMS_ALWAYS_USE_CREDMAN       _T("RemoteProgramsAlwaysUseCredMan")
#define UTREG_UI_REMOTEPROGRAMS_ALWAYS_USE_CREDMAN_DFLT  0

//
// Internal regkey to disable order support in the TS-Client to test Screen Data
//
#define UTREG_UI_SUPPRESS_ORDERS                       _T("SuppressOrders")
#define UTREG_UI_SUPPRESS_ORDERS_DFLT                  FALSE

//
// Monitor layout key and values
//
#define UTREG_UI_MONITORS                       _T("Monitors")
#define UTREG_UI_MONITORS_LEFT                  _T("left")
#define UTREG_UI_MONITORS_TOP                   _T("top")
#define UTREG_UI_MONITORS_RIGHT                 _T("right")
#define UTREG_UI_MONITORS_BOTTOM                _T("bottom")
#define UTREG_UI_MONITORS_PHYSICAL_WIDTH        _T("physicalWidth")
#define UTREG_UI_MONITORS_PHYSICAL_HEIGHT       _T("physicalHeight")
#define UTREG_UI_MONITORS_ORIENTATION           _T("orientation")
#define UTREG_UI_MONITORS_DESKTOP_SCALE_FACTOR  _T("desktopScaleFactor")
#define UTREG_UI_MONITORS_DEVICE_SCALE_FACTOR   _T("deviceScaleFactor")
#define UTREG_UI_MONITORS_FLAGS                 _T("flags")

//
// Use multimon property.
//
#define UTREG_UI_USE_MULTIMON       _T("Use Multimon")
#define UTREG_UI_USE_MULTIMON_DFLT  0

//
// SuperPan property.
//
#define UTREG_UI_ENABLE_SUPERPAN       _T("EnableSuperPan")
#define UTREG_UI_ENABLE_SUPERPAN_DFLT  0

//
// SuperPan acceleration factor.
//
#define UTREG_UI_SUPERPAN_ACCEL_FACTOR       _T("SuperPanAccelerationFactor")
#define UTREG_UI_SUPERPAN_ACCEL_FACTOR_DFLT  1

//
// Public mode property
//
#define UTREG_UI_ENABLE_PUBLIC_MODE       _T("Public Mode")
#define UTREG_UI_ENABLE_PUBLIC_MODE_DFLT  0

//
// Trusted redirection switch
//
#define UTREG_UI_USE_REDIRECTION_SERVER_NAME               _T("Use Redirection Server Name")
#define UTREG_UI_USE_REDIRECTION_SERVER_NAME_DFLT          0

//
// Show shutdown dialog when closing the client.
//
#define UTREG_UI_SHOW_SHUTDOWN_DLG        _T("ShowShutdownDialog")
#define UTREG_UI_SHOW_SHUTDOWN_DLG_DFLT   1

//
// Property name and range of values for network connection types
//
#define UTREG_NETWORK_CONNECTION_TYPE             _T("connection type")
#define UTREG_NETWORK_CONNECTION_MODEM            1
#define UTREG_NETWORK_CONNECTION_BROADBAND_LOW    2
#define UTREG_NETWORK_CONNECTION_SATELLITE        3
#define UTREG_NETWORK_CONNECTION_BROADBAND_HIGH   4
#define UTREG_NETWORK_CONNECTION_WAN              5
#define UTREG_NETWORK_CONNECTION_LAN              6
#define UTREG_NETWORK_CONNECTION_AUTO_DETECT      7

#define UTREG_NETWORK_CONNECTION_TYPE_DFLT        UTREG_NETWORK_CONNECTION_AUTO_DETECT
#define UTREG_NETWORK_CONNECTION_TYPE_FIRST       UTREG_NETWORK_CONNECTION_MODEM
#define UTREG_NETWORK_CONNECTION_TYPE_LAST        UTREG_NETWORK_CONNECTION_AUTO_DETECT

#define UTREG_NETWORK_AUTO_DETECT _T("NetworkAutodetect")
#define UTREG_NETWORK_AUTO_DETECT_DFLT 1

#define UTREG_BANDWIDTH_AUTO_DETECT _T("BandwidthAutodetect")
#define UTREG_BANDWIDTH_AUTO_DETECT_DFLT 1

//
// Disable codec caps
//
#define UTREG_CORE_DISABLE_CODEC_CAPS           _T("DisableCodecCaps")
#define UTREG_CORE_DISABLE_CODEC_CAPS_DFLT      0

//
// Simulate CPU without SSE support
//
#define UTREG_CORE_DISABLE_SSESUPPORT           _T("DisableSSESupport")
#define UTREG_CORE_DISABLE_SSESUPPORT_DFLT      0

//
// Enable/disable drawing updates to the CLX test surface. To use
// the surface CLX must also be loaded.
//
#define UTREG_UI_USE_CLX_MIRROR_SURFACE         _T("UseClxMirrorSurface")
#define UTREG_UI_USE_CLX_MIRROR_SURFACE_DFLT    0

//
// Enable/disable overlays when using the DynVC graphics protocol.
//
#define UTREG_UI_ENABLE_GFXPIPE_OVERLAYS        _T("EnableGfxPipelineOverlays")
#define UTREG_UI_ENABLE_GFXPIPE_OVERLAYS_DFLT   0

//
// Specify whether touch support should be checked on the local machine when
// creating the BBar.
//
#define UTREG_UI_SCALE_BBAR_FOR_TOUCH        _T("ScaleBBarForTouch")
#define UTREG_UI_SCALE_BBAR_FOR_TOUCH_DFLT   1

//
// Specify whether pointer frames received from the system should be
// traced on the client.
//
#define UTREG_UI_TRACE_POINTER_FRAMES        _T("TracePointerFrames")
#define UTREG_UI_TRACE_POINTER_FRAMES_DFLT   0

//
// Specify whether touch remoting should disable timestamps.
//
#define UTREG_UI_DISABLE_TOUCH_TIMESTAMP_REMOTING       _T("DisableTouchTimestampRemoting")
#define UTREG_UI_DISABLE_TOUCH_TIMESTAMP_REMOTING_DFLT  0

//
// Specify whether touch should be remoted.
//
#define UTREG_UI_DISABLE_TOUCH_REMOTING       _T("DisableTouchRemoting")
#define UTREG_UI_DISABLE_TOUCH_REMOTING_DFLT  0

//
// Temporary registry key for using the surface presenter.
//
#define UTREG_UI_APPCONTAINERCLIENT_USE_SURFACE_PRESENTER _T("AppContainerClientUseSurfacePresenter")
#define UTREG_UI_APPCONTAINERCLIENT_USE_SURFACE_PRESENTER_DFLT 0
#define UTREG_UI_APPCONTAINERCLIENT_USE_SURFACE_PRESENTER_TRIDENT 1

//
// Enable/disable frame buffer redirection
//
#define UTREG_UI_ENABLE_FRAME_BUFFER_REDIRECTION          _T("EnableFrameBufferRedirection")

//
// Use frame buffer redirection external presenter
//
#define UTREG_UI_FRAME_BUFFER_REDIRECTION_PRESENTER       _T("FrameBufferRedirectionPresenter")

//
// Display view orientation
//
#define UTREG_UI_DISPLAY_VIEW_ORIENTATION                 _T("DisplayViewOrientation")

#define UTREG_UI_IGNORE_CURSORS                           _T("IgnoreCursors")

//
// GP - disable UDP
//
#define UTREG_GP_DISABLE_UDP_FROM_CLIENT                  _T("fClientDisableUDP")

//
// Private - Enable/disable UDP transport from client side
//
#define UTREG_DISABLE_UDP_FROM_CLIENT                     _T("DisableUDPTransport")
#define UTREG_DISABLE_UDP_FROM_CLIENT_DFLT                0

//
// Private - Enable/disable MT soft-sync option from client side
//
#define UTREG_DISABLE_MT_SOFT_SYNC_FROM_CLIENT            _T("DisableMTSoftSync")
#define UTREG_DISABLE_MT_SOFT_SYNC_FROM_CLIENT_DFLT       0


//
// Enable/disable (1) full, (2) thin client or (3) small cache mode
// for RDP 8 and later graphics.
//
#define UTREG_ENABLE_CLIENTMODE_GRAPHICS                  _T("SetClientProtocolSpecMode")
#define UTREG_ENABLE_CLIENTMODE_GRAPHICS_FULLMODE         0
#define UTREG_ENABLE_CLIENTMODE_GRAPHICS_THINCLIENT       1
#define UTREG_ENABLE_CLIENTMODE_GRAPHICS_SMALLCACHE       2
#define UTREG_ENABLE_CLIENTMODE_GRAPHICS_DFLT             UTREG_ENABLE_CLIENTMODE_GRAPHICS_SMALLCACHE

//
// Property to disable seamless language bar integration in RAIL
//
#define UTREG_UI_DISABLE_SEAMLESS_LANGUAGE_BAR          _T("DisableSeamlessLanguageBar")
#define UTREG_UI_DISABLE_SEAMLESS_LANGUAGE_BAR_DFLT     0

//
// Property to show publisher warning dialogs
//
#define UTREG_STORE_APP_SHOW_PUBLISHER_WARNING_DIALOG         _T("ShowPublisherWarningDialog")
#define UTREG_STORE_APP_SHOW_PUBLISHER_WARNING_DIALOG_DFLT    1

//
// Proprty to determine if UDP transport is connected
//
#define UTREG_UI_UDP_TRANSPORT_CONNECTED            _T("UDPTransportConnected")
#define UTREG_UI_UDP_TRANSPORT_CONNECTED_DFLT        0

//
// Specify the HTTPS address to be used for event log upload
//
#define UTREG_EVENTLOG_UPLOAD_ADDRESS               _T("EventLogUploadAddress")
#define UTREG_EVENTLOG_UPLOAD_ADDRESS_DFLT          _T("")

//
// Private - Enable/Disable remoting of local edge gestures (swipes)
//
#define UTREG_ENABLE_REMOTE_TOUCH_EDGEGESTURE_PREFERENCE            _T("EnableRemoteTouchEdgeGesturePreference")
#define UTREG_ENABLE_REMOTE_TOUCH_EDGEGESTURE_PREFERENCE_DFLT       1

//
// Private - Indicate we are in a collab (Remote Assistance) scenario
//
#define UTREG_UI_IS_COLLAB_SCENARIO      _T("IsCollabScenario")

//
// Private - Indicate we need to enable zoom in viewer
//
#define UTREG_UI_ENABLE_ZOOM      _T("EnableZoom")

//
// Private - Force enable hardware mode in client (use HW framebuffer and cache)
//
#define UTREG_GP_ENABLE_HARDWARE_MODE_GRAPHICS          _T("EnableHardwareMode")
#define UTREG_GP_ENABLE_HARDWARE_MODE_GRAPHICS_DFLT     (1)

//
// Private - Force disable hardware AVC decoding in client
//
#define UTREG_DISABLE_AVC_HARDWARE_DECODE               _T("DisableH264HardwareDecode")
#define UTREG_DISABLE_AVC_HARDWARE_DECODE_DFLT          (0)

//
// Private - Enable AVC CPU decoding in client (if supported by OS)
//
#define UTREG_ENABLE_AVC_CPU_DECODE             _T("EnableH264CPUDecode")
#define UTREG_ENABLE_AVC_CPU_DECODE_DFLT        (1)

//
// Private/Temporary - Enable UI enhancements for the Quick Re-Connect feature
//
#define UTREG_ENABLE_REMOTEAPP_QUICKRECONNECTUI         _T("QuickReconnectUI")
#define UTREG_ENABLE_REMOTEAPP_QUICKRECONNECTUI_DEFAULT 1


//
// Key to disable HiDef RemoteApp
//
#define UTREG_UI_ENABLE_HIDEF_REMOTEAPP_SUPPORT       _T("EnableAdvancedRemoteFXRemoteAppSupport")
#define UTREG_UI_ENABLE_HIDEF_REMOTEAPP_SUPPORT_DFLT  1

//
// Reduce allow-list of properties in RDP files when launching from an external source.
//
#define UTREG_STORE_APP_SETTINGS_SOURCE_EXTERNAL _T("SettingsSourceExternal")

//
// for Test
//
#define UTREG_ENABLE_TEST_MODE _T("EnableTestMode")
#define UTREG_RDCLIENT_ALLOW_MULTIPLE_INSTANCE _T("RdClientAllowMultipleInstance")

#define UTREG_ENABLE_CMDLINE_MODE _T("EnableCmdLineMode")

#define UTREG_RDCLIENT_SHOW_SIGNOUT_DLG _T("RdclientShowSignoutDialog")
#define UTREG_RDCLIENT_SHOW_SIGNOUT_DLG_DFLT 1

#define UTREG_RDCLIENT_SHOW_EXIT_DLG _T("RdclientShowExitDialog")
#define UTREG_RDCLIENT_SHOW_EXIT_DLG_DFLT 1


#endif // _H_AUTREG
