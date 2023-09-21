// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#include "framework.h"
typedef void(__stdcall* Notification)(const WORD*);

/// <summary>
/// Подписка на сканирование GUID.
/// </summary>
/// <param name="notification">Ссылка на функцию, которая будет вызвана при сканировании GUID.</param>
/// <returns>Код выполнения подписки.</returns>
__int32 CALLBACK ScanningSubscribe(Notification notification);

/// <summary>
/// Подписка на сканирование GUID.
/// </summary>
/// <param name="hInstance">Ссылка на экземпляр окна, в котором будет осуществляться перехват событий.</param>
/// <param name="notification">Ссылка на функцию, которая будет вызвана при сканировании GUID.</param>
/// <returns>Код выполнения подписки.</returns>
__int32 CALLBACK ScanningSubscribe(HINSTANCE hInstance, Notification notification);

#endif //PCH_H
