% 스크립트 작성 목적
% : 기업이나 프로젝트 중 협업자들에 대한 코드 이해와 가독성을 높이기 위함

% 스크립트 기능 간략 소개
% : 함수 , 변수에 대한 기능 설명등

% 스크립트 input/output

%줄마다 간략한 설명


x = -6:0.01:6   % x에 대한 변수를 일정하게 생성

y1 = cos(0.5*pi*x);  % cos0.5pi
y2 = cos(2*pi*x);    % cos2pi
plot(x,y1)        % cos0.5pi plot
hold on            % cos0.5pi 유지
plot(x,y2,'r')   % cos2pi plot

xlabel('x')   % x축 label
ylabel('y')   % y축 label
legend('cos0.5pi','cos2pi') % 범례