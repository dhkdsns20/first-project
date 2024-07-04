# 필요한 라이브러리를 불러옵니다.
import random
import numpy as np

# 학번을 변수에 저장합니다.
student_id = 2020037087

# 0과 1을 랜덤하게 생성하여 1kbyte 크기의 데이터를 만듭니다.
# 1kbyte는 8*1024개의 비트를 의미하므로, 이만큼의 랜덤한 0과 1을 생성합니다.
data = np.random.randint(2, size=8*1024)

# 생성한 데이터를 binary 파일로 저장합니다.
# 파일 이름은 'data_학번.bin' 형식으로 합니다.
with open(f'data_{student_id}.bin', 'wb') as f:
    f.write(data.tobytes())

# 파일이 성공적으로 저장되었음을 알립니다.
print("파일이 성공적으로 저장되었습니다.")

# 필요한 라이브러리를 불러옵니다.
import binascii

# CRC 다항식을 정의합니다.
CRC_16_POLY = 0x11021  # 10001000000100001
CRC_32_POLY = 0x104C11DB7  # 100000100110000010001110110110111

# 데이터를 바이트 배열로 변환합니다.
data_bytes = data.tobytes()

# CRC-16을 계산합니다.
crc16 = binascii.crc_hqx(data_bytes, 0xffff)
crc16_result = crc16.to_bytes(2, 'big')

# CRC-32를 계산합니다.
crc32 = binascii.crc32(data_bytes) & 0xffffffff
crc32_result = crc32.to_bytes(4, 'big')

# CRC-16 결과를 데이터 끝에 첨부하고 binary 파일로 저장합니다.
with open(f'data_{student_id}_16.bin', 'wb') as f:
    f.write(data_bytes + crc16_result)

# CRC-32 결과를 데이터 끝에 첨부하고 binary 파일로 저장합니다.
with open(f'data_{student_id}_32.bin', 'wb') as f:
    f.write(data_bytes + crc32_result)

# 파일이 성공적으로 저장되었음을 알립니다.
print("파일이 성공적으로 저장되었습니다.")

# 필요한 라이브러리를 불러옵니다.
import random

# 비트 에러를 삽입할 위치를 랜덤하게 선택합니다.
error_positions_16 = random.sample(range(len(data_bytes)), 2)
error_positions_32 = random.sample(range(len(data_bytes)), 2)

# 선택한 위치에 비트 에러를 삽입합니다.
data_bytes_error_16 = bytearray(data_bytes)
for pos in error_positions_16:
    data_bytes_error_16[pos] ^= 0x01  # XOR 연산을 통해 비트를 반전시킵니다.

data_bytes_error_32 = bytearray(data_bytes)
for pos in error_positions_32:
    data_bytes_error_32[pos] ^= 0x01  # XOR 연산을 통해 비트를 반전시킵니다.

# 비트 에러가 삽입된 데이터에 대해 CRC-16과 CRC-32를 다시 계산합니다.
crc16_error = binascii.crc_hqx(data_bytes_error_16, 0xffff)
crc32_error = binascii.crc32(data_bytes_error_32) & 0xffffffff

# 계산된 CRC와 원래의 CRC를 비교하여 어떻게 달라졌는지 파악합니다.
print(f"CRC-16: 원래 {crc16}, 에러 삽입 후 {crc16_error}")
print(f"CRC-32: 원래 {crc32}, 에러 삽입 후 {crc32_error}")

