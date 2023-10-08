using System.Runtime.InteropServices;
using System.Text;

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
    /// <param name="content">Строка, возвращенная из метода.</param>
    [UnmanagedFunctionPointer(CallingConvention.StdCall, CharSet = CharSet.Unicode)]
    internal delegate void ScanGuid([MarshalAs(UnmanagedType.LPTStr)] string content);
}