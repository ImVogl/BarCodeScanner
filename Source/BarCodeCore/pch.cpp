// pch.cpp: source file corresponding to the pre-compiled header

#include "pch.h"
#include "InputScanner.h"
#include "spdlog/spdlog.h"
#include "Logger.h"

#define GUID_LENGTH 36;

size_t CALLBACK Subscribe(Notification notification)
{
    if (notification == NULL)
        return NULL;

    InputScanner scanner;
    scanner.StartScanning(notification);
    return GUID_LENGTH;
}

size_t CALLBACK SubscribeThread(DWORD hThread, Notification notification)
{
    if (notification == NULL)
        return NULL;

    InputScanner scanner;
    scanner.StartScanning(hThread, notification);
    return GUID_LENGTH;
}

size_t CALLBACK SubscribeInstance(HINSTANCE hInstance, Notification notification)
{
    if (notification == NULL)
        return NULL;

    InputScanner scanner;
    scanner.StartScanning(hInstance, notification);
    return GUID_LENGTH;
}
