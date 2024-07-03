%%
% Time vector
t = 0:1e-6:0.1; % Time vector from 0 to 0.1 seconds with 1 microsecond steps

% PV array voltage (Vs) signal
Vs = 20 + 2*sin(2*pi*50*t)'; % Example: DC voltage with a small sinusoidal ripple

% PV array current (Is) signal
Is = 5 + 0.5*sin(2*pi*50*t)'; % Example: DC current with a small sinusoidal ripple

% Create structures for Vs and Is
Vs_struct.time = t';
Vs_struct.signals.values = Vs;
Vs_struct.signals.dimensions = 1;

Is_struct.time = t';
Is_struct.signals.values = Is;
Is_struct.signals.dimensions = 1;

% Save signals to workspace
assignin('base', 'Vs_struct', Vs_struct);
assignin('base', 'Is_struct', Is_struct);
