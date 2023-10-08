namespace BarCodeScanner
{
    using System.Runtime.InteropServices;
    using Scanner.Types;

    /// <summary>
    /// Делегат метода сканирования штрих кода
    /// </summary>
    /// <param name="content">Строка, возвращенная из метода.</param>
    [UnmanagedFunctionPointer(CallingConvention.StdCall, CharSet = CharSet.Unicode)]
    internal delegate void ScanGuid([MarshalAs(UnmanagedType.LPTStr)] string content);

    /// <summary>
    /// Интерфейс службы сканирования штрих кодов.
    /// </summary>
    public interface INativeScanner : IScanner
    {
    }
}