// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        spdlog::set_level(spdlog::level::debug);
        spdlog::basic_logger_mt("file_logger", "logs/barcode.log", true);
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        spdlog::shutdown();
        break;
    }

    return TRUE;
}
