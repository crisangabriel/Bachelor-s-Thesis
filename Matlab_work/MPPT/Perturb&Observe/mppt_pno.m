function Vref = mppt_pno(Vpv, Ipv, Vref_prev, P_prev, step_size)
    P = Vpv * Ipv; % Calculate the current power
    deltaP = P - P_prev; % Change in power
    deltaV = Vpv - Vref_prev; % Change in voltage
    
    if deltaP > 0
        if deltaV > 0
            Vref = Vref_prev + step_size;
        else
            Vref = Vref_prev - step_size;
        end
    else
        if deltaV > 0
            Vref = Vref_prev - step_size;
        else
            Vref = Vref_prev + step_size;
        end
    end
    
    % Update previous values
    Vref_prev = Vref;
    P_prev = P;
end
