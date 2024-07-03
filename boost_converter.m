function boost_converter(E, L, C, R, T, D, N)
    % Parameters
    t = 0;
    y = [0 0];  % Initial conditions [iL, uC]

    % Simulation loop
    for k = 1:N
        nt = length(t);
        t0 = (k - 1) * T;
        tf = t0 + D * T;
        ci = y(nt, :);
        interval = 1;
        [t, y] = ode45(@boost_conv, [t0, tf], ci, [], E, R, L, C, interval);
        nt = length(t);

        % Setting the plots
        subplot(2, 1, 1);
        plot(t, y(:, 1), 'r'); grid on; hold on;
        subplot(2, 1, 2);
        plot(t, y(:, 2), 'r'); grid on; hold on;

        interval = 2;
        t0 = (k - 1) * T + D * T;
        tf = k * T;
        ci = y(nt, :);
        options = odeset('Events', @conv_ev);
        [t, y, te, ye, ie] = ode45(@boost_conv, [t0, tf], ci, options, E, R, L, C, interval);
        nt = length(t);

        subplot(2, 1, 1);
        plot(t, y(:, 1), 'b'); grid on; hold on;
        subplot(2, 1, 2);
        plot(t, y(:, 2), 'b'); grid on; hold on;

        if te > 0
            t0 = t(nt);
            tf = k * T;
            ci = y(nt, :);
            interval = 3;
            [t, y] = ode45(@boost_conv, [t0, tf], ci, [], E, R, L, C, interval);
            subplot(2, 1, 1);
            plot(t, y(:, 1), 'g'); grid on; hold on;
            subplot(2, 1, 2);
            plot(t, y(:, 2), 'g'); grid on; hold on;
        end
    end

    subplot(2, 1, 1);
    ylabel('iL [A]');
    title('Boost Converter');
    subplot(2, 1, 2);
    ylabel('uC [V]');
    xlabel('t [s]');
end

% Function for Boost converter dynamics
function dy = boost_conv(t, y, E, R, L, C, interval)
    dy = zeros(2, 1);
    if interval == 1
        a = 1; b = 0; c = 0;
    elseif interval == 2
        a = 1; b = 1; c = 1;
    else
        a = 0; b = 0; c = 0;
    end
    % Current equation
    dy(1) = (a * E - b * y(2)) / L;
    % Voltage equation
    dy(2) = (c * y(1) - y(2) / R) / C;
end

% Event function to detect iL = 0
function [value, isterminal, direction] = conv_ev(t, y, E, R, L, C, interval)
    value = y(1);  % detect iL = 0
    isterminal = 1;  % stop the integration
    direction = -1;  % negative direction
end
