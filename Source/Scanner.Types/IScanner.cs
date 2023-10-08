namespace Scanner.Types
{
    using System;
    using JetBrains.Annotations;

    /// <summary>
    /// Интерфейс службы сканирования штрих кодов.
    /// </summary>
    public interface IScanner
    {
        /// <summary>
        /// Событие, генерируемое при сканировании штрих-кода.
        /// </summary>
        [CanBeNull]
        event EventHandler<Guid> Scanned;
    }
}