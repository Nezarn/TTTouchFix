#include <Windows.h>
#include "MinHook.h"

int (WINAPI* GetSystemMetrics_Original)(int nIndex);
int WINAPI GetSystemMetrics_Hook(int nIndex) 
{
	if(nIndex == SM_DIGITIZER)
		return 0;

	return GetSystemMetrics_Original(nIndex);
}

void Init()
{
	MH_Initialize();
	MH_CreateHookApi(L"user32.dll", "GetSystemMetrics", GetSystemMetrics_Hook, (void**)&GetSystemMetrics_Original);
	MH_EnableHook(MH_ALL_HOOKS);
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		Init();
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}