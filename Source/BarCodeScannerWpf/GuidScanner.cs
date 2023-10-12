using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Interop;

namespace BarCodeScannerWpf
{
    /// <summary>
    /// Служба сканирования GUID из штрих-кодов.
    /// </summary>
    public sealed class GuidScanner : IWpfScanner
    {
        /// <summary>
        /// Код сообщения, обозначающее, что была нажата кнопка.
        /// </summary>
        private const int WmKeyDown = 0x0100;

        /// <summary>
        /// Код сообщения, обозначающее, что была нажата системная кнопка.
        /// </summary>
        private const int WmSysKeyDown = 0x0104;

        /// <summary>
        /// Код клавиши Enter.
        /// </summary>
        private const int VkReturn = 0x0D;

        /// <summary>
        /// Код клавиши "Тире".
        /// </summary>
        private const int Dash = 0x0BD;

        /// <summary>
        /// Список с подходящими символами.
        /// </summary>
        private readonly IList<int> _suitableCharacters = Enumerable.Range(32, 125).ToList();

        /// <summary>
        /// Буфер с введенными символами.
        /// </summary>
        private readonly GuidStorage _storage = new GuidStorage();

        /// <summary>
        /// Инициализирует новый экземпляр обработчика сообщений.
        /// </summary>
        public GuidScanner()
        {
            _suitableCharacters.Add(VkReturn);
            _suitableCharacters.Add(Dash);
            ComponentDispatcher.ThreadFilterMessage += ProcessMessage;
        }

        /// <inheritdoc cref="IWpfScanner.Scanned"/>.
        public event EventHandler<Guid> Scanned;

        /// <summary>
        /// Освобождение занятых ресурсов.
        /// </summary>
        public void Dispose()
        {
            ComponentDispatcher.ThreadFilterMessage -= ProcessMessage;
        }

        /// <summary>
        /// Обработка поступивших сообщений.
        /// </summary>
        /// <param name="msg">Сообщение из очереди сообщений UI.</param>
        /// <param name="handled">Значение, показывающее, что сообщение было обработано.</param>
        private void ProcessMessage(ref MSG msg, ref bool handled)
        {
            if (handled || msg.message != WmKeyDown && msg.message != WmSysKeyDown)
                return;

            var keyCode = msg.wParam.ToInt32();
            if (!_suitableCharacters.Contains(keyCode))
                return;

            handled = true;
            if (keyCode != VkReturn)
            {
                _storage.Add(keyCode != Dash ? Convert.ToChar(keyCode) : '-');
                return;
            }

            var guid = _storage.GetGuid();
            if (guid == null)
                return;

            var handler = Scanned;
            handler?.Invoke(this, (Guid)guid);
        }
    }
}