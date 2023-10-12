#include "pch.h"
#include "InputScanner.h"
#include "spdlog/spdlog.h"
#include "Logger.h"

bool InputScanner::doProcess = false;
Notification InputScanner::pNotify = nullptr;
void InputScanner::StartScanning(Notification notification)
{
    this->StartScanningInternal(NULL, NULL, notification);
}

void InputScanner::StartScanning(DWORD hThread, Notification notification)
{
    this->StartScanningInternal(NULL, hThread, notification);
}

void InputScanner::StartScanning(HINSTANCE hInstance, Notification notification)
{
    this->StartScanningInternal(hInstance, NULL, notification);
}

void InputScanner::StartScanningInternal(HINSTANCE hInstance, DWORD hThread, Notification notification)
{
    if (notification == nullptr)
        return;

    MSG msg = { };
    InputScanner::doProcess = true;
    InputScanner::pNotify = notification;
    this->pHook = SetWindowsHookEx(WH_KEYBOARD_LL, InputScanner::ScannerProc, hInstance, hThread);
    while (doProcess)
    {
        log(GetMessage(&msg, NULL, NULL, NULL));
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
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

    if (!(actionType == WM_KEYDOWN || actionType == WM_SYSKEYDOWN))
        return CallNextHookEx(NULL, nCode, actionType, actionData);

    auto pKeyboard = (KBDLLHOOKSTRUCT*)actionData;
    switch (pKeyboard->vkCode) {
        case VK_RETURN:
            {
                if (!GuidStorage::GetInstance()->GetGuid(resultBuffer, bufferSize))
                    break;

                InputScanner::pNotify(resultBuffer);
                break;
            }
        default:
            {
                ToUnicode(pKeyboard->vkCode, pKeyboard->scanCode, uKeyboardState, buffer, size, NULL);
                GuidStorage::GetInstance()->AddSymbol(buffer[0]);
                break;
            }
        }

    return CallNextHookEx(NULL, nCode, actionType, actionData);
}
