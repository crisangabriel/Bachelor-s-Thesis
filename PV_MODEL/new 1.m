% Define input signal parameters
V_start = 0;            % Start voltage (V)
V_end = 180;            % End voltage (V)
V_step = 0.5;           % Voltage step size (V)
time_step = 0.1;        % Time step for each voltage step (s)
irradiance_levels = [1000, 800, 600, 400, 200]; % Irradiance levels G(W/m^2)
temperature = 25;       % Tc (C)

% Create input signal vector
V_sweep = V_start:V_step:V_end;
time_vector = 0:time_step:(length(V_sweep)-1)*time_step;
input_signal = [time_vector' V_sweep'];

% Initialize result vectors
I_results = zeros(length(V_sweep), length(irradiance_levels));
P_results = zeros(length(V_sweep), length(irradiance_levels));

model = 'PVModel3'; % Model name
load_system(model);

% Set the simulation stop time
set_param(model, 'StopTime', num2str(time_vector(end)));

% Loop through each irradiance level
for i = 1:length(irradiance_levels)
    irradiance = irradiance_levels(i);
    
    % Create the input signal in the workspace
    assignin('base', 'irradiance', irradiance);
    assignin('base', 'temperature', temperature);
    assignin('base', 'input_signal', input_signal);
    
    % Run the simulation
    simOut = sim(model, 'SimulationMode', 'normal');
    
    % Extract current and voltage data
    V_sim = simOut.logsout.getElement('Vpv').Values.Data;
    I_sim = simOut.logsout.getElement('Ipv').Values.Data;
    
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
