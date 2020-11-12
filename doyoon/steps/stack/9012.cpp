#include <cstdio>
#include <stack>
using namespace std;

void checkp(){
    char p[51];
    scanf("%s", p);

    stack <char> par;
    bool correct = true;
    int i=0, l=0, r=0;
    while(p[i]!='\0'){
        if(p[i]=='(') par.push('l');
        else if(p[i]==')'){
            if(par.empty()){
                correct = false;
                break;
            }else{
                par.pop();
            }
        }
        i++;
    }
    if(!par.empty()) correct = false;
    if(correct) printf("YES\n");
    else printf("NO\n");
}

int main(){
    int t;
    scanf("%d", &t);

    for(int i=0; i<t; i++) checkp();

    return 0;
}