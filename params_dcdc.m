clear all;
close;
E=20;       % input voltage value
L=3e-5;     % inductor value
C=10e-5;    % capacitor value
R=10;       % load value

Q=sqrt(L./C)./R;
T0=2.*pi.*sqrt(L.*C);

T=50e-6;    % switching period
D=0.5;      % duty-cycle
N=200;       % numbers of periods to be displayed

%p=1;        % default plotting regime (transient)

%type=1;     % default analyzed converter - Buck
 type=2;   % Boost
% type=3;   % Buck-Boost

%boost_converter(E,L,C,R,T,D,N); % function for converters simulation
