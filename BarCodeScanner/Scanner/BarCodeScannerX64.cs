using System.Reflection;
using System.Runtime.InteropServices;

namespace BarCodeScanner.Scanner
{
    /// <summary>
    /// Служба сканирования штрих-кодов под операционный системы разрядностью x64.
    /// </summary>
    internal sealed class BarCodeScannerX64 : BarCodeScannerBase
    {
        /// <summary>
        /// Инициализирует новый экземпляр <see cref="BarCodeScannerX64"/>.
        /// </summary>
        internal BarCodeScannerX64()
        {
            ScanningSubscribe(ScanInternal);
        }

        /// <summary>
        /// Инициализирует новый экземпляр <see cref="BarCodeScannerX64"/>.
        /// </summary>
        /// <param name="module">Ссылка на модуль, который генерирует события.</param>
        internal BarCodeScannerX64(Module module)
        {
            ScanningSubscribe(module, ScanInternal);
        }
        
        /// <summary>
        /// Подписка на сканирование GUID.
        /// </summary>
        /// <param name="scan">Делегат метода, вызываемого при сканировании GUID.</param>
        /// <returns>Число сканированных символов.</returns>
        [DllImport("CrossPlatformLibrary-x64", CallingConvention = CallingConvention.StdCall)]
        private static extern UIntPtr ScanningSubscribe(IBarCodeScanner.ScanGuid scan);

        /// <summary>
        /// Подписка на сканирование GUID.
        /// </summary>
        /// <param name="module">Ссылка на модуль, который генерирует события.</param>
        /// <param name="scan">Делегат метода, вызываемого при сканировании GUID.</param>
        /// <returns>Число сканированных символов.</returns>
        [DllImport("CrossPlatformLibrary-x64", CallingConvention = CallingConvention.StdCall)]
        private static extern UIntPtr ScanningSubscribe(Module module, IBarCodeScanner.ScanGuid scan);
    }
}