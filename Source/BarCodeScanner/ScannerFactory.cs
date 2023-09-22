using BarCodeScanner.Scanner;
using System.Reflection;

namespace BarCodeScanner;

/// <summary>
/// Фабрика, получения нужного экземпляра службы сканирования.
/// </summary>
public class ScannerFactory
{
    /// <summary>
    /// Размер указателя в ОС.
    /// </summary>
    private const int PointerSize = 4;

    /// <summary>
    /// Получение экземпляра службы сканирования.
    /// </summary>
    /// <returns>Экземпляр службы сканирования.</returns>
    public IBarCodeScanner Create()
    {
        return IntPtr.Size == PointerSize
            ? new BarCodeScannerX86()
            : new BarCodeScannerX64();
    }

    /// <summary>
    /// Получение экземпляра службы сканирования.
    /// </summary>
    /// <param name="module">Ссылка на модуль, который генерирует события.</param>
    /// <returns>Экземпляр службы сканирования.</returns>
    public IBarCodeScanner Create(Module module)
    {
        return IntPtr.Size == PointerSize
            ? new BarCodeScannerX86(module)
            : new BarCodeScannerX64(module);
    }
}