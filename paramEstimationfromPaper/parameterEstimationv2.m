%% Initial parameters
k = 1.381e-23; % Boltzmann constant (J/K)
q = 1.602e-19; % Electron charge (C)
T = 298; % Temperature at STC (K)
V_T = (k * T) / q; % Thermal voltage (V)

% BP 4175T PV module data at STC
Isc = 5.45; % Short-circuit current (A)
Voc = 43.6; % Open-circuit voltage (V)
n = 1.6; % Diode ideality factor (from the paper for analytical method)

% Calculate reverse saturation current at STC
I_r0 = Isc / (exp(Voc / (n * V_T)) - 1);
disp(['I_r0: ', num2str(I_r0), ' A']);

% Temperature dependence of reverse saturation current
T0 = 298; % Reference temperature (K)
Eg = 1.12; % Band gap energy for silicon (eV)

I_r_T = I_r0 * ((T / T0)^3) * exp((Eg / (n * V_T)) * (1 / T0 - 1 / T));
disp(['I_r_T: ', num2str(I_r_T), ' A']);

%% Run the PV model with initial parameters to get I-V data
V_sweep = linspace(0, Voc, 100); % Voltage sweep from 0 to Voc
G = 1000; % Irradiance in W/m^2
Tc = 298; % Temperature in K

% Create input signal for the simulation
time_vector = linspace(0, 10, length(V_sweep));
input_signal = [time_vector' V_sweep'];

% Load and run the Simulink model
model = 'PVModel3'; % Model name
load_system(model);
set_param(model, 'StopTime', num2str(time_vector(end)));

% Assign input variables
assignin('base', 'input_signal', input_signal);
assignin('base', 'G', G);
assignin('base', 'Tc', Tc);

% Run the simulation
simOut = sim(model, 'SimulationMode', 'normal');

% Extract I-V data
logsout = simOut.get('logsout');
Vpv_element = logsout.getElement('Vpv');
Ipv_element = logsout.getElement('Ipv');

V_sim = Vpv_element.Values.Data;
I_sim = Ipv_element.Values.Data;

% Calculate slopes at Voc and Isc
dVdI_Voc = gradient(V_sim) ./ gradient(I_sim); % Slope near Voc
dVdI_Isc = gradient(V_sim) ./ gradient(I_sim); % Slope near Isc

% Calculate Rs and Rp using equations (29) and (30)
R_s = -dVdI_Voc(end) - (n * V_T) / I_r0 * exp(Voc / (n * V_T));
disp(['R_s: ', num2str(R_s), ' Ohms']);

R_p = -((dVdI_Isc(1) + R_s) / (1 + (dVdI_Isc(1) + R_s) * I_r0 / (n * V_T * exp(-Voc / (n * V_T)))));
disp(['R_p: ', num2str(R_p), ' Ohms']);

