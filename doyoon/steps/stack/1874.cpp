#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int seq[n];

    for(int i=0; i<n; i++) scanf("%d", &seq[i]);

    stack<int> s;
    vector<char> sign;
    int num = 1;
    bool impossible = false;
    for(int i=0; i<n; i++){
        //printf("i %d\n", i);
        if(num < seq[i]){
            while(num <= seq[i]){
                s.push(num);
                //printf("+\n");
                sign.push_back('+');
                num += 1;
            }
            s.pop();
            //printf("-\n");
            sign.push_back('-');
        }else if(num == seq[i]){
            s.push(num);
            //printf("+\n");
            sign.push_back('+');
            s.pop();
            //printf("-\n");
            sign.push_back('-');
            num += 1;
        }else{ // num > seq[i]
            bool found = false;
            while(!s.empty() && s.top() >= seq[i]){
                if(s.top()==seq[i]) found = true;
                s.pop();
                //printf("-\n");
                sign.push_back('-');
            }
            if(!found){
                impossible = true;
                break;
            }
        }
    }

    if(impossible){
        printf("NO");
    }else{
        for(int i=0; i<sign.size(); i++){
            printf("%c\n", sign[i]);
        }
    }


    return 0;
}

/*
8
4
3
6
8
7
5
2
1
*/