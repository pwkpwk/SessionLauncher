// dllmain.cpp : Implementation of DllMain.

#include "stdafx.h"
#include "resource.h"
#include "dllmain.h"

CSessionHelperModule _AtlModule;

// DLL Entry Point
extern "C" BOOL WINAPI DllMain( HINSTANCE, DWORD dwReason, LPVOID lpReserved )
{
	return _AtlModule.DllMain(dwReason, lpReserved); 
}
