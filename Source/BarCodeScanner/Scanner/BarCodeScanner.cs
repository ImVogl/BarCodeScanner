using System.Reflection;
using System.Runtime.InteropServices;

namespace BarCodeScanner.Scanner
{
    /// <summary>
    /// Служба сканирования штрих-кодов под операционный системы разрядностью x86.
    /// </summary>
    public sealed class BarCodeScanner : IBarCodeScanner
    {
        /// <summary>
        /// Инициализирует новый экземпляр <see cref="BarCodeScanner"/>.
        /// </summary>
        public BarCodeScanner()
        {
            Subscribe(ScanInternal);
        }

        /// <summary>
        /// Инициализирует новый экземпляр <see cref="BarCodeScanner"/>.
        /// </summary>
        /// <param name="module">Ссылка на модуль, который генерирует события.</param>
        internal BarCodeScanner(Module module)
        {
            SubscribeInstance(module, ScanInternal);
        }

        /// <inheritdoc cref="IBarCodeScanner.Scanned"/>.
        public event EventHandler<Guid>? Scanned;

        /// <summary>
        /// Обработка результатов сканирования.
        /// </summary>
        /// <param name="value">Значение, полученное в результате сканирования.</param>
        private void ScanInternal(string value)
        {
            if (!Guid.TryParse(value, out var id))
                return;

            var handler = Scanned;
            handler?.Invoke(this, id);
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