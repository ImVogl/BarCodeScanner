#include "pch.h"
#include "InputScanner.h"
#include "spdlog/spdlog.h"
#include "Logger.h"
#include <thread>

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

    InputScanner::pNotify = notification;
    this->pHook = SetWindowsHookEx(WH_KEYBOARD_LL, InputScanner::ScannerProc, hInstance, hThread);
    
    std::thread message_loop(&InputScanner::CreateMessageLoop);
    message_loop.detach();
}

void InputScanner::CreateMessageLoop()
{
    MSG msg = { };
    InputScanner::doProcess = true;
    if (doProcess)
        log("True");
    else
        log("False");

    while (doProcess)
    {
        log(GetMessage(&msg, NULL, NULL, NULL));
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    log("Leaved");
}

LRESULT CALLBACK InputScanner::ScannerProc(int nCode, WPARAM actionType, LPARAM actionData) {
    log("Procedure is called.");

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
    log(pKeyboard->vkCode);
    if (!(actionType == WM_KEYDOWN || actionType == WM_SYSKEYDOWN))
        return CallNextHookEx(NULL, nCode, actionType, actionData);
    
    switch (pKeyboard->vkCode) {
        case VK_RETURN:
            {
                log("Return pressed");
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
