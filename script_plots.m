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
