% Definim semnal intrare
V_start = 0;            % Start voltage (V)
V_end = 38.4;           % End voltage (V)
V_step = 0.1;           % Voltage step size (V)
time_step = 1;       % Time step for each voltage step (s)
irradiance_levels = [1000 , 950 , 900,850, 800, 750, 700, 650, 600, 550, 500, 450, 400]; % Irradiance levels G(W/m^2)
temperature = 25;       % T(C)

% Vector de timp pt intrare
V_sweep = 0:0.1:38.4;
time_vector = 0:0.1:38.4;

% Semnal pt simulink
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
    irradiance_data = [time_vector' irradiance .* ones(length(time_vector), 1)];
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
    I_results(:, i) = I_sim(:,i);
    P_results(:, i) = P_sim(:,i);
end

% Plot I-V and P-V curves
figure;
for i = 1:length(irradiance_levels)

    % Assume your data is stored in variables I_results, V_sweep, and P_results
    % Assume irradiance_levels is defined

    % Initialize cell arrays to store valid data
    V_valid = cell(1, size(I_results, 2));
    I_valid = cell(1, size(I_results, 2));
    P_valid = cell(1, size(I_results, 2));

    % Iterate over each column
    for i = 1:size(I_results, 2)
        if any(I_results(:,i) <= 0)
            valid_indices = find(I_results(:,i) < 0, 1);
            V_valid{i} = V_sweep(1:valid_indices-1);
            I_valid{i} = I_results(1:valid_indices-1, i);
            P_valid{i} = P_results(1:valid_indices-1, i);
        else
            V_valid{i} = V_sweep;
            I_valid{i} = I_results(:, i);
            P_valid{i} = P_results(:, i);
        end
    end

    % Plot I-V Characteristics
    for i = 1:5    
    subplot(2,1,1);
    plot(V_valid{i}, I_valid{i}, 'DisplayName', ['Irradiance = ' num2str(irradiance_levels(i)) ' W/m^2'],'LineWidth',2);
    hold on;
    ylabel('Current (A)');
    xlabel('Voltage (V)');
    title('I-V Characteristics');
    legend show;

    subplot(2,1,2);
    plot(V_valid{i}, P_valid{i}, 'DisplayName', ['Irradiance = ' num2str(irradiance_levels(i)) ' W/m^2'],'LineWidth',2);
    hold on;
    ylabel('Power (W)');
    xlabel('Voltage (V)');
    title('P-V Characteristics');
    legend show;
    end
end
