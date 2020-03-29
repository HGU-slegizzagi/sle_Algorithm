N,M=map(int,input().split()) 

O=[[int(x) for x in input().split()] for y in range(N)]

def check(x):
    if x==1:
        print("z")




def counter(X,num):
    min=1000
    O=X.copy()
    
    


def zero_counter(x):
    count=0
    for i in range(N):
        for j in range(M):
            if O[i][j]==0:
                count+=1
    return count


for i in range(N):
    for j in range(M):
        if O[i][j] == 0:
            continue
        check(O[i][j])
    print()



