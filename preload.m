clear;
clc;
load('70PVArrayExperimentalData.mat');

MPPT_IncCond=Simulink.Variant('MPPT_MODE==1')
MPPT_PandO=Simulink.Variant('MPPT_MODE==2')

MPPT_MODE=1

Constant_800=Simulink.Variant('Irradiance_Mode==1')
Constant_1000=Simulink.Variant('Irradiance_Mode==2')
Step=Simulink.Variant('Irradiance_Mode==3')

Irradiance_Mode=2