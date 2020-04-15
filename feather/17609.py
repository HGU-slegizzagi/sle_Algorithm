# 시간초과
# O(n^2)인데 다른 사람은 되던데.. 나도 같은데 왜 안되지..

def sol(S):
    ans=0
    if check(S)==0:
        return 0
    
    for i in range(len(S)):
        S_list=list(S)
        tmp=''
        S_list.pop(i)
        tmp+=''.join(S_list)
        if check(tmp)==0:
            return 1


    return 2

def check(S):
    for i in range(int(len(S)/2)):
        if i==(len(S)-1-i):
            break
        if S[i]==S[len(S)-1-i]:
            continue
        else :
            return 1
            

    return 0


T=int(input())

for i in range(T):
    S=input()
    print(sol(S))
