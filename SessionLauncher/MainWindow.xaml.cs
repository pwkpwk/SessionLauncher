namespace SessionLauncher
{
    using System;
    using System.Windows;

    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        protected override void OnClosed(EventArgs e)
        {
            IDisposable viewModel = this.DataContext as IDisposable;

            if (null != viewModel)
                viewModel.Dispose();

            base.OnClosed(e);
        }
    }
}
