namespace SessionLauncher.ViewModels
{
    using System.Windows.Interop;

    interface IWindowHandleReceiver
    {
        WindowInteropHelper Window { get; set; }
    }
}
