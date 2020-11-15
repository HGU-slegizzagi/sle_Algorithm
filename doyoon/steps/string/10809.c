#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char word[100];
    scanf("%s", word);
    int count[26];
    for(int i=0; i<26; i++) count[i] = -1;
    for(int i=0; i<strlen(word); i++){
        //printf("i %d", i);
        //printf("%d\n", word[i]-97);
        if(count[word[i]-97] == -1){
            count[word[i]-97] = i;
        }
    }

    for(int i=0; i<26; i++) printf("%d ", count[i]);

    return 0;
}