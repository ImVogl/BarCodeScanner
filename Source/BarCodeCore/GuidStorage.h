#pragma once
#include <vector>

/// <summary>
/// Хранилище GUID.
/// </summary>
class GuidStorage
{
public:

	/// <summary>
	/// Добавление нового символа в буффер.
	/// </summary>
	/// <param name="symbol">Добавляемый симвод.</param>
	/// <returns>Значение, показывающее, что симвод был успешно добавлен в буффер.</returns>
	bool AddSymbol(const WCHAR symbol);

	/// <summary>
	/// Чтение GUID из хранилища.
	/// </summary>
	/// <param name="buffer">Буфер, куда должен быть скопирован GUID.</param>
	/// <param name="size">Размер буфера.</param>
	/// <returns>Значение, показывающее, что удалось прочесть GUID.</returns>
	bool GetGuid(WCHAR* buffer, const USHORT size);

	/// <summary>
	/// Получение экземпляра класса.
	/// </summary>
	/// <returns>Экземпляр класса.</returns>
	static GuidStorage* GetInstance();

private:

	/// <summary>
	/// Констректор класса.
	/// </summary>
	GuidStorage() {}

	/// <summary>
	/// Размер буфера.
	/// </summary>
	const USHORT size = 36;

	/// <summary>
	/// Буфер, в котором хранятся перехваченные символы.
	/// </summary>
	std::vector<WCHAR> buffer = std::vector<WCHAR>(this->size, L'\0');

	/// <summary>
	/// Текущая позиция на запись.
	/// </summary>
	USHORT position = 0;
};

