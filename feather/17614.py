# 시간초과.. 

N=int(input())
ans=[0]*1000001

for i in range(1,N+1):
    count=0
    tmp=list(str(i))
    for j in range(len(tmp)):
        if tmp[j]=='3' or tmp[j]=='6' or tmp[j] =='9':
            count+=1
    
    ans[i]=ans[i-1]+count 
 
print(ans[N])



# 정답 코드 
# 위 내용과 같은 코드 python3 to Java 

import java.util.Scanner;
//시간초과
//문자비교: StringUtils 

class Main
{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[] ans = new int[1000001];
        int count=0;
        String tmp;
        for(int i=1; i<=N; i++){
            tmp = Integer.toString(i);
            int len=tmp.length();
            count=0;
            for(int j=0; j<len;j++){
                if('3'==tmp.charAt(j)|| '6'==tmp.charAt(j) || '9'==tmp.charAt(j))
                        count+=1;
                }   
            ans[i]=ans[i-1]+count;
                
        }   
        System.out.println(ans[N]);
    }   
}
