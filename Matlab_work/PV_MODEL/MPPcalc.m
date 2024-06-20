pmax = max(out.PV.signals.values(:,2));
vrange = max(out.PV.signals.values(:,1));
irange = max(out.PV.signals.values(:,3));
[tf,index]=ismember(pmax,out.PV.signals.values(:,2));
disp(' MPP power: ')
disp(out.PV.signals.values(index,2));
disp(' MPP voltage: ')
disp(out.PV.signals.values(index,1));
disp(' MPP current: ');
disp(out.PV.signals.values(index,3));
figure(1)
plot(out.PV.signals.values(:,1),out.PV.signals.values(:,2)); 
axis([0 vrange 0 pmax]);
figure(2)
plot(out.PV.signals.values(:,1),out.PV.signals.values(:,3));
axis([0 vrange 0 irange]);