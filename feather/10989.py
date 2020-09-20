import sys
N=int(sys.stdin.readline())
s=[0]*10001

for i in range(N):
    s[int(sys.stdin.readline())]+=1
    
for idx in range(1,10001):
    print((str(idx)+'\n')*s[idx],end='')
 
