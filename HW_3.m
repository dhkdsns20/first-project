% original sine wave
t = linspace(0, 4,4001);
x = 7*cos(pi*t);
plot(t, x, 'linewidth', 1.5), hold on

% clipped sine wave
ub = 4;     % upper bound 
lb = -4;    % lower bound
y = max(lb, min(x, ub));
plot(t, y, 'linewidth', 1.5), hold off

grid on, xlabel('t'), ylabel('x(t)'), ylim([-10 10])