// pch.cpp: source file corresponding to the pre-compiled header

#include "pch.h"
#include "InputScanner.h"
#define GUID_LENGTH 36;

__int32 CALLBACK ScanningSubscribe(Notification notification)
{
    if (notification == nullptr)
        return NULL;

    InputScanner scanner;
    scanner.StartScanning(notification);

    return GUID_LENGTH;
}

__int32 CALLBACK ScanningSubscribe(HINSTANCE hInstance, Notification notification)
{
    if (notification == nullptr)
        return NULL;

    InputScanner scanner;
    scanner.StartScanning(notification);

    return GUID_LENGTH;
}
