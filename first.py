#ex01
hours = input("Enter your hours: ")
hours = float(hours)
rate = input("Enter your rate per hour:")
rate = float(rate)
print("your money : ",hours*rate)

#ex02 조건문
sh = input("Enter Hours: ")
sr = input("Enter Rate: ")
try:
    fh = float(sh)
    fr = float(sr)
except:
    print("Error, please enter numeric input")
    quit()
#print(fh, fr)
if fh > 40 :
	#print("Overtime")
	reg = fr * fh
	otp = (fh - 40.0) * (fr * 0.5)
	#print(reg, otp)
	xp = reg + otp
else:
	#print("regular")
	xp = fh * fr
print("Pay:", xp)



#ex03 함수
def computepay(hours, rate):
    if hours > 40:
        reg = rate * hours
        otp = (hours - 40.0) * (rate * 0.5)
        pay = reg + otp
    else:
        pay = hours * rate
    return pay

sh = input("Enter Hours: ")
sr = input("Enter Rate: ")
fh = float(sh)
fr = float(sr)

xp = computepay(fh, fr)

print("Pay: ", xp)  

#ex04 루프와 반복문
num=0
tot =0.0
while True:
    sval = input ("Enter a number: ")
    if sval == 'done':
        break
    try:
        fval=float(sval)
    except:
        print('Invaild input')
        continue  #return first loop 
    #print(sval)
    num = num + 1
    tot = tot + fval #sum
    
print("ALL DONE")
print(tot,num,tot/num)


#ex05 문자열파싱
str = 'X-DSPM-Confidence: 0.8475'

ipos=str.find(':')
piece = str[ipos+2:]
print(piece)
value = float(ipos)
print(value)


#ex06 파일
fh=open('mbox-short.txt')
print(fh)

for lx in fh:
    ly = lx.rstrip()
    print(ly.upper())



#ex07 리스트
han = open('mbox-short.txt')

for line in han:
    line = line.rstrip()     # 줄의 오른쪽 \n을 제거
    wds = line.split()       # 줄별 공백으로 분리
    #guardian in a compound statement
    if len(wds)<3 or wds[0] != 'From':    #len먼저 확인후 wds[0]을 확인한다. 순서가 바뀌면 오류발생
        continue
    print(wds[2])




#ex09 딕셔너리
fname = input('Enter File:')
if len(fname) < 1 : fname= 'clown.txt'
hand = open(fname)

di = dict()
for lin in hand:
    lin = lin.rstrip()
    #print(lin)
    wds = lin.split()
    #print(wds)
    for w in wds:
       di[w] = di.get(w,0) + 1
       #print(w,'NEW',di[w])
#print(di)

#now we want to find the most common word
largest = -1
theword = None
for k,v in di.items():
    if v> largest:
        largest = v
        theword = k
print('Done',theword,largest)


#ex10 tuple
fname = input('Enter File:')
if len(fname) < 1 : fname= 'clown.txt'
hand = open(fname)

di = dict()
for lin in hand:
    lin = lin.rstrip()
    wds = lin.split()
    for w in wds:
       di[w] = di.get(w,0) + 1

tmp=list()
for k,v in di.items():
    newt=(v,k)
    tmp.append(newt)
    
#print('Flipped',tmp)

tmp= sorted(tmp,reverse=True)
#print('sorted',tmp)

for v,k in tmp[:5]:
    print(v,k)

