clear all;
close;
E=90;       % input voltage value
L=8945e-6;     % inductor value
C=106.75e-6;    % capacitor value
R=48.48;       % load value

Q=sqrt(L./C)./R;
T0=2.*pi.*sqrt(L.*C);

T=10e-6;    % switching period
D=0.625;      % duty-cycle
N=2000;       % numbers of periods to be displayed

%p=1;        % default plotting regime (transient)

%type=1;     % default analyzed converter - Buck
%type=2;   % Boost
%type=3;   % Buck-Boost

%boost_converter(E,L,C,R,T,D,N); % function for converters simulation
