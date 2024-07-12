% ch4 example 1
clear all; clc;
Ts=0.01; delay=1; Tend=2.5; t=0:Ts:Tend;
for n=1:3
    if n==1
        x=unitstep(t,0)-unitstep(t,-delay);
        h=unitstep(t,0)-unitstep(t,-2*delay);
        figure(1)
    elseif n==2
        x=ramp(t,1,0)+ramp(t,-2,-1)+ramp(t,1,2);
        h=x;
        figure(2)
    else
        x=exp(-2*t); h=2*exp(-10*t);
        figure(3)
    end
    y=Ts*conv(x,h);
    t1=0:Ts:length(y)*Ts-Ts;
    subplot(311)
    plot(t,x); axis([0 2.5 -0.1 1.2]); grid on; ylabel('x_3(t)');
    subplot(312)
    plot(t,h); axis([0 2.5 -0.1 2.1]); grid on; ylabel('h_3(t)');
    subplot(313)
    plot(t1,y); axis([0 5 -0.01 1.1*max(y)]); grid on; ylabel('y_3(t)');
end

% ch4 example 2
clear all;clc
Ts=0.01; delay=1; Tend=20;
t=0:Ts:Tend;
x1=cos(2*pi*t).*(unitstep(t,0)-unitstep(t,-20));
x2=sin(2*pi*t).*exp(-0.1*t).*(unitstep(t,0)-unitstep(t,-20));
x3=ramp(t,1,0)+ramp(t,-2,-2)+ramp(t,1,-8);
h=exp(-t);
y1=Ts*conv(x1,h);
y2=Ts*conv(x2,h);
y3=Ts*conv(x3,h);

%plot
t1=0:Ts:length(y1)*Ts-Ts;
figure(1)
subplot(311)
plot(t,x1); axis([0 20 -5 3]); grid on; ylabel('x_1(t)');
subplot(312)
plot(t,h); axis([0 20 -0.1 1]); grid on; ylabel('h(t)');
subplot(313)
plot(t1,y1); grid on; ylabel('y_1(t)');

t2=0:Ts:length(y2)*Ts-Ts;
figure(2)
subplot(311)
plot(t,x1); axis([0 20 -5 3]); grid on; ylabel('x_1(t)');
subplot(312)
plot(t,h); axis([0 20 -0.1 1]); grid on; ylabel('h(t)');
subplot(313)
plot(t2,y2); grid on; ylabel('y_1(t)');

t3=0:Ts:length(y3)*Ts-Ts;
figure(3)
subplot(311)
plot(t,x1); axis([0 20 -5 3]); grid on; ylabel('x_1(t)');
subplot(312)
plot(t,h); axis([0 20 -0.1 1]); grid on; ylabel('h(t)');
subplot(313)
plot(t3,y3); grid on; ylabel('y_1(t)');
