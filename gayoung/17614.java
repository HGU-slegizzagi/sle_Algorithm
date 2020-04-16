import java.util.Scanner;
//시간초과
//문자비교: StringUtils 

class Main
{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int cnt=0;
        String strNum;
        for(int num=1; num<=N; num++){
            strNum=Integer.toString(num);
            String[] tmp=strNum.split("");
            
            int i=0;
            do{
            if(tmp[i].equals("3") || tmp[i].equals("6") || tmp[i].equals("9")) cnt++;
            
            i++;
            }while(i<strNum.length());
        }
        System.out.println(cnt);
    }
}
