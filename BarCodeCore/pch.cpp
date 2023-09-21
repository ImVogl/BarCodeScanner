// pch.cpp: source file corresponding to the pre-compiled header

#include "pch.h"
#include "InputScanner.h"
#define GUID_LENGTH 36;

size_t CALLBACK ScanningSubscribe(Notification notification)
{
    if (notification == nullptr)
        return NULL;

    InputScanner scanner;
    scanner.StartScanning(notification);

    return GUID_LENGTH;
}

size_t CALLBACK ScanningSubscribe(HINSTANCE hInstance, Notification notification)
{
    if (notification == nullptr)
        return NULL;

    InputScanner scanner;
    scanner.StartScanning(notification);

    return GUID_LENGTH;
}
