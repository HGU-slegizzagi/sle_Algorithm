import java.util.Scanner;
import java.lang.Math;
class Main{
    static int k=0;
    static int[] D;
    static int[] getWeight;
    public static void main(String[] agrs)
    {
        Scanner sc=new Scanner(System.in);
        k=sc.nextInt();
        int cnt=0; //가능한 조합 경우수
        getWeight = new int[k];
        D=new int[//백준 서버채점하면 런타임에러 뜨는데 왜일까요
import java.util.Scanner;
import java.lang.Math;
class Main{
    static int k=0;
    static int[] D;
    static int[] getWeight;
    public static void main(String[] agrs){
        Scanner sc=new Scanner(System.in);
        k=sc.nextInt();
        int cnt=0; //가능한 조합 경우수
        getWeight = new int[k];
        D=new int[2600001];

        int sum=0;
        for(int i=0; i<k; i++){
            getWeight[i]=sc.nextInt();
            sum+=getWeight[i];
        }
        dfs(0,0);
        for (int i=0; i<sum ;i++) cnt += D[i]; //초기화
        System.out.println(sum-cnt);


    }
    public static void dfs(int step, int weight){
        D[weight]=1;
        if(step>=k) return;
        dfs(step+1,weight);
        dfs(step+1,weight+getWeight[step]);
        dfs(step+1,Math.abs(weight-getWeight[step]));
    }
}];

        int sum=0;
        for(int i=0; i<k; i++){
            getWeight[i]=sc.nextInt();
            sum+=getWeight[i];
        }
        dfs(0,0);
        for (int i=0; i<sum ;i++) cnt += D[i]; //초기화
        System.out.println(sum-cnt);
    }
    
    public static void dfs(int step, int weight)
    {
        D[weight]=1;
        if(step>=k) return;
        dfs(step+1,weight);
        dfs(step+1,weight+getWeight[step]);
        dfs(step+1,Math.abs(weight-getWeight[step]));
    }
}
