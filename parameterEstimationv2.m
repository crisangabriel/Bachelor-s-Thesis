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


%%
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
R_s = -dVdI_Voc(end) - (A * V_T) / I_r0 * exp(Voc / (A * V_T));
disp(['R_s: ', num2str(R_s), ' Ohms']);

R_p = -((dVdI_Isc(1) + R_s) / (1 + (dVdI_Isc(1) + R_s) * I_r0 / (A * V_T * exp(-Voc / (A * V_T)))));
disp(['R_p: ', num2str(R_p), ' Ohms']);

% Update the parameters with the estimated values
Rs = R_s; % Updated Rs
Rp = R_p; % Updated Rp

% Save updated parameters
save('PV_Params.mat', 'Rated_power', 'Isc', 'Voc', 'Ki', 'Kv', 'Ns', 'A', 'Tref', 'Gref', 'Tc', 'G', 'Rs', 'Rp', 'I_r_T');

%% Sim
% Load Parameters
load('PV_Params.mat');

% Define input signal
V_start = 0;            % Start voltage (V)
V_end = 34.9;            % End voltage (V)
V_step = 0.1;           % Voltage step size (V)
time_step = 0.01;        % Time step for each voltage step (s)
irradiance_levels = [1000, 800, 600, 400, 200]; % Irradiance levels G(W/m^2)
temperature = 25;       % Tc (C)

% Time vector for input
V_sweep = V_start:V_step:V_end;
time_vector = 0:time_step:(length(V_sweep)-1)*time_step;

% Input signal for Simulink
input_signal = [time_vector' V_sweep'];

% Initialize result vectors
I_results = zeros(length(V_sweep), length(irradiance_levels));
P_results = zeros(length(V_sweep), length(irradiance_levels));

model = 'PVModel3'; % Model slx
load_system(model);

% Set the simulation stop time
set_param(model, 'StopTime', num2str(time_vector(end)));

% Loop through each irradiance level
for i = 1:length(irradiance_levels)
    irradiance = irradiance_levels(i);

    % Create the input signal in the workspace
    irradiance_data = [time_vector' irradiance * ones(length(time_vector), 1)];
    temperature_data = [time_vector' temperature .* ones(length(time_vector), 1)];  
  
    assignin('base', 'irradiance', irradiance_data);
    assignin('base', 'temperature', temperature_data);
    assignin('base', 'input_signal', input_signal);
    
    % Run the simulation
    simOut = sim(model, 'SimulationMode', 'normal');
    
    % Extract current and voltage data
    logsout = simOut.get('logsout');
    Vpv_element = logsout.getElement('Vpv');
    Ipv_element = logsout.getElement('Ipv');
    
    V_sim = Vpv_element.Values.Data;
    I_sim = Ipv_element.Values.Data;
    
    % Resize results matrix if needed
    if length(I_sim) ~= length(V_sweep)
        I_results = zeros(length(I_sim), length(irradiance_levels));
        P_results = zeros(length(I_sim), length(irradiance_levels));
        V_sweep = linspace(V_start, V_end, length(I_sim));
    end
    
    % Calculate power
    P_sim = V_sim .* I_sim;
    
    % Store results
    I_results(:, i) = I_sim;
    P_results(:, i) = P_sim;
end

% Plot I-V and P-V curves
figure;
for i = 1:length(irradiance_levels)
    subplot(2,1,1);
    plot(V_sweep, I_results(:, i), 'DisplayName', ['Irradiance = ' num2str(irradiance_levels(i)) ' W/m^2']);
    hold on;
    ylabel('Current (A)');
    xlabel('Voltage (V)');
    title('I-V Characteristics');
    legend show;
    
    subplot(2,1,2);
    plot(V_sweep, P_results(:, i), 'DisplayName', ['Irradiance = ' num2str(irradiance_levels(i)) ' W/m^2']);
    hold on;
    ylabel('Power (W)');
    xlabel('Voltage (V)');
    title('P-V Characteristics');
    legend show;
end

