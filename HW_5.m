T0_values = 10.^[0:4]; % T0 = 1, 10, 100, 1000, 10000
Omega = linspace(-50, 50, 1000); % 주파수 범위

figure;
hold on;
for k = 1:length(T0_values) % T0의 개수 만큼 반복
    T0 = T0_values(k);
    X_Omega = sin(T0 * Omega / 2) ./ (T0 * Omega / 2); % (a)에서 구한 식
    plot(Omega, abs(X_Omega), 'DisplayName', ['T_0 = ', num2str(T0)]); % X_Omega의 절댓값을 plot하고 'T_0 = _(위에서 설정한 5가지 값 중 하나)' 로 표시한다.
end

xlabel('\Omega');     % x축 표시 (오메가)
ylabel('|X(\Omega)|'); % y축 표시 (크기)
title('Magnitude Spectrum for different T_0 values'); % "T0에 따른 크키 스펙트럼"
legend;
grid on;
hold off;
