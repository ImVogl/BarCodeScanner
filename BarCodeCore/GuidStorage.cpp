#include "pch.h"
#include "GuidStorage.h"

bool GuidStorage::AddSymbol(WORD symbol)
{
	const WORD digit_low = 48;
	const WORD digit_up = 57;
	const WORD up_letter_low = 65;
	const WORD up_letter_up = 90;
	const WORD letter_low = 97;
	const WORD letter_up = 122;

	if (symbol == '\0')
		return false;

	if (symbol < digit_low)
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

	return true;;
}

bool GuidStorage::GetGuid(WORD* buffer, USHORT size)
{
	if (this->size > size)
		return false;
	
	auto index = 0;
	for (auto i = this->position; i < this->size && this->buffer[i] != '\0'; i++)
		buffer[++index] = this->buffer[i];

	for (auto i = 0; i < this->position; i++)
		buffer[++index] = this->buffer[i];

	return true;
}

GuidStorage* GuidStorage::GetInstance()
{
	static GuidStorage instance;
	return &instance;
}
