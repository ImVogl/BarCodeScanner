#include "pch.h"
#include "InputScanner.h"

void InputScanner::StartScanning(HINSTANCE hInstance, Notification notification)
{
    if (notification == nullptr)
        return;

    InputScanner::pNotify = notification;
    this->pHook = SetWindowsHookEx(WH_KEYBOARD_LL, InputScanner::ScannerProc, hInstance, NULL);
}

void InputScanner::StartScanning(Notification notification)
{
    if (notification == nullptr)
        return;

    InputScanner::pNotify = notification;
    this->pHook = SetWindowsHookEx(WH_KEYBOARD_LL, InputScanner::ScannerProc, NULL, NULL);
}

LRESULT CALLBACK InputScanner::ScannerProc(int nCode, WPARAM actionType, LPARAM actionData) {
    BYTE uKeyboardState[256];
    for (int i = 0; i < 256; ++i)
        uKeyboardState[i] = 0;

    const USHORT size = 1;
    const USHORT bufferSize = 36;

    WORD buffer[size];
    WORD resultBuffer[bufferSize];
    if (nCode != HC_ACTION)
        return CallNextHookEx(NULL, nCode, actionType, actionData);
    
    auto pKeyboard = (KBDLLHOOKSTRUCT*)actionData;
    if (actionType == WM_KEYDOWN || actionType == WM_SYSKEYDOWN) {
        switch (pKeyboard->vkCode) {
        case VK_RETURN:
            if (!GuidStorage::GetInstance()->GetGuid(resultBuffer, bufferSize))
                break;

            InputScanner::pNotify(resultBuffer);
            break;
        default:
            ToAscii(pKeyboard->vkCode, pKeyboard->scanCode, uKeyboardState, buffer, size);
            GuidStorage::GetInstance()->AddSymbol(buffer[0]);
            break;
        }
    }
    
    return CallNextHookEx(NULL, nCode, actionType, actionData);
}