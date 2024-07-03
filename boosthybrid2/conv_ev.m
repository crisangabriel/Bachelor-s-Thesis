function [value, isterminal, direction] = conv_ev(t, y)
    value = y(1);  % detect iL = 0
    isterminal = 1;  % stop the integration
    direction = -1;  % negative direction
end