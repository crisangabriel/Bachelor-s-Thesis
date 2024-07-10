clear all;
close;
%E=30;       % input voltage value
L=350e-6;     % inductor value
C=128.78e-6;    % capacitor value
R=4.6;       % load value

Q=sqrt(L./C)./R;
T0=2.*pi.*sqrt(L.*C);

T=10e-6;    % switching period
D=0.38;      % duty-cycle
N=1000;       % numbers of periods to be displayed

%p=1;        % default plotting regime (transient)

%type=1;     % default analyzed converter - Buck
%type=2;   % Boost
%type=3;   % Buck-Boost

%boost_converter(E,L,C,R,T,D,N); % function for converters simulation
