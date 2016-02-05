namespace SessionLauncher
{
    using System;
    using System.Windows;
    using ViewModels;

    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            this.DataContextChanged += this.OnDataContextChanged;
            this.Loaded += this.OnLoaded;
        }

        protected override void OnClosed(EventArgs e)
        {
            IDisposable viewModel = this.DataContext as IDisposable;

            if (null != viewModel)
                viewModel.Dispose();

            base.OnClosed(e);
        }

        private void OnDataContextChanged(object sender, DependencyPropertyChangedEventArgs e)
        {
            IWindowHandleReceiver receiver = e.OldValue as IWindowHandleReceiver;

            if (null != receiver)
                receiver.Window = null;

            receiver = e.NewValue as IWindowHandleReceiver;

            if (null != receiver)
                receiver.Window = new System.Windows.Interop.WindowInteropHelper(this);
        }

        private void OnLoaded(object sender, RoutedEventArgs e)
        {
            IWindowHandleReceiver receiver = this.DataContext as IWindowHandleReceiver;

            if (null != receiver)
                receiver.Window = new System.Windows.Interop.WindowInteropHelper(this);
        }
    }
}
