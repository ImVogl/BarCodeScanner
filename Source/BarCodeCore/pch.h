// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#include "framework.h"
#include "Notification.h"

/// <summary>
/// Подписка на сканирование GUID.
/// </summary>
/// <param name="notification">Ссылка на функцию, которая будет вызвана при сканировании GUID.</param>
/// <returns>Код выполнения подписки.</returns>
extern "C" __declspec(dllexport) size_t CALLBACK Subscribe(Notification notification);

/// <summary>
/// Подписка на сканирование GUID.
/// </summary>
/// <param name="threadId">Идентификатор потока, с которым будет ассоциирован вызов перехватчика.</param>
/// <param name="notification">Ссылка на функцию, которая будет вызвана при сканировании GUID.</param>
/// <returns>Код выполнения подписки.</returns>
extern "C" __declspec(dllexport) size_t CALLBACK SubscribeThread(DWORD hThread, Notification notification);

/// <summary>
/// Подписка на сканирование GUID.
/// </summary>
/// <param name="hInstance">Дескриптор модуля, с которым будет ассоциирована исполняемая процедура.</param>
/// <param name="notification">Ссылка на функцию, которая будет вызвана при сканировании GUID.</param>
/// <returns>Код выполнения подписки.</returns>
extern "C" __declspec(dllexport) size_t CALLBACK SubscribeInstance(HINSTANCE hInstance, Notification notification);

#endif //PCH_H
