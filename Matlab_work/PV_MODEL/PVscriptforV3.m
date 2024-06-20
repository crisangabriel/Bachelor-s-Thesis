% Definim semnal intrare
V_start = 0;            % Start voltage (V)
V_end = 34.9;            % End voltage (V)
V_step = 0.1;           % Voltage step size (V)
time_step = 0.01;        % Time step for each voltage step (s)
irradiance_levels = [1000, 800, 600, 400, 200]; % Irradiance levels G(W/m^2)
temperature = 25;       % Tc (C)

% Vector de timp pt intrare
V_sweep = V_start:V_step:V_end;
time_vector = 0:time_step:(length(V_sweep)-1)*time_step;

%Semnal pt simulink
input_signal = [time_vector' V_sweep'];

% Init vectori
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
    
    % % Extract current and voltage data
    % V_sim = simOut.logsout.getElement('Vpv').Values.Data;
    % I_sim = simOut.logsout.getElement('Ipv').Values.Data;
    % 
    
    % Extract current and voltage data
    logsout = simOut.get('logsout');
    Vpv_element = logsout.getElement('Vpv');
    Ipv_element = logsout.getElement('Ipv');
    
    V_sim = Vpv_element.Values.Data;
    I_sim = Ipv_element.Values.Data;
    
    % Resize results matrix 
    if length(I_sim) ~= length(V_sweep)
        I_results = zeros(length(I_sim), length(irradiance_levels));
        P_results = zeros(length(I_sim), length(irradiance_levels));
        V_sweep = linspace(V_start, V_end, length(I_sim));
    end
    
    % Calculate power
    P_sim = V_sim .* I_sim;
    
    % Store results
    I_results(:, i) = I_sim(:,i);
    P_results(:, i) = P_sim(:,i);
end

% Plot I-V and P-V curves
figure;
for i = 1:length(irradiance_levels)
    % Exclude negative values
    % valid_indices = I_results(:, i) >= 0;
    % V_valid = V_sweep(valid_indices);
    % I_valid = I_results(valid_indices, i);
    % P_valid = P_results(valid_indices, i);

    subplot(2,1,1);
    plot(V_sweep, I_results(:,i), 'DisplayName', ['Irradiance = ' num2str(irradiance_levels(i)) ' W/m^2']);
    hold on;
    ylabel('Current (A)');
    xlabel('Voltage (V)');
    title('I-V Characteristics');
    legend show;
    
    subplot(2,1,2);
    plot(V_sweep, P_results(:,i), 'DisplayName', ['Irradiance = ' num2str(irradiance_levels(i)) ' W/m^2']);
    hold on;
    ylabel('Power (W)');
    xlabel('Voltage (V)');
    title('P-V Characteristics');
    legend show;
end
