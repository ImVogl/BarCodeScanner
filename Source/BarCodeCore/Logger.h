#pragma once
#include <iostream>
#include <fstream>

/// <summary>
/// ������������.
/// </summary>
/// <param name="text">����������� �����.</param>
static void log(const char* text)
{
    std::ofstream file("BarCode.log", std::ios_base::app);
    if (file.is_open())
        file << text << std::endl;

    file.close();
}

/// <summary>
/// ������������.
/// </summary>
/// <param name="value">����������� �����.</param>
static void log(const int value)
{
    std::ofstream file("BarCode.log", std::ios_base::app);
    if (file.is_open())
        file << value << std::endl;

    file.close();
}

/// <summary>
/// ������������.
/// </summary>
/// <param name="value">����������� �����.</param>
static void log(const DWORD value)
{
    std::ofstream file("BarCode.log", std::ios_base::app);
    if (file.is_open())
        file << value << std::endl;

    file.close();
}
