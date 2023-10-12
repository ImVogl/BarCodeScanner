using System;

namespace BarCodeScannerWpf
{
    /// <summary>
    /// Хранилище GUID.
    /// </summary>
    public class GuidStorage
    {
        /// <summary>
        /// Размер буфера, где хранятся введенные значения.
        /// </summary>
        private const int BufferSize = 36;

        /// <summary>
        /// Буфер, где хранятся добавленные значения.
        /// </summary>
        private readonly char[] _buffer = new char[BufferSize];

        /// <summary>
        /// Текущая позиция в буфере.
        /// </summary>
        private int _position;

        /// <summary>
        /// Инициализирует новый экземпляр <see cref="GuidStorage"/>.
        /// </summary>
        public GuidStorage()
        {
            for (var i = 0; i < BufferSize; i++)
                _buffer[i] = '\0';
        }

        /// <summary>
        /// Добавление символа в хранилище.
        /// </summary>
        /// <param name="symbol">Добавляемый символ.</param>
        public void Add(char symbol)
        {
            _buffer[_position] = symbol;
            if (_position < BufferSize - 1)
                ++_position;
            else
                _position = 0;
        }

        /// <summary>
        /// Получение GUID из хранилища.
        /// </summary>
        /// <returns>GUID или null, если не удалось получить GUID.</returns>
        public Guid? GetGuid()
        {
            var buffer = new char[BufferSize];
            var index = 0;
            for (var i = _position; i < BufferSize; i++)
            {
                if (_buffer[i] == '\0')
                    return null;

                buffer[index++] = _buffer[i];
            }

            for (var i = 0; i < _position; i++)
                buffer[index++] = _buffer[i];

            if (Guid.TryParse(new string(buffer), out var result))
                return result;

            return null;
        }
    }
}