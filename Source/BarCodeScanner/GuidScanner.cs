using System.Runtime.InteropServices;

namespace BarCodeScanner
{
    /// <summary>
    /// Служба сканирования GUID из штрих-кодов.
    /// </summary>
    public sealed class GuidScanner : IScanner
    {
        /// <summary>
        /// Инициализирует новый экземпляр <see cref="GuidScanner"/>.
        /// </summary>
        public GuidScanner()
        {
            Subscribe(ScanInternal);
        }

        /// <summary>
        /// Инициализирует новый экземпляр <see cref="GuidScanner"/>.
        /// </summary>
        /// <param name="threadId">Идентификатор потока, с которым будет ассоциирован вызов перехватчика.</param>
        public GuidScanner(int threadId)
        {
            SubscribeInstance(threadId, ScanInternal);
        }

        /// <inheritdoc cref="IScanner.Scanned"/>.
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
        private static extern UIntPtr Subscribe(IScanner.ScanGuid scan);

        /// <summary>
        /// Подписка на сканирование GUID.
        /// </summary>
        /// <param name="threadId">Идентификатор потока, с которым будет ассоциирован вызов перехватчика.</param>
        /// <param name="scan">Делегат метода, вызываемого при сканировании GUID.</param>
        /// <returns>Число сканированных символов.</returns>
        [DllImport("BarCodeCore", CallingConvention = CallingConvention.StdCall)]
        private static extern UIntPtr SubscribeInstance(int threadId, IScanner.ScanGuid scan);
    }
}