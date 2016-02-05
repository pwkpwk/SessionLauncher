namespace SessionLauncher
{
    using SessionHelper;
    using System;
    using System.Windows.Input;
    using ViewModels;
    using System.Windows.Interop;
    using System.Threading.Tasks;
    sealed class MainWindowViewModel : IDisposable, IWindowHandleReceiver
    {
        private sealed class Command : ICommand
        {
            private readonly Action<object> _execute;
            private readonly Predicate<object> _canExecute;

            public Command(Action<object> execute, Predicate<object> canExecute = null)
            {
                _execute = execute;
                _canExecute = canExecute;
            }

            public event EventHandler CanExecuteChanged;

            public bool CanExecute(object parameter)
            {
                return null == _canExecute ? true : _canExecute(parameter);
            }

            public void Execute(object parameter)
            {
                _execute(parameter);
            }

            public void EmitCanExecuteChanged()
            {
                this.CanExecuteChanged?.Invoke(this, EventArgs.Empty);
            }
        }

        private bool _disposedValue;
        private readonly Command _launchSession, _showThreadWindow, _deleteThreadWindow, _authenticate, _launchApplication;
        private readonly Kielbasa _kielbasa;
        private string _serverName;
        private ThreadWindow _threadWindow;
        private WindowInteropHelper _window;

        public MainWindowViewModel()
        {
            _disposedValue = false;
            _launchSession = new Command(this.ExecuteLaunchSession);
            _showThreadWindow = new Command(this.ExecuteShowThreadWindow, this.CanExecuteShowThreadWindow);
            _deleteThreadWindow = new Command(this.ExecuteDeleteThreadWindow, this.CanExecuteDeleteThreadWindow);
            _authenticate = new Command(this.ExecuteAuthenticate);
            _launchApplication = new Command(this.ExecuteLaunchApplication);
            _kielbasa = Kielbasa.Create();
        }

        ~MainWindowViewModel()
        {
            // Do not change this code. Put cleanup code in Dispose(bool disposing) above.
            Dispose(false);
        }

        public ICommand LaunchSession { get { return _launchSession; } }
        public ICommand ShowThreadWindow { get { return _showThreadWindow; } }
        public ICommand DeleteThreadWindow { get { return _deleteThreadWindow; } }
        public ICommand Authenticate { get { return _authenticate; } }
        public ICommand LaunchApplication { get { return _launchApplication; } }

        public string ServerName
        {
            get { return _serverName; }
            set
            {
                if(!string.Equals(_serverName, value))
                {
                    _serverName = value;
                    _launchSession.EmitCanExecuteChanged();
                }
            }
        }

        WindowInteropHelper IWindowHandleReceiver.Window
        {
            get { return _window; }

            set
            {
                if(!WindowInteropHelper.Equals(_window, value))
                {
                    _window = value;
                    _kielbasa.SetWindow(_window);
                }
            }
        }

        private void ExecuteLaunchSession(object parameter)
        {
            _kielbasa.LaunchSession(_serverName);
        }

        private bool CanExecuteLaunchSession(object parameter)
        {
            bool canExecute = false;

            if(null != _serverName)
            {
                canExecute = !string.IsNullOrEmpty(_serverName.Trim());
            }

            return canExecute;
        }

        private void ExecuteShowThreadWindow(object parameter)
        {
            _threadWindow = _kielbasa.CreateThreadWindow();
            _showThreadWindow.EmitCanExecuteChanged();
            _deleteThreadWindow.EmitCanExecuteChanged();
        }

        private bool CanExecuteShowThreadWindow(object parameter)
        {
            return null == _threadWindow;
        }

        private void ExecuteDeleteThreadWindow(object parameter)
        {
            _threadWindow.Dispose();
            _threadWindow = null;
            _showThreadWindow.EmitCanExecuteChanged();
            _deleteThreadWindow.EmitCanExecuteChanged();
        }

        private bool CanExecuteDeleteThreadWindow(object parameter)
        {
            return null != _threadWindow;
        }

        private void ExecuteAuthenticate(object parameter)
        {
            Task.Run(() =>
            {
                _kielbasa.Authenticate();
            });
        }

        private void ExecuteLaunchApplication(object parameter)
        {
            _kielbasa.LaunchProgram();
        }

        #region IDisposable Support

        private void Dispose(bool disposing)
        {
            if (!_disposedValue)
            {
                if (disposing)
                {
                    // TODO: dispose managed state (managed objects).
                }

                _kielbasa.Dispose();
                _disposedValue = true;
            }
        }

        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }
        #endregion
    }
}
