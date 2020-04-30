N=int(input())

sum=0


box=[0]*(5000+1)
for i in range(5001):
    box[i]=[]

for i in range(N):
    x,y=map(int,input().split())
    box[y].append(x)

for i in range(5001):
    box[i].sort()
    #print(box[i])
    for j in range(len(box[i])):
        #print("box[i][j] : ",box[i][j])
        #print(sum)
        if j==0:
            sum+=abs(box[i][j+1]-box[i][j])
            continue
        if j==(len(box[i])-1):
            sum+=abs(box[i][j]-box[i][j-1])
            continue
        if abs(box[i][j]-box[i][j-1])> abs(box[i][j]-box[i][j+1]):
            sum+=abs(box[i][j]-box[i][j+1])
        else:
            sum+=abs(box[i][j]-box[i][j-1])


print(sum)
