N=int(input())
  
G=list(map(int,input().split()))
G.sort()
print(G[-1]-G[0])
