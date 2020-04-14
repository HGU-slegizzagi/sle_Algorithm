import java.util.Scanner;
class Main{
    public static void main(String[] args){
        Scanner sc= new Scanner(System.in);
        int accumulate=0, cnt=1;  
        int N=sc.nextInt(); 

        int[] stickSize=new int[N];
        for(int i=0; i<N; i++){ 
            stickSize[i]=sc.nextInt();
        }
        
        accumulate=stickSize[N-1];
        for(int i=N-2; i>=0; i--){
            if(accumulate<stickSize[i]) {
                accumulate=stickSize[i];
                cnt++;
            }
        }
        System.out.println(cnt);
    }
}
