﻿using System.Reflection;
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
        public GuidScanner(uint threadId)
        {
            SubscribeThread(threadId, ScanInternal);
        }

        /// <summary>
        /// Инициализирует новый экземпляр <see cref="GuidScanner"/>.
        /// </summary>
        /// <param name="module">Модуль, который содержит код исполняемой процедуры.</param>
        public GuidScanner(Module module)
        {
            Marshal.GetHINSTANCE(module);
            SubscribeInstance(Marshal.GetHINSTANCE(module), ScanInternal);
        }

        /// <inheritdoc cref="IScanner.Scanned"/>.
        public event EventHandler<Guid>? Scanned;

        /// <summary>
        /// Обработка результатов сканирования.
        /// </summary>
        /// <param name="value">Строка, возвращенная из метода.</param>
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
        private static extern UIntPtr Subscribe([MarshalAs(UnmanagedType.FunctionPtr)] IScanner.ScanGuid scan);

        /// <summary>
        /// Подписка на сканирование GUID.
        /// </summary>
        /// <param name="threadId">Идентификатор потока, с которым будет ассоциирован вызов перехватчика.</param>
        /// <param name="scan">Делегат метода, вызываемого при сканировании GUID.</param>
        /// <returns>Число сканированных символов.</returns>
        [DllImport("BarCodeCore", CallingConvention = CallingConvention.StdCall)]
        private static extern UIntPtr SubscribeThread(uint threadId, [MarshalAs(UnmanagedType.FunctionPtr)] IScanner.ScanGuid scan);

        /// <summary>
        /// Подписка на сканирование GUID.
        /// </summary>
        /// <param name="handle">Дескриптор модуля, который содержит код исполняемой процедуры.</param>
        /// <param name="scan">Делегат метода, вызываемого при сканировании GUID.</param>
        /// <returns>Число сканированных символов.</returns>
        [DllImport("BarCodeCore", CallingConvention = CallingConvention.StdCall)]
        private static extern UIntPtr SubscribeInstance(IntPtr handle, [MarshalAs(UnmanagedType.FunctionPtr)] IScanner.ScanGuid scan);
    }
}
