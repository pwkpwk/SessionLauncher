namespace SessionLauncher
{
    using SessionHelper;
    using System;
    using System.Windows.Input;

    sealed class MainWindowViewModel : IDisposable
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
        private readonly Command _launchSession;
        private readonly Kielbasa _kielbasa;
        private string _serverName;

        public MainWindowViewModel()
        {
            _disposedValue = false;
            _launchSession = new Command(this.ExecuteLaunchSession, this.CanExecuteLaunchSession);
            _kielbasa = Kielbasa.Create();
        }

        ~MainWindowViewModel()
        {
            // Do not change this code. Put cleanup code in Dispose(bool disposing) above.
            Dispose(false);
        }

        public ICommand LaunchSession
        {
            get { return _launchSession; }
        }

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

        private void ExecuteLaunchSession(object parameter)
        {
            _kielbasa.LaunchSession(_serverName.Trim());
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
