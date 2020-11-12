#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);

    int stack[10000];
    int point = 0;
    char command[6];
    for(int i=0; i<n; i++){
        scanf("%s", command);
        if(strncmp(command, "push", 4)==0){
            int num;
            scanf("%d", &num);
            stack[point] = num;
            point+=1;
        }else if(strncmp(command, "pop", 3)==0){
            if(point==0) printf("-1\n");
            else{
                printf("%d\n", stack[point-1]);
                point-=1;
            }
        }else if(strncmp(command, "size", 4)==0){
            printf("%d\n", point);
        }else if(strncmp(command, "empty", 5)==0){
            if(point==0) printf("1\n");
            else printf("0\n");
        }else if(strncmp(command, "top", 3)==0){
            if(point==0) printf("-1\n");
            else printf("%d\n", stack[point-1]);
        }
    }

    return 0;
}