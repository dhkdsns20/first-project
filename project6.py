# 프로그램 실행 예시
# 출력 결과

# print(x_train, x_train.shape)
# [1. 2. 3. 4. 5. 6.] (6,)

# print(y_train, y_train.shape)
# [10. 20. 30. 40. 50. 60.] (6,)

import numpy as np

xy = np.array([[1., 2., 3., 4., 5., 6.],
              [10., 20., 30., 40., 50., 60.]])

## 코드시작 ##
xy_transposed = xy.T

x_train = xy_transposed[:, 0]
y_train = xy_transposed[:, 1]


## 코드종료 ##

print(x_train, x_train.shape)
print(y_train, y_train.shape)


# 프로그램 실행 예시
# 출력 결과

# print(beta_gd, bias)
# [0.53764546] [0.71495179] 

## 코드시작 ##
x_train = np.array([1,2,3,4,5,6])

beta_gd = np.random.rand(1)
bias = np.random.rand(1)


## 코드종료 ##

print(beta_gd, bias)

learning_rate = 0.001

## 코드시작 ##
for epoch in range(1000):
    y_pred=beta_gd*x_train+bias
    error=np.mean((y_pred-y_train)**2)

    gradient_beta=2*np.mean((y_pred-y_train)*x_train)
    gradient_bias=2*np.mean(y_pred-y_train)

    beta_gd = beta_gd - learning_rate * gradient_beta
    bias = bias - learning_rate * gradient_bias

    #print("w:",beta_gd,"b:",bias)
    if epoch % 100 == 0:
        print(f"Epoch(   {epoch}/{1000}) cost:   {error:.6f}, w:   {beta_gd[0]:.6f}, b:   {bias[0]:.6f}")


## 코드종료 ##


