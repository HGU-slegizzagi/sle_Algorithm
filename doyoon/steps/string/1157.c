#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str[1000000];
    scanf("%s", str);

    int alpha[26];
    for(int i=0; i<26; i++) alpha[i] = 0;

    int len = strlen(str);
    for(int i=0; i<len; i++){
        if(str[i]<97) alpha[str[i]-65] += 1;
        else alpha[str[i]-97] += 1;
    }
    
    int same = 0;
    int max = alpha[0], maxIndex = 0;
    for(int i=1; i<26; i++){
        if(alpha[i] == max) same += 1;
        else if(alpha[i] > max){
            max = alpha[i];
            maxIndex = i;
            same = 0;
        }
    }

    if(same == 0) printf("%c", maxIndex+65);
    else printf("?");

    return 0;
}