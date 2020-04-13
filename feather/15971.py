# 실패 
 - 다익스트라 비슷하길래 그걸로 짜려다가 시간 오버 하..

<!--
import sys 

def dijkstra(K,V,graph):
    INF=sys.maxsize
    s=[False]*V
    d=[INF]*V
    d[K-1]=0
    while True:
        m=INF
        N=-1

        for j in range(V):
            if not s[j] and m>d[j]:
                m=d[j]
                N=j 

        if m==INF:
            break

        s[N]=True

        for j in range(V):
            if s[j]: continue
            via=d[N]+graph[N][j]
            if d[j] > via:
                d[j] = via 
    return d 




INF=sys.maxsize

V,X,Y=map(int,(input().split()))
graph=[[INF]*(V) for _ in range(V)]

for _ in range(V-1):
    u,v,w=map(int,input().split())
    graph[u-1][v-1]=w
    graph[v-1][u-1]=w

for i in range(V-1):
    for j in range(V-1):
        print(graph[i][j] if graph[i][j]!=INF else "INF",end=' ')
    print()

#for d in dijkstra(1,V,graph):
#    print(d if d!= INF else "INF", end= ' ')

d=dijkstra(1,V,graph)
print(d)




-->
