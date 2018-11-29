% +3.3V, 750mA Power supply, LT3973, AC Power Meter
clc;
clear;

% Constants
Vin_max = 13.2;
Vin = 12;
Vout = 3.3;
Vd = 0.7;
Vsw = 0.5;
ton_min = 60*10^-9;

% Switching frequency
fsw_max = (Vout + Vd) / (ton_min * (Vin_max - Vsw + Vd));
fprintf("Maximum Fsw = %.2f MHz\n\r", fsw_max/1000000);

% Selected switching frequency
fsw = 2*10^6;
fprintf("Selected Fsw = %.2f MHz\n\r", fsw/1000000);

% Nominal duty cycle
D = Vout/Vin;
fprintf("Nominal duty cycle is %.2f percent\n\r", D * 100);

% Suggested inductance
L_sug = 1.5 * ((Vout + Vd)/(fsw/1000000));
fprintf("Suggested inductance is %.2f uH\n\r", L_sug);

% Suggested output cap
C_out_sug = 50/(Vout*(fsw/1000000));
fprintf("Suggested output capacitance is %.2f uF\n\r", C_out_sug);

% Undervoltage lockout resistor divider
R4 = 10000;
Vuvlo = 10.8;
Vrefuvlo = 1.19;
R3 = (Vuvlo*R4/Vrefuvlo) - R4;
fprintf("Selected bottom UVLO R = %.2f kOhm\n\r", R4/1000);
fprintf("Calculated top UVLO R = %.2f kOhm\n\r", R3/1000);