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
    RpcCoreHelper.RpcCoreGetProcessInfoFn(pRpcCoreCtxt, Pid, Ppid, ProcessInfoMask);

    std::cout << "Hello World!\n";

    getchar();
}