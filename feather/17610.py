# this code is from https://ai-information.blogspot.com/2020/03/problem-httpswww.html

k=int(input())
gk_list=list(map(int,input().split()))
gk_list.sort()

S=sum(gk_list)

def func(gk_list):
    if len(gk_list)==0:
        return 0
    if len(gk_list)==1:
        return gk_list

    pre_possible=func(gk_list[:-1])
    sum_possible=[x+gk_list[-1] for x in pre_possible]
    minus_possible=[abs(gk_list[-1]-x) for x in pre_possible]
    new_possible=[gk_list[-1]]

    total_possible= pre_possible + sum_possible + minus_possible + new_possible
    result_list=[x for x in total_possible if x>0]
    result_list=list(set(result_list))
    return result_list


answer = S-len(func(gk_list))
print(answer)
