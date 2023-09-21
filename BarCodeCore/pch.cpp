// pch.cpp: source file corresponding to the pre-compiled header

#include "pch.h"
#include "InputScanner.h"
#define UNSUCCESS 1001;

__int32 CALLBACK ScanningSubscribe(Notification notification)
{
    if (notification == nullptr)
        return UNSUCCESS;

    InputScanner scanner;
    scanner.StartScanning(notification);

    return NULL;
}

__int32 CALLBACK ScanningSubscribe(HINSTANCE hInstance, Notification notification)
{
    if (notification == nullptr)
        return UNSUCCESS;

    InputScanner scanner;
    scanner.StartScanning(notification);

    return NULL;
}
