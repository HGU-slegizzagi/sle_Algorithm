import sys 

N=int(sys.stdin.readline())
s=[0]*10001

for i in range(N):
    s[int(sys.stdin.readline())]+=1
 
idx=1
while True:
    if idx==10001:
        break
    if s[idx]==0:
        idx+=1
        continue
    print((str(idx)+'\n')*s[idx],end='')
    idx+=1
