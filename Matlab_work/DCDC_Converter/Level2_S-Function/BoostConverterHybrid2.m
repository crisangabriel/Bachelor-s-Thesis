function BoostConverterHybrid2(block)
% Level-2 MATLAB file S-Function for a Boost Converter

  setup(block);
  
%endfunction

function setup(block)

  % Register number of ports
  block.NumInputPorts  = 3; % Vin, Iout, Duty Cycle
  block.NumOutputPorts = 1; % Vout
  
  % Setup port properties to be inherited or dynamic
  block.SetPreCompInpPortInfoToDynamic;
  block.SetPreCompOutPortInfoToDynamic;

  % Override input port properties
  for i = 1:3
      block.InputPort(i).Dimensions        = 1;
      block.InputPort(i).DatatypeID  = 0;  % double
      block.InputPort(i).Complexity  = 'Real';
      block.InputPort(i).DirectFeedthrough = false;
  end

  % Override output port properties
  block.OutputPort(1).Dimensions       = 1;
  block.OutputPort(1).DatatypeID  = 0; % double
  block.OutputPort(1).Complexity  = 'Real';
  
  % Register parameters
  %block.NumDialogPrms = 3; % Parameters: R, L, C

  % Register the number of continuous states
  block.NumContStates = 2;

  % Register sample times
  block.SampleTimes = [0 0];
  
  % -----------------------------------------------------------------
  % The MATLAB S-function uses an internal discrete time integrator
  % and therefore needs to set block.Dwork to avoid cumulative 
  % floating point errors that are produced when the integrator state
  % value is updated using a small time step.
  % -----------------------------------------------------------------

  % Specify the block simStateCompliance
  block.SimStateCompliance = 'DefaultSimState';

  % Register methods
  block.RegBlockMethod('InitializeConditions', @InitializeConditions);
  block.RegBlockMethod('Outputs',                 @Outputs);     
  block.RegBlockMethod('Derivatives',             @Derivatives);
  block.RegBlockMethod('Terminate',               @Terminate);

%endfunction

function InitializeConditions(block)

  % Initialize continuous states
  block.ContStates.Data = [0; 0];

%endfunction

function Outputs(block)

  % Output the state value
  C = [0 1];
  block.OutputPort(1).Data = C * block.ContStates.Data;

%endfunction

function Derivatives(block)

  % Get parameters
  % R = block.DialogPrm(1).Data;    
  % L = block.DialogPrm(2).Data;
  % C = block.DialogPrm(3).Data;
  R = 1;
  L = 1;
  C = 1;
  
  % Get inputs
  Vin = block.InputPort(1).Data;
  DutyCycle = block.InputPort(3).Data;

  % Define state-space matrices
  

  Aon = [0 0; 0 -1/(R*C)];
  Aoff = [0 -1/L; 1/C -1/(R*C)];
  B = [1/L; 0];

  % Compute derivatives based on duty cycle
  if DutyCycle > 0.5
      A = Aon;
  else
      A = Aoff;
  end
  
  block.Derivatives.Data = A * block.ContStates.Data + B * Vin;

%endfunction

function Terminate(block)

  % No termination tasks needed

%endfunction
