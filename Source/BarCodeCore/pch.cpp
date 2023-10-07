// pch.cpp: source file corresponding to the pre-compiled header

#include "pch.h"
#include "InputScanner.h"
#include "spdlog/spdlog.h"

#define GUID_LENGTH 36;

size_t CALLBACK Subscribe(Notification notification)
{
    spdlog::debug("Simple Subscribtion");
    if (notification == nullptr)
        return NULL;

    InputScanner scanner;
    scanner.StartScanning(notification);
    return GUID_LENGTH;
}

size_t CALLBACK SubscribeInstance(DWORD hThread, Notification notification)
{
    spdlog::debug("Instance Subscribtion");
    if (notification == nullptr)
        return NULL;

    InputScanner scanner;
    scanner.StartScanning(hThread, notification);
    return GUID_LENGTH;
}
