function [dx, value, isterminal, direction] = boost_conv_try2(t, x, E, L, C, R, interval)
    % State variables
    iL = x(1);
    uC = x(2);

    % Differential equations based on interval
    if interval == 1
        diL_dt = E / L;
        duC_dt = -uC / (R * C);
    elseif interval == 2
        diL_dt = (E - uC) / L;
        duC_dt = (iL - uC / R) / C;
    else
        diL_dt = 0;
        duC_dt = 0;
    end

    % Output derivatives
    dx = [diL_dt; duC_dt];

    % Event detection for iL = 0
    value = iL;
    isterminal = 1;  % Stop integration
    direction = -1;  % Negative direction
end