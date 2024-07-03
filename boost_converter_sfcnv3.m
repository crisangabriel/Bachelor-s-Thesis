function [sys,x0,str,ts,simStateCompliance] = BoostConverter(t,x,u,flag)

switch flag
    case 0
        [sys,x0,str,ts,simStateCompliance] = mdlInitializeSizes();
    case 1
        sys = mdlDerivatives(t,x,u);
    case 3
        sys = mdlOutputs(t,x,u);
    case {2, 4, 9}
        sys = [];
    otherwise
        DAStudio.error('Simulink:blocks:unhandledFlag', num2str(flag));
end

% Function: mdlInitializeSizes ===============================================
function [sys,x0,str,ts,simStateCompliance] = mdlInitializeSizes()
sizes = simsizes;

sizes.NumContStates  = 2;  % iL, uC
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 3;  % iL, uC, Uo
sizes.NumInputs      = 5;  % E, D, L, C, R
sizes.DirFeedthrough = 0;
sizes.NumSampleTimes = 1;

sys = simsizes(sizes);
x0  = [0; 0];  % Initial states: [iL, uC]
str = [];
ts  = [0 0];
simStateCompliance = 'UnknownSimState';

% Function: mdlDerivatives ===================================================
function sys = mdlDerivatives(t,x,u)
% Extract parameters from input
E = u(1);  % Input voltage
D = u(2);  % Duty cycle
L = u(3);  % Inductor value
C = u(4);  % Capacitor value
R = u(5);  % Load resistance

iL = x(1);  % Inductor current
uC = x(2);  % Capacitor voltage

% Determine ON/OFF state based on duty cycle
T_switching = 1; % Define a fixed switching period (adjust as needed)
t_mod = mod(t, T_switching);
switch_state = t_mod < D * T_switching;

if switch_state
    diL_dt = E / L;
    duC_dt = -uC / (R * C);
else
    diL_dt = (E - uC) / L;
    duC_dt = (iL - uC / R) / C;
end

% Ensure the derivatives are real and valid
if ~isreal([diL_dt; duC_dt]) || length([diL_dt; duC_dt]) ~= 2
    disp('Error: Derivatives are not real or not of length 2');
    disp(['diL_dt: ', num2str(diL_dt), ', duC_dt: ', num2str(duC_dt)]);
    error('Derivatives must be a real vector of length 2');
end

sys = [diL_dt; duC_dt];

% Function: mdlOutputs =======================================================
function sys = mdlOutputs(t,x,u)
iL = x(1);  % Inductor current
uC = x(2);  % Capacitor voltage
Uo = uC;    % Output voltage of the Boost converter

sys = [iL; uC; Uo];

% End of BoostConverter S-function
