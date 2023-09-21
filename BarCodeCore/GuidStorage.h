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
	bool AddSymbol(WORD symbol);

	/// <summary>
	/// ������ GUID �� ���������.
	/// </summary>
	/// <param name="buffer">�����, ���� ������ ���� ���������� GUID.</param>
	/// <param name="size">������ ������.</param>
	/// <returns>��������, ������������, ��� ������� �������� GUID.</returns>
	bool GetGuid(WORD* buffer, USHORT size);

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
	std::vector<WORD> buffer = std::vector<WORD>(this->size, L'\0');

	/// <summary>
	/// ������� ������� �� ������.
	/// </summary>
	USHORT position = 0;
};

