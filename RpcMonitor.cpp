// RpcMonitor.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "RpcCore/RpcCore.h"

#ifdef __cplusplus
extern "C" {
#endif

    extern    RpcCore_T	RpcCoreHelper;

#ifdef __cplusplus
}
#endif

typedef struct _EnumCtxt_T {
    void* pRpcCoreCtxt;
    RpcCore_T* pRpcCore;
}EnumCtxt_T;

static BOOL __fastcall EnumInterfaces(RpcInterfaceInfo_T* pRpcInterfaceInfo, EnumCtxt_T* pEnumCtxt, BOOL* pbContinue)
{
    return TRUE;
}

int main()
{
    /*
    void* pRpcCoreCtxt, DWORD Pid, DWORD Ppid,ULONG ProcessInfoMask
    */
    void* pRpcCoreCtxt;
    pRpcCoreCtxt = RpcCoreHelper.RpcCoreInitFn(true);
    DWORD Pid = 33084;
    // DWORD Ppid = 22112;
    DWORD Ppid = 0;
    ULONG ProcessInfoMask = RPC_PROCESS_INFO_ALL;
    RpcProcessInfo_T* pRpcProcessInfo;
    EnumCtxt_T				EnumCtxt = { 0 };
    EnumCtxt.pRpcCore = &RpcCoreHelper;
    EnumCtxt.pRpcCoreCtxt = RpcCoreHelper.RpcCoreInitFn(FALSE);
    pRpcProcessInfo = RpcCoreHelper.RpcCoreGetProcessInfoFn(pRpcCoreCtxt, Pid, Ppid, ProcessInfoMask);
    RpcCoreHelper.RpcCoreFreeProcessInfoFn(pRpcCoreCtxt, pRpcProcessInfo);
    RpcCoreHelper.RpcCoreEnumProcessInterfacesFn(pRpcCoreCtxt, Pid, (RpcCoreEnumProcessInterfacesCallbackFn_T)&EnumInterfaces, &EnumCtxt, RPC_INTERFACE_INFO_ALL);


    std::cout << "Hello World!\n";

    getchar();
}