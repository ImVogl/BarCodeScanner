#include "pch.h"
#include "GuidStorage.h"

bool GuidStorage::AddSymbol(const WCHAR symbol)
{
	const WCHAR dash_letter = 45;
	const WCHAR digit_low = 48;
	const WCHAR digit_up = 57;
	const WCHAR up_letter_low = 65;
	const WCHAR up_letter_up = 90;
	const WCHAR letter_low = 97;
	const WCHAR letter_up = 122;

	if (symbol == '\0')
		return false;

	if (symbol < digit_low && symbol != dash_letter)
		return false;

	if (symbol > digit_up && symbol < up_letter_low)
		return false;

	if (symbol > up_letter_up && symbol < letter_low)
		return false;

	if (symbol > letter_up)
		return false;

	this->buffer[this->position] = symbol;
	if (this->position < this->size - 1)
		++this->position;
	else
		this->position = 0;

	return true;
}

bool GuidStorage::GetGuid(WCHAR* buffer, const USHORT size)
{
	if (this->size > size)
		return false;

	for (auto i = 0; i < size; i++)
		buffer[i] = '\0';

	auto index = 0;
	for (auto i = this->position; i < this->size; i++)
	{
		if (this->buffer[i] == '\0')
			break;

		buffer[index++] = this->buffer[i];
	}

	for (auto i = 0; i < this->position; i++)
		buffer[index++] = this->buffer[i];

	return true;
}

GuidStorage* GuidStorage::GetInstance()
{
	static GuidStorage instance;
	return &instance;
}
