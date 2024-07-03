function ed_converter(E,L,C,R,T,D,N,p,type)
    % create a new figure
    Fig = figure('Name', 'DC-DC Converters', 'Numbertitle', 'off', 'color', [1, 1, 1]);

    % Create 7 text buttons
    txt = {'E [V]', 'L [H]', 'C [F]', 'R [ohm]', 'T [s]', 'D', 'N'};
    for k = 1:7
        B_T(k) = uicontrol('Style', 'text', ...
            'Units', 'normalized', ...
            'backgroundcolor', [1, 1, 1], ...
            'Position', [0.91 0.95 - 0.1 * (k - 1) 0.10 0.04], ...
            'String', txt{k}, ...
            'Callback', 'close; ');
    end

    % Create 7 Edit buttons
    var = ['E'; 'L'; 'C'; 'R'; 'T'; 'D'; 'N'];
    val = [E; L; C; R; T; D; N];
    xc = '=str2num(get(gco,''String''));close;ed_converter(E,L,C,R,T,D,N,p,type)';
    for i = 1:7
        B_E(i) = uicontrol('Style', 'edit', ...
            'Units', 'normalized', ...
            'backgroundcolor', [1, 1, 0], ...
            'Position', [0.91 0.90 - 0.1 * (i - 1) 0.10 0.04], ...
            'String', num2str(val(i)), ...
            'Callback', cat(2, var(i), xc));
    end

    % Create control buttons for selection of converter type
    Buck = uicontrol('Style', 'pushbutton', ...
        'Units', 'normalized', ...
        'Position', [0.05 0.01 0.17 0.04], ...
        'String', 'Buck', ...
        'backgroundcolor', [0, 1, 0.5], ...
        'Callback', 'type=1;close;ed_converter(E,L,C,R,T,D,N,p,type)');
    
    Boost = uicontrol('Style', 'pushbutton', ...
        'Units', 'normalized', ...
        'Position', [0.25 0.01 0.17 0.04], ...
        'String', 'Boost', ...
        'backgroundcolor', [0, 1, 0.5], ...
        'Callback', 'type=2;close;ed_converter(E,L,C,R,T,D,N,p,type)');
    
    Buck_Boost = uicontrol('Style', 'pushbutton', ...
        'Units', 'normalized', ...
        'Position', [0.45 0.01 0.17 0.04], ...
        'String', 'BuckBoost', ...
        'backgroundcolor', [0, 1, 0.5], ...
        'Callback', 'type=3;close;ed_converter(E,L,C,R,T,D,N,p,type)');

    % Button for Steady-State or Transient Regime
    Bp = uicontrol('Style', 'pushbutton', ...
        'Units', 'normalized', ...
        'Position', [0.01 0.92 0.19 0.04], ...
        'String', 'Steady-State Regime', ...
        'backgroundcolor', [0, 1, 1], ...
        'Callback', 'p=0;close;ed_converter(E,L,C,R,T,D,N,p,type)');
    if p == 0
        set(Bp, 'String', 'Transient Regime');
        set(Bp, 'Callback', 'p=1;close;ed_converter(E,L,C,R,T,D,N,p,type)');
    end

    % Routine for solving the function ec_conv, that describes the converters operation
    t = 0;
    y = [0 0];
    for k = 1:N
        nt = length(t);
        t0 = (k - 1) * T;
        tf = t0 + D * T;
        ci = y(nt, :);
        interval = 1;
        [t, y] = ode45(@ec_conv, [t0, tf], ci, [], E, R, L, C, type, interval);
        nt = length(t);
        % Setting the plots
        subplot('Position', [0.10 0.55 0.80 0.35]);
        plot(t, y(:, 1), 'r'); grid on; hold on;
        subplot('Position', [0.10 0.15 0.80 0.35]);
        plot(t, y(:, 2), 'r'); grid on; hold on;

        interval = 2;
        t0 = (k - 1) * T + D * T;
        tf = k * T;
        ci = y(nt, :);
        options = odeset('Events', @conv_ev);
        [t, y, te, ye, ie] = ode45(@ec_conv, [t0, tf], ci, options, E, R, L, C, type, interval);
        nt = length(t);

        subplot('Position', [0.10 0.55 0.80 0.35]);
        plot(t, y(:, 1), 'b'); grid on; hold on;
        subplot('Position', [0.10 0.15 0.80 0.35]);
        plot(t, y(:, 2), 'b'); grid on; hold on;

        if te > 0
            t0 = t(nt);
            tf = k * T;
            ci = y(nt, :);
            interval = 3;
            [t, y] = ode45(@ec_conv, [t0, tf], ci, [], E, R, L, C, type, interval);
            subplot('Position', [0.10 0.55 0.80 0.35]);
            plot(t, y(:, 1), 'g'); grid on; hold on;
            subplot('Position', [0.10 0.15 0.80 0.35]);
            plot(t, y(:, 2), 'g'); grid on; hold on;
        end
    end

    subplot('Position', [0.10 0.55 0.80 0.35]);
    ylabel('iL [A]');
    switch type
        case 1 % Buck Converter
            Lm = R * T * (1 - D) / 2;
            Uo = E * D;
            if 2 * L / (R * T) >= 1 - D
                % Continuous conduction mode
            else
                % Discontinuous conduction mode
                z = 0.5 * R * D^2 * T / L;
                v = 0.5 * (sqrt(z^2 + 4 * z) - z);
                Uo = v * E;
            end
            title(['Buck Converter', ' Uo = ', num2str(Uo), ' [V]', ' Lm = ', num2str(Lm), ' [H]']);
        case 2 % Boost Converter
            Lm = R * T * D * (1 - D)^2 / 2;
            di = E * D * T / L;
            if 2 * L / (R * T) >= D * (1 - D)^2
                Uo = E / (1 - D);
            else
                v = 0.5 * (1 + sqrt(1 + 2 * D^2 * T * R / L));
                Uo = v * E;
            end
            title(['Boost Converter', ' Uo = ', num2str(Uo), ' [V]', ' Lm = ', num2str(Lm), ' [H]']);
        case 3 % Buck-Boost Converter
            Lm = R * T * (1 - D)^2 / 2;
            if 2 * L / (R * T) >= (1 - D)^2
                Uo = E * D / (1 - D);
            else
                v = D * sqrt(0.5 * T * R / L);
                Uo = v * E;
            end
            title(['Buck-Boost Converter', ' Uo = ', num2str(Uo), ' [V]', ' Lm = ', num2str(Lm), ' [H]']);
    end
    subplot('Position', [0.10 0.15 0.80 0.35]);
    ylabel('Uo = uC [V]');
    xlabel('t [s]');
end

% Function that describes the converters operation
function dy = ec_conv(t, y, E, R, L, C, type, interval)
    dy = zeros(2, 1);
    switch type
        case 1 % Buck Converter
            if interval == 1
                a = 1; b = 1; c = 1;
            elseif interval == 2
                a = 0; b = 1; c = 1;
            else
                a = 0; b = 0; c = 0;
            end
        case 2 % Boost Converter
            if interval == 1
                a = 1; b = 0; c = 0;
            elseif interval == 2
                a = 1; b = 1; c = 1;
            else
                a = 0; b = 0; c = 0;
            end
        case 3 % Buck-Boost Converter
            if interval == 1
                a = 1; b = 0; c = 0;
            elseif interval == 2
                a = 0; b = 1; c = 1;
            else
                a = 0; b = 0; c = 0;
            end
    end
    % Current equation
    dy(1) = (a * E - b * y(2)) / L;
    % Voltage equation
    dy(2) = (c * y(1) - y(2) / R) / C;
end

% Event function to detect iL = 0 and stop integration in negative direction
function [value, isterminal, direction] = conv_ev(t, y, E, R, L, C, type, interval)
    value = y(1);        % detect iL = 0
    isterminal = 1;      % stop the integration
    direction = -1;      % negative direction
end
