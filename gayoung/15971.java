import java.util.Scanner;
class Main{
    public static void main(String[] args){
        Scanner sc= new Scanner(System.in);
        int[] gradeArray=new int [sc.nextInt()];

        int max=Integer.MIN_VALUE;
        int min=Integer.MAX_VALUE;
        for (int i=0; i<gradeArray.length; i++){
            gradeArray[i]=sc.nextInt();
            if (gradeArray[i]>max) max=gradeArray[i];
            if (gradeArray[i]<min) min=gradeArray[i];
        }
        
        int gap=max-min;
        System.out.println(gap);
    }
}
