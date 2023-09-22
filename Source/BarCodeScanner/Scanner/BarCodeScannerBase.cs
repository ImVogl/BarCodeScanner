namespace BarCodeScanner.Scanner;

/// <summary>
/// Базовый класс службы сканирования штрих-кодов.
/// </summary>
internal abstract class BarCodeScannerBase : IBarCodeScanner
{
    /// <inheritdoc cref="IBarCodeScanner.Scanned"/>.
    public event EventHandler<Guid>? Scanned;

    /// <summary>
    /// Обработка результатов сканирования.
    /// </summary>
    /// <param name="value">Значение, полученное в результате сканирования.</param>
    protected void ScanInternal(string value)
    {
        if (!Guid.TryParse(value, out var id))
            return;

        var handler = Scanned;
        handler?.Invoke(this, id);
    }
}