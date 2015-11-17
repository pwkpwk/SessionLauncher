namespace SessionLauncher
{
    using System.Windows;

    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private SessionHelper.Kielbasa _kielbasa;

        public MainWindow()
        {
            InitializeComponent();
            _kielbasa = new SessionHelper.Kielbasa();
        }
    }
}
