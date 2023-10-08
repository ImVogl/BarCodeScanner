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
		InputScanner::doProcess = false;
	}

	/// <summary>
	/// ������ ����������� ��������� �� �������� QR �����.
	/// </summary>
	/// <param name="hInstance">���������� ������, � ������� ����� ������������� ����������� ���������.</param>
	void StartScanning(HINSTANCE hInstance, Notification notification);

	/// <summary>
	/// ������ ����������� ��������� �� �������� QR �����.
	/// </summary>
	/// <param name="hThread">��������� �� �����, � ������� ����� ������������� ����������� ���������.</param>
	void StartScanning(DWORD hThread, Notification notification);

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
	/// ��������, ������������, ��� ����� ������������ ��������� ���������.
	/// </summary>
	static bool doProcess;

	/// <summary>
	/// ��������� ������ GUID, ���������� �� ��������.
	/// </summary>
	/// <param name="nCode">�������� hook ����.</param>
	/// <param name="actionType">��� �������������� ��������.</param>
	/// <param name="actionData">������ �������������� ��������.</param>
	/// <returns>��������� ���������� ���������.</returns>
	static LRESULT CALLBACK ScannerProc(int nCode, WPARAM actionType, LPARAM actionData);

	/// <summary>
	/// ������ ����������� ��������� �� �������� QR �����.
	/// </summary>
	/// <param name="hInstance">���������� ������, � ������� ����� ������������� ����������� ���������.</param>
	/// <param name="hThread">��������� �� �����, � ������� ����� ������������� ����������� ���������.</param>
	/// <param name="notification">��������� �� �����, ����������� ��� ��������� ������� �� Enter.</param>
	void StartScanningInternal(HINSTANCE hInstance, DWORD hThread, Notification notification);
};

