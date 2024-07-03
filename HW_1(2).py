import numpy as np
import matplotlib.pyplot as plt

# 0과 1을 1/2 확률로 랜덤하게 생성
data = np.random.choice([0, 1], size=60, p=[0.5, 0.5])

# 전압 레벨 설정
voltage_levels = {0: '-1', 1: '+1'}

# 디지털 데이터를 전압 레벨로 변환
digital_signal = [voltage_levels[i] for i in data]

# 디지털 파형 그리기
plt.figure(figsize=(10, 2))
plt.step(range(0, len(digital_signal)*2, 2), digital_signal, where='post', linewidth=2)
plt.title('Digital Signal')
plt.xlabel('Time')
plt.ylabel('Voltage Level')
plt.xticks(np.arange(0, len(data)*2, step=2), labels=np.arange(0, len(data), step=1)) 
plt.yticks([0, 1], ['-1V', '+1V'])
plt.ylim(-1.5, 1.5)
plt.grid(True)
plt.show()