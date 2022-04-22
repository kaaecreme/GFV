clear all; close all; clc;
set(0,'DefaultFigureWindowStyle','docked');
set(0, 'DefaultLineLineWidth', 1.5);

% MÅLINGER MED SAMPLE RATE PÅ CA. 3 PR SEKUND. HUSK AT ÆNDRE SAMPLE
% VARIABEL, HVIS ANDEN ANVENDES
plotandprint('30til50_P2_I1_d0.txt','P = 2, I = 1, D = 0')

plotandprint('30til50_P4_I1_d0.txt','P = 4, I = 1, D = 0')

plotandprint('30til50_P8_I1_d0.txt','P = 8, I = 1, D = 0')

plotandprint('30til50_P2_I2_d0.txt','P = 2, I = 2, D = 0')

plotandprint('30til50_P2_I4_D0.txt','P = 2, I = 4, D = 0')

plotandprint('30til50_P4_I4_D0.txt','P = 4, I = 4, D = 0')


% MÅLINGER MED SAMPLE RATE PÅ CA. 3 PR SEKUND. HUSK AT ÆNDRE SAMPLE
% VARIABEL, HVIS ANDEN ANVENDES
%plotandprint
%('30til50_P4_I4_D0_Integrale1000_Måling6.txt','6/s, P = 4, I = 4, D = 0')



function plotandprint(filestr,titlestr)
points = 10;
samplesprsek = 3;


A = importdata(filestr);
setPoint = A(:,1);
temp = A(:,2);
error = A(:,3);
control = A(:,4);
propPart = A(:,8);
intPart = A(:,9);
derivPart = A(:,10);
time = linspace(0,1/samplesprsek*length(temp),length(temp));

setPointplot = setPoint(1:points:(length(temp)))
tempplot = temp(1:points:length(temp));
errorplot = error(1:points:length(temp));
controlplot = control(1:points:length(temp));
propPartplot = propPart(1:points:length(temp));
intPartplot = intPart(1:points:length(temp));
derivPartplot = derivPart(1:points:length(temp));
timeplot = time(1:points:length(temp));


disp('Approximate rise time in seconds')
last30 = find(temp == 30);
first50 = find(temp == 50);
risetime = (first50(1) - last30(end))/samplesprsek;

disp('Maximum overshoot recorded')
overshoot = max(temp) - 50;
disp('Maximum undershoot recorded')
undershoot = min(temp(first50:end)) - 50;


figure
hold on
title(titlestr);
grid on; 
xlabel('Time (s)', 'FontSize', 14); 
ylabel('Control signal [% duty cycle]', 'FontSize', 14);
plot(timeplot,controlplot);
plot(timeplot,intPartplot);
plot(timeplot,propPartplot);
axis([0 1250 -15 110])
[~,b] = legend( 'control', 'intPart', 'propPart', 'Location',...
    'NorthEast', 'Interpreter', 'none' , 'FontSize', 14);
set(findobj(b,'-property','MarkerSize'),'MarkerSize',30)

figure
hold on
title(titlestr);
grid on; 
xlabel('Time (s)', 'FontSize', 14); 
ylabel('Temperatur [^\circC]', 'FontSize', 14);
plot(timeplot,setPointplot);
plot(timeplot,tempplot);
axis([0 1250 25 55])
[~,b] = legend('setPoint', 'Temperature', 'Location', 'SouthEast',...
    'Interpreter', 'none', 'FontSize', 14);
set(findobj(b,'-property','MarkerSize'),'MarkerSize',30)

annotation('textbox', [0.7, 0.3, 0.1, 0.1], 'String', ...
    ['Risetime (s):  ', num2str(risetime), ...
    newline, 'Undershoot (^\circC):  ', num2str(undershoot), newline, ... 
    'Overshoot (^\circC):  ', num2str(overshoot)], 'FontSize', 14);

end