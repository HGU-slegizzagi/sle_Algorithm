#include <iostream>
#include <stack>
#include <cstring>
using namespace std;



void decide(char* str){
    //cout << strlen(str) << endl;
    stack <int> s;
    int i = 0;
    int correct = true;
    while(str[i]!='\0'){
        //cout << "i " << i << endl;
        if(str[i]=='(') s.push(1);
        else if(str[i]=='[') s.push(2);
        else if(str[i]==')'){
            //cout << "case 3" << endl;
            if(s.empty()||s.top()==2){
                correct = false;
                break;
            }else s.pop();
        }else if(str[i]==']'){
            //cout << "case 4" << endl;
            if(s.empty()||s.top()==1){
                correct = false;
                break;
            }else s.pop();
        }
        i++;
    }
    if(!s.empty()) correct = false;
    if(correct) cout << "yes" << endl;
    else cout << "no" << endl;
}

int main(){
    char str[102];
    fgets(str,102, stdin);
    //scanf("%s", str);
    while(strcmp(str, ".\n")!=0){
        decide(str);
        fgets(str,102, stdin);
    }

    return 0;
}