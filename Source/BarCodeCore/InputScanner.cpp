#include "pch.h"
#include "InputScanner.h"
#include "spdlog/spdlog.h"

Notification InputScanner::pNotify = nullptr;
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
    const USHORT keys_count = 256;
    BYTE uKeyboardState[keys_count];
    for (int i = 0; i < keys_count; ++i)
        uKeyboardState[i] = 0;

    const USHORT size = 4;
    const USHORT bufferSize = 72;

    WCHAR buffer[size];
    WCHAR resultBuffer[bufferSize];
    if (nCode != HC_ACTION)
        return CallNextHookEx(NULL, nCode, actionType, actionData);

    auto pKeyboard = (KBDLLHOOKSTRUCT*)actionData;
    if (!(actionType == WM_KEYDOWN || actionType == WM_SYSKEYDOWN))
        return CallNextHookEx(NULL, nCode, actionType, actionData);
    
    switch (pKeyboard->vkCode) {
        case VK_RETURN:
            if (!GuidStorage::GetInstance()->GetGuid(resultBuffer, bufferSize))
                break;

            spdlog::debug("Recieved message:");
            // spdlog::debug(resultBuffer);
            InputScanner::pNotify(resultBuffer);
            break;
        default:
            ToUnicode(pKeyboard->vkCode, pKeyboard->scanCode, uKeyboardState, buffer, size, NULL);
            GuidStorage::GetInstance()->AddSymbol(buffer[0]);
            break;
        }

    return CallNextHookEx(NULL, nCode, actionType, actionData);
}