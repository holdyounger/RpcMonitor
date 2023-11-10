#include "ntdll.h"

NtQueryInformationProcessFn_T	NtQueryInformationProcessFn	= NULL;


//-----------------------------------------------------------------------------
NTSTATUS NTAPI NtQueryInformationProcess(
	IN	HANDLE				ProcessHandle,
	IN	PROCESSINFOCLASS	ProcessInformationClass,
	OUT	PVOID				ProcessInformation,
	IN	ULONG				ProcessInformationLength,
	OUT	PULONG				ReturnLength OPTIONAL
	)
{
	if (NtQueryInformationProcessFn == NULL)
	{
		HMODULE hNtdll = GetModuleHandleW(L"ntdll.dll");
		if (!hNtdll)
			return -1;
		NtQueryInformationProcessFn = (NtQueryInformationProcessFn_T)GetProcAddress(hNtdll, "NtQueryInformationProcess");
	}
	return NtQueryInformationProcessFn(
		ProcessHandle,
		ProcessInformationClass,
		ProcessInformation,
		ProcessInformationLength,
		ReturnLength);
}