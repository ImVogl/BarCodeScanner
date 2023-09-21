#pragma once
#include "GuidStorage.h"
#include "Notification.h"

class InputScanner
{
public:

	/// <summary>
	/// �����������.
	/// </summary>
	InputScanner() = default;

	/// <summary>
	/// ����������.
	/// </summary>
	~InputScanner()
	{
		UnhookWindowsHookEx(this->pHook);
	}

	/// <summary>
	/// ������ ����������� ��������� �� �������� QR �����.
	/// </summary>
	/// <param name="hInstance">��������� �� ������, ������� ����� ���������� ������� ��� ���������.</param>
	void StartScanning(HINSTANCE hInstance, Notification notification);

	/// <summary>
	/// ������ ����������� ��������� �� �������� QR �����.
	/// </summary>
	void StartScanning(Notification notification);

private:

	/// <summary>
	/// ��������� ��������� ����������� �������.
	/// </summary>
	HHOOK pHook;

	/// <summary>
	/// ������ �� �������, �����������, � ������������.
	/// </summary>
	static Notification pNotify;

	/// <summary>
	/// ��������� ������ GUID, ���������� �� ��������.
	/// </summary>
	/// <param name="nCode">�������� hook ����.</param>
	/// <param name="actionType">��� �������������� ��������.</param>
	/// <param name="actionData">������ �������������� ��������.</param>
	/// <returns>��������� ���������� ���������.</returns>
	static LRESULT CALLBACK ScannerProc(int nCode, WPARAM actionType, LPARAM actionData);
};

