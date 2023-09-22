using System.Runtime.InteropServices;

namespace BarCodeScanner.Scanner;

/// <summary>
/// Интерфейс службы сканирования GUID из штрих кодов.
/// </summary>
public interface IBarCodeScanner
{
    /// <summary>
    /// Событие, генерируемое при сканировании штрих-кода.
    /// </summary>
    event EventHandler<Guid>? Scanned;

    /// <summary>
    /// Делегат метода сканирования штрих кода
    /// </summary>
    /// <param name="guid">GUID, полученный в результате сканирования.</param>
    [UnmanagedFunctionPointer(CallingConvention.StdCall, CharSet = CharSet.Ansi)]
    internal delegate void ScanGuid(string guid);
}