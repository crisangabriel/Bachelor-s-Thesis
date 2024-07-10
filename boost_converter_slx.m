% function [dx, iL, uC] = boost_converter_slx(t, x, E, L, C, R, D)
%     % State variables
%     iL = x(1);  % Inductor current
%     uC = x(2);  % Capacitor voltage
% 
%     % Calculate the switching state based on the duty cycle D
%     T_switching = 50e-6; % Define a fixed switching period (adjust as needed)
%     t_mod = mod(t, T_switching);
%     if t_mod < D * T_switching
%         interval = 1;  % Switch is on
%     else
%         interval = 2;  % Switch is off
%     end
% 
%     % Calculate the state derivatives
%     if interval == 1
%         diL_dt = E / L;
%         duC_dt = -uC / (R * C);
%     else
%         diL_dt = (E - uC) / L;
%         duC_dt = (iL - uC / R) / C;
%     end
% 
%     % Return the derivatives and states
%     dx = [diL_dt; duC_dt];
% end

function [dx, iL, uC, eventFlag] = boost_converter_slx(t, x, E, L, C, R, D, T_switching)
    % States
    iL = x(1);  
    uC = x(2);  

    % Calculate current interval
    t_mod = mod(t, T_switching);
    if t_mod < D * T_switching
        interval = 1;  % Switch is on
    else
        interval = 2;  % Switch is off
    end

    % Calculate derivatives based on interval
    if interval == 1
        diL_dt = E / L;
        duC_dt = -uC / (R * C);
    elseif interval == 2
        diL_dt = (E - uC) / L;
        duC_dt = (iL - uC / R) / C;
    else
        % Additional interval logic if needed
        diL_dt = 0;
        duC_dt = 0;
    end

    % Check event condition (iL reaching zero)
    eventFlag = iL <= 0;

    % Output derivatives and event flag
    dx = [diL_dt; duC_dt];
end
