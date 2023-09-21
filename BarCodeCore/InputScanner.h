#pragma once
#include "GuidStorage.h"

class InputScanner
{
public:
	/// <summary>
	/// Запуск обработчика сообщений от сканнера QR кодов.
	/// </summary>
	/// <param name="hInstance">Указатель на модуль, который будет источником событий для обработки.</param>
	void StartScanning(HINSTANCE hInstance);

	/// <summary>
	/// Запуск обработчика сообщений от сканнера QR кодов.
	/// </summary>
	void StartScanning();

private:

	/// <summary>
	/// Указатель экземпляр перехватчик событий.
	/// </summary>
	HHOOK _pHook;

	/// <summary>
	/// Процедура чтения GUID, полученных от сканнера.
	/// </summary>
	/// <param name="nCode">Значение hook кода.</param>
	/// <param name="actionType">Тип перехваченного действия.</param>
	/// <param name="actionData">Данные перехваченного действия.</param>
	/// <returns>Результат выполнения процедуры.</returns>
	static LRESULT CALLBACK ScannerProc(int nCode, WPARAM actionType, LPARAM actionData);
};

