#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int t;
    scanf("%d", &t);
    
    for(int i=0; i<t; i++){
        int r;
        char s[20];
        scanf("%d %s", &r, s);
        for(int j=0; j<strlen(s); j++){
            for(int k=0; k<r; k++){
                printf("%c", s[j]);
            }
        }
        printf("\n");
    }

    return 0;
}