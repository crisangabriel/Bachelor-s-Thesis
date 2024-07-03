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