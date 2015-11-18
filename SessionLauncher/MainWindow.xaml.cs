namespace SessionLauncher
{
    using System;
    using System.Windows;
    using System.Windows.Interop;

    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private SessionHelper.Kielbasa _kielbasa;

        public MainWindow()
        {
            InitializeComponent();
            _kielbasa = SessionHelper.Kielbasa.Create(new WindowInteropHelper(this));
        }

        protected override void OnClosed(EventArgs e)
        {
            _kielbasa.Dispose();
            base.OnClosed(e);
        }
    }
}
