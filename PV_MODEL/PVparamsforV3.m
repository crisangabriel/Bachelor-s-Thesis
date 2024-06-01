% Parameters from Table I 
%Parametrii model

% Rated Power
Rated_power = 250; % W
% Short-circuit current
Isc = 8.61; % A
% Open-circuit voltage
Voc = 37.41; % V
% Temperature coefficient of Isc
Ki = 0.05 /100; % %/K to fraction/K
% Temperature coefficient of Voc
Kv = -0.32 /100; % %/K to fraction/K
% Series Resistance
Rs = 0.22; % Ohms
% Shunt Resistance
Rp = 415; % Ohms
% Number of cells in series
Ns = 60;
% Diode ideality factor
A = 1.3;
% Standard Test Conditions (STC)
Tref = 298; % K (25 ºC)
Gref = 1000; % W/m^2
% Ambient conditions (can be modified during simulation)
Tc = 298; % Module temperature in K (25 ºC)
G = 1000; % Solar irradiance in W/m^2

% Save the parameters to a .mat file for loading into Simulink
save('PV_Params.mat', 'Rated_power', 'Isc', 'Voc', 'Ki', 'Kv', 'Rs', 'Rp', 'Ns', 'A', 'Tref', 'Gref', 'Tc', 'G');
