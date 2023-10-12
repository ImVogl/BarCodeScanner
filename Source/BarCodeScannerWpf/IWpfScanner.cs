using JetBrains.Annotations;
using System;

namespace BarCodeScannerWpf
{
    /// <summary>
    /// Интерфейс службы сканирования штрих кодов.
    /// </summary>
    public interface IWpfScanner : IDisposable
    {
        /// <summary>
        /// Событие, генерируемое при сканировании штрих-кода.
        /// </summary>
        [CanBeNull]
        event EventHandler<Guid> Scanned;
    }
}