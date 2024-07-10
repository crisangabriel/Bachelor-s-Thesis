% Coeficientii polinomului folosit pentru potrivirea caracteristicii
coefficients = [-36.93, 142.4, -214.8, 158, -56.25, 7.95, 0.4, 3.44];

% Define SOC
Battery_SOC = linspace(0, 1, 100);

% Calculam OCV folosind polyval
U_OC = polyval(coefficients, Battery_SOC);

%% Plot
figure;
plot(Battery_SOC, U_OC, 'LineWidth', 2);
xlabel('State of Charge (SOC)');
ylabel('Open Circuit Voltage (U_{OC})');
title('Open Circuit Voltage vs. State of Charge');
grid on;

%% Plot pt verificarea suprapunerii
p = polyfit(Battery_SOC, U_OC, 7); % Fit a 7th-degree polynomial
Battery_U_OCV_fit = polyval(p, Battery_SOC);

% Plot the fitted polynomial
hold on;
plot(Battery_SOC, Battery_U_OCV_fit, '--r', 'LineWidth', 1.5);
legend('Original Polynomial', 'Fitted Polynomial');
hold off;
