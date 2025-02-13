%% Parameter estimation using analytical approach (paper)

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

%% Parameters for simulation 
% Save initial parameters to workspace
Rated_power = 175; % W (from Table 2)
Ki = 0.065 / 100; % %/K to fraction/K (from Table 2)
Kv = -0.5 / 100; % %/K to fraction/K (from Table 2)
Ns = 72; % Number of cells in series (assuming typical value for BP module)
A = 1.6; % Diode ideality factor (from Table 3, Analytical method)
Tref = 298; % K (25 ºC)
Gref = 1000; % W/m^2
Tc = 298; % Module temperature in K (25 ºC)
G = 1000; % Solar irradiance in W/m^2

% Initial Parameters for Rs and Rp
Rs = 0.0068; % Ohms (initial guess)
Rp = 1000.8; % Ohms (initial guess)

% Save initial parameters for Simulink
save('PV_Params.mat', 'Rated_power', 'Isc', 'Voc', 'Ki', 'Kv', 'Ns', 'A', 'Tref', 'Gref', 'Tc', 'G', 'I_r_T');
