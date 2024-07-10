%%% Parameters for battery model

Battery_U_OCV = [Battery_U_OCV_fit(1:5:end), Battery_U_OCV_fit(end)]';
Battery_Capacity_Ah = 2.4 ; %Battery Capacity [Ah]
Battery_SOC0 = 50; %Initial SOC value [%]
Battery_SOC =[0	5	10	15	20	25	30	35	40	45	50	55	60	65	70	75	80	85	90	95	100]; %SOC values [%]

%Battery_R1 = 0.003103; %R1 resistance from ECM [Ohm]
%Battery_C1 = 8437.9; %C1 capacitance from ECM [Farad]
%Battery_Rs = 0.010822; %Rs Series resistance from ECM [Ohm]

%load("pulseVtime.mat")

%% params2

Rs = 10.822e-3; 
Rp1 = 3.103e-3;  
Rp = 3.103e-3; 
Rp2 = 2.611e-3;  
Cp1 = 8.4379e3;  
Cp = 8.4379e3;
Cp2 = 91.401e3;  

%%
Nserie= 13 ;
Nparalel = 29 ;

Rs_pack = (Nserie*Rs)/Nparalel
Rp_pack = (Nserie*Rp)/Nparalel
Cp_pack = (Nparalel*Cp)/Nserie

%%

Battery_U_OCV = [Battery_U_OCV_fit(1:5:end), Battery_U_OCV_fit(end)]';
Battery_Capacity_Ah = 2.4 ; %Battery Capacity [Ah]
Battery_SOC0 = 50; %Initial SOC value [%]
Battery_SOC =[0	5	10	15	20	25	30	35	40	45	50	55	60	65	70	75	80	85	90	95	100]; %SOC values [%]


%%
V_pack_OCV = Nserie*Battery_U_OCV;
