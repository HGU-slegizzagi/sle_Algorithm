#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str[1000000];
    int total = 0;
    while(scanf("%s", str)!=EOF){
        printf("%s", str);
        total+=1;
    };
    
    printf("%d", total);
    
    

    return 0;
}