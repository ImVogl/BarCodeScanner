#pragma once
#include "GuidStorage.h"
#include "Notification.h"

class InputScanner
{
public:

	/// <summary>
	/// Конструктор.
	/// </summary>
	InputScanner() = default;

	/// <summary>
	/// Деструктор.
	/// </summary>
	~InputScanner()
	{
		UnhookWindowsHookEx(this->pHook);
	}

	/// <summary>
	/// Запуск обработчика сообщений от сканнера QR кодов.
	/// </summary>
	/// <param name="hInstance">Указатель на модуль, который будет источником событий для обработки.</param>
	void StartScanning(HINSTANCE hInstance, Notification notification);

	/// <summary>
	/// Запуск обработчика сообщений от сканнера QR кодов.
	/// </summary>
	void StartScanning(Notification notification);

private:

	/// <summary>
	/// Указатель экземпляр перехватчик событий.
	/// </summary>
	HHOOK pHook;

	/// <summary>
	/// Ссылка на функцию, оповещающую, о сканировании.
	/// </summary>
	static Notification pNotify;

	/// <summary>
	/// Процедура чтения GUID, полученных от сканнера.
	/// </summary>
	/// <param name="nCode">Значение hook кода.</param>
	/// <param name="actionType">Тип перехваченного действия.</param>
	/// <param name="actionData">Данные перехваченного действия.</param>
	/// <returns>Результат выполнения процедуры.</returns>
	static LRESULT CALLBACK ScannerProc(int nCode, WPARAM actionType, LPARAM actionData);
};

