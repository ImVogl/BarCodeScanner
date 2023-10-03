using System.Runtime.InteropServices;

namespace BarCodeScanner;

/// <summary>
/// Интерфейс службы сканирования штрих кодов.
/// </summary>
public interface IScanner
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