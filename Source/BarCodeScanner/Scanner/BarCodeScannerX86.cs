using System.Reflection;
using System.Runtime.InteropServices;

namespace BarCodeScanner.Scanner
{
    /// <summary>
    /// Служба сканирования штрих-кодов под операционный системы разрядностью x86.
    /// </summary>
    internal sealed class BarCodeScannerX86 : BarCodeScannerBase
    {
        /// <summary>
        /// Инициализирует новый экземпляр <see cref="BarCodeScannerX86"/>.
        /// </summary>
        internal BarCodeScannerX86()
        {
            Subscribe(ScanInternal);
        }

        /// <summary>
        /// Инициализирует новый экземпляр <see cref="BarCodeScannerX86"/>.
        /// </summary>
        /// <param name="module">Ссылка на модуль, который генерирует события.</param>
        internal BarCodeScannerX86(Module module)
        {
            SubscribeInstance(module, ScanInternal);
        }
        
        /// <summary>
        /// Подписка на сканирование GUID.
        /// </summary>
        /// <param name="scan">Делегат метода, вызываемого при сканировании GUID.</param>
        /// <returns>Число сканированных символов.</returns>
        [DllImport("BarCodeCore", CallingConvention = CallingConvention.StdCall)]
        private static extern UIntPtr Subscribe(IBarCodeScanner.ScanGuid scan);

        /// <summary>
        /// Подписка на сканирование GUID.
        /// </summary>
        /// <param name="module">Ссылка на модуль, который генерирует события.</param>
        /// <param name="scan">Делегат метода, вызываемого при сканировании GUID.</param>
        /// <returns>Число сканированных символов.</returns>
        [DllImport("BarCodeCore", CallingConvention = CallingConvention.StdCall)]
        private static extern UIntPtr SubscribeInstance(Module module, IBarCodeScanner.ScanGuid scan);
    }
}