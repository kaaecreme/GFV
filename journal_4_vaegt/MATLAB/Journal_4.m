clear all; close all; clc;
set(0,'DefaultFigureWindowStyle','docked');
set(0, 'DefaultLineLineWidth', 1.5);

% OPGAVE 2
linfitAndPlot("Øvelse-2-data.txt", "Measured vs known weights")

%% OPGAVE 4
linfitAndPlot("Opgave4data.txt", "Measured vs known weights - after disturbances")
%% OPGAVE 3

%Der ser ud til at være systematiske fejl ved målinger af små værdier.
%Måske den ikke er helt lineær som antaget i dette interval.
data = importdata("precision.txt");

A = [];
for i = 1:6
A = [A ; 
    calculateErrors(data(:,i))];
end
ys = A(:,1);
errs = A(:,2);
xs = [100; 200; 400; 600; 700; 900]./1000;

data = importdata("Øvelse-2-data.txt");
weight = data(:,1);
voltage = data(:,2);
weight = weight./1000;

xs1 = linspace(0, max(weight),length(weight));
xs1 = xs1';
beta = [10 0];
f = @(a,x) a(1)*x+a(2);
%Fittet bestemmes
beta = nlinfit(weight,voltage,f,beta);
linfit = beta(1)*xs1+beta(2);
testfunk = @(x) beta(1)*x + beta(2);



figure
hold on
title("Expected vs actual measurements with errorbars");
axis([0 1 0 1])
grid on;
ylabel('Measured weight [Kg]', 'FontSize', 14);
xlabel('Known weight [Kg]', 'FontSize', 14); 
errorbar(xs,ys,errs, 'o');
plot(xs1,linfit)


%Funktion til udregning af gennemsnit og spredning ved 95% konfidens
function result = calculateErrors(data)
var = 1/(length(data)-1) * sum((data-mean(data)).^2);
sig = sqrt(var);
sig = sig*1.96;
result = [mean(data), sig];
end

%Funktion til lineært fit. Anvendes i flere opgaver, og finjusteres
%hertil
function beta = linfitAndPlot(filestr,titlestr)
data = importdata(filestr);
weight = data(:,1);
voltage = data(:,2);
weight = weight./1000;

xs = linspace(0, max(weight),length(weight));
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
ylabel('Measured weight [Kg]', 'FontSize', 14);
xlabel('Known weight [Kg]', 'FontSize', 14); 
plot(weight, voltage, 'o');
plot(xs,linfit)
axis([0 1 -0.6 0.4])
[~,b] = legend('Data points', 'Linear fit', 'Location', 'SouthEast',...
    'Interpreter', 'none', 'FontSize', 14);
set(findobj(b,'-property','MarkerSize'),'MarkerSize',15)
annotation('textbox', [0.7, 0.3, 0.1, 0.1], 'String', ...
    ['Følsomhed [1/Kg]:  ', num2str(beta(1)), ...
    newline, 'Offset [Kg]:  ', num2str(beta(2)), newline, ... 
    'Ulinearitet [Kg]:  ', num2str(max(Delta))], 'FontSize', 14);

end 