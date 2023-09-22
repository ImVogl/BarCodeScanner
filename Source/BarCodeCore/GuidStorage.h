#pragma once
#include <vector>

/// <summary>
/// ��������� GUID.
/// </summary>
class GuidStorage
{
public:

	/// <summary>
	/// ���������� ������ ������� � ������.
	/// </summary>
	/// <param name="symbol">����������� ������.</param>
	/// <returns>��������, ������������, ��� ������ ��� ������� �������� � ������.</returns>
	bool AddSymbol(const WCHAR symbol);

	/// <summary>
	/// ������ GUID �� ���������.
	/// </summary>
	/// <param name="buffer">�����, ���� ������ ���� ���������� GUID.</param>
	/// <param name="size">������ ������.</param>
	/// <returns>��������, ������������, ��� ������� �������� GUID.</returns>
	bool GetGuid(WCHAR* buffer, const USHORT size);

	/// <summary>
	/// ��������� ���������� ������.
	/// </summary>
	/// <returns>��������� ������.</returns>
	static GuidStorage* GetInstance();

private:

	/// <summary>
	/// ����������� ������.
	/// </summary>
	GuidStorage() {}

	/// <summary>
	/// ������ ������.
	/// </summary>
	const USHORT size = 36;

	/// <summary>
	/// �����, � ������� �������� ������������� �������.
	/// </summary>
	std::vector<WCHAR> buffer = std::vector<WCHAR>(this->size, L'\0');

	/// <summary>
	/// ������� ������� �� ������.
	/// </summary>
	USHORT position = 0;
};

