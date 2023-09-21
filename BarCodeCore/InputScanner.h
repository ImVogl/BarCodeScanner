#pragma once
#include "GuidStorage.h"

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
	void StartScanning(HINSTANCE hInstance);

	/// <summary>
	/// ������ ����������� ��������� �� �������� QR �����.
	/// </summary>
	void StartScanning();

private:

	/// <summary>
	/// ��������� ��������� ����������� �������.
	/// </summary>
	HHOOK pHook;

	/// <summary>
	/// ��������� ������ GUID, ���������� �� ��������.
	/// </summary>
	/// <param name="nCode">�������� hook ����.</param>
	/// <param name="actionType">��� �������������� ��������.</param>
	/// <param name="actionData">������ �������������� ��������.</param>
	/// <returns>��������� ���������� ���������.</returns>
	static LRESULT CALLBACK ScannerProc(int nCode, WPARAM actionType, LPARAM actionData);
};

