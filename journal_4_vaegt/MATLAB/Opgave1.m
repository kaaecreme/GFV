clear all; close all; clc;
set(0,'DefaultFigureWindowStyle','docked');
set(0, 'DefaultLineLineWidth', 1.5);



beta = linfitAndPlot("Øvelse1Data.txt","ADC values fit with linear function")



function beta = linfitAndPlot(filestr,titlestr)
data = importdata(filestr);
weight = data(:,1);
voltage = data(:,2);

xs = linspace(min(weight), max(weight),length(weight));
xs = xs';


%Funktionen antages lineær, der gættes på værdier 10 og 0
beta = [10 0];
f = @(a,x) a(1)*x+a(2);
%Fittet bestemmes
beta = nlinfit(weight,voltage,f,beta);
linfit = beta(1)*xs+beta(2);
Delta = voltage-linfit;
figure
hold on
title(titlestr);
grid on;
xlabel('Weight [Kg]', 'FontSize', 14);
ylabel('ADC-value', 'FontSize', 14); 
plot(weight, voltage, 'o');
plot(xs,linfit)
[~,b] = legend('Data points', 'Linear fit', 'Location', 'SouthEast',...
    'Interpreter', 'none', 'FontSize', 14);
set(findobj(b,'-property','MarkerSize'),'MarkerSize',15)
annotation('textbox', [0.7, 0.3, 0.1, 0.1], 'String', ...
    ['Function:', newline, 'y = ', num2str(beta(1)), ...
    '*x + ', num2str(beta(2))], 'FontSize', 14);

end 