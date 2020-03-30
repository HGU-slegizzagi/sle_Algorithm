K=int(input())

bucket=[]

for i in range(K):
    N=int(input())
    bucket.append(N)
    if N==0:
        bucket.pop()
        bucket.pop()

sum=0
for i in bucket:
    sum+=i
    
print(sum)
