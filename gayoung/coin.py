pay=int(input(''))
change=1000-pay
clist=[500,100,50,10,5,1]
n=0
while change>0:
    for i in clist:
        coin=change//i
        n+=coin
        change=change%i
print (n)

