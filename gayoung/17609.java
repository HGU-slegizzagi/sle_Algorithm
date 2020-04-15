import java.util.Scanner;
//runtime error
class palin
{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        sc.nextLine();
        String[] strArray=new String[N];
        for(int i=0; i<N; i++){
            strArray[i]=sc.nextLine();
        }

        for(int i=0; i<N; i++){
            if(palin(strArray[i])) System.out.println(0);
            else if(pPalin(strArray[i])) System.out.println(1);
            else System.out.println(2);
        }
    }

    public static boolean palin(String str){
        int left=0;
        int right=str.length()-1;
        while(left<right){
            if(str.charAt(left)!=str.charAt(right)) return false;
            left++;
            right--;
        }
        return true;
    }

    public static boolean pPalin(String str){
        int cnt=0;
        int left=0;
        int ck=0;
        int right=0;
        int j=0;
        int fix=0;
        String[] subone=new String[str.length()-1];
        for(cnt=0; cnt<str.length(); cnt++){  //문자열의 길이만큼 반복함.
            String[] each=str.split("");
            j=0;
            for (int i=0; i<str.length(); i++){  //한개 문자를 숨긴 배열을 만드는 반복문
                if(i != fix){
                  subone[j]=each[i];
                  j++;
                }
            }
            fix++;
            String complete=String.join("",subone);   //그 문자가 담긴 배열을 다시 String으로 만듬

            //System.out.println("-->complete: "+complete);
            left=0; right=complete.length()-1; ck=0;  
            while(left<right){
                if(complete.charAt(left)==complete.charAt(right)) {
                    //System.out.println("->left:"+complete.charAt(left)+" / right:"+complete.charAt(right));
                    ck++;
                }
                left++;
                right--;
            }
            if(ck==(complete.length())/2) return true;

        }
        return false;
    }
}
