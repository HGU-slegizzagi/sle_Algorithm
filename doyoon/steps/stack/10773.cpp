#include <iostream>
#include <stack>
using namespace std;

int main(){
    int k;
    scanf("%d", &k);

    stack <int> s;
    int num;
    for(int i=0; i<k; i++){
        scanf("%d", &num);
        if(num==0){
            s.pop();
        }else{
            s.push(num);
        }
    }

    int sum = 0;
    while(!s.empty()){
        num = s.top();
        s.pop();
        sum += num;
    }

    cout << sum;

    return 0;
}