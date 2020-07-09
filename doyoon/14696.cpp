#include <iostream>
#include <algorithm>
using namespace std;

char gameResult(){
    char result = 'Z';
    int numa, numb;
    scanf("%d", &numa);
    int a[4], b[4];
    for(int i=0; i<4; i++){
        a[i] = 0;
        b[i] = 0;
    }
    for(int i=0; i<numa; i++){
        int temp;
        scanf("%d", &temp);
        a[temp-1]+=1;
    }
    
    scanf("%d", &numb);
    for(int i=0; i<numb; i++){
        int temp;
        scanf("%d", &temp);
        b[temp-1]+=1;
    }

    if(a[3]>b[3]){
        //printf("a[3] %d b[3] %d\n", a[3], b[3]);
        result = 'A';
    }else if(b[3]>a[3]){
        result = 'B';
    }else{
        if(a[2]>b[2]){
            result = 'A';
        }else if(b[2]>a[2]){
            result = 'B';
        }else{
            if(a[1]>b[1]){
                result = 'A';
            }else if(b[1]>a[1]){
                result = 'B';
            }else{
                if(a[0]>b[0]){
                    result = 'A';
                }else if(b[0]>a[0]){
                    result = 'B';
                }else{
                    result = 'D';
                }
            }
        }
    }

    /*cout << "a\n";
    for(int i=0; i<4; i++){
        printf("%d\t", a[i]);
    }printf("\n");
    cout << "b\n";
    for(int i=0; i<4; i++){
        printf("%d\t", b[i]);
    }printf("\n");*/

    return result;
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        cout << gameResult()<<endl;
    }

    return 0;
}