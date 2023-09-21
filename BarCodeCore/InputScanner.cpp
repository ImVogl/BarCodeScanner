#include "pch.h"
#include "InputScanner.h"
#include <windows.h>

void InputScanner::StartScanning(HINSTANCE hInstance)
{
    _pHook = SetWindowsHookEx(WH_KEYBOARD_LL, ScannerProc, hInstance, NULL);
}

void InputScanner::StartScanning()
{
    _pHook = SetWindowsHookEx(WH_KEYBOARD_LL, ScannerProc, NULL, NULL);
}

LRESULT CALLBACK InputScanner::ScannerProc(int nCode, WPARAM actionType, LPARAM actionData) {
    BYTE uKeyboardState[256];
    for (int i = 0; i < 256; ++i)
        uKeyboardState[i] = 0;

    const USHORT size = 1;
    WORD buffer[size];
    if (nCode == HC_ACTION) {
        KBDLLHOOKSTRUCT* pKeyboard = (KBDLLHOOKSTRUCT*)actionData;
        if (actionType == WM_KEYDOWN || actionType == WM_SYSKEYDOWN) {
            switch (pKeyboard->vkCode) {
            case VK_RETURN:
                break;
            default:
                ToAscii(pKeyboard->vkCode, pKeyboard->scanCode, uKeyboardState, buffer, size);
                GuidStorage::GetInstance()->AddSymbol(buffer[0]);
                break;
            }
        }
    }

    return CallNextHookEx(NULL, nCode, actionType, actionData);
}