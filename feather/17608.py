import sys 

N=int(input())
L=[]
for i in range(N):
    L.append(int(sys.stdin.readline()))

count=1
tmp=L[N-1]
for i in range(N-1,0,-1):
    if L[i-1] > tmp:
        count+=1
        tmp=L[i-1]
print(count)
