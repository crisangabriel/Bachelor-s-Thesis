function [sys,x0,str,ts,simStateCompliance] = BoostConverterHybrid(t,x,u,flag)

switch flag,
  % Initialization
  case 0,
    [sys,x0,str,ts,simStateCompliance]=mdlInitializeSizes();
  % Derivatives
  case 1,
    sys=mdlDerivatives(t,x,u);
  % Update
  case 2,
    sys=mdlUpdate(t,x,u);
  % Outputs
  case 3,
    sys=mdlOutputs(t,x,u);
  % GetTimeOfNextVarHit
  case 4,
    sys=mdlGetTimeOfNextVarHit(t,x,u);
  % Terminate
  case 9,
    sys=mdlTerminate(t,x,u);
  % Unexpected flags
  otherwise
    DAStudio.error('Simulink:blocks:unhandledFlag', num2str(flag));
end

% mdlInitializeSizes
function [sys,x0,str,ts,simStateCompliance]=mdlInitializeSizes()
sizes = simsizes;
sizes.NumContStates  = 2;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 1;
sizes.NumInputs      = 3; % Vin, Iout, Duty Cycle
sizes.DirFeedthrough = 0;
sizes.NumSampleTimes = 1;   
sys = simsizes(sizes);
x0  = [0, 0];
str = [];
ts  = [0 0];
simStateCompliance = 'UnknownSimState';

% mdlDerivatives
function sys=mdlDerivatives(t,x,u)
    Vin = u(1);
    DutyCycle = u(3);
    
    R = 1;    
    L = 1;
    C = 1;

    Aon = [0 0; 0 -1/(R*C)];
    Aoff = [0 -1/L; 1/C -1/(R*C)];
    B = [1/L; 0];
    
    if DutyCycle > 0.5
        A = Aon;
    else
        A = Aoff;
    end
    
    sys = A*x + B*Vin;

% mdlUpdate
function sys=mdlUpdate(t,x,u)
sys = [];

% mdlOutputs
function sys=mdlOutputs(t,x,u)
C=[0 1];
sys = C*x;

% mdlGetTimeOfNextVarHit
function sys=mdlGetTimeOfNextVarHit(t,x,u)
sampleTime = 1;
sys = t + sampleTime;

% mdlTerminate
function sys=mdlTerminate(t,x,u)
sys = [];
