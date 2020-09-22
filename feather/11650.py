N=int(input())
s=[[0 for i in range(2)] for i in range(N)]

for i in range(N):
    s[i][0],s[i][1]=map(int,input().split())

s.sort()

for i in range(N):
    print(s[i][0],s[i][1])
