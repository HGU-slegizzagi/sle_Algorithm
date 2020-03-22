#include <iostream>
using namespace std;

int main(){


    int big;
    int small;
    int temp;


    cin >> big;
    cin >> small;

    if(big < small){
        temp = big;
        big = small;
        small = temp;
        
    }
    else if(big == small){
        cout << big << endl;
        cout << big << endl;
        return 0;
    }
    
    int gcd;
    int lcm;
    //gcd
    for(int i = 1; i < big; i++){
        if((big%i ==0) && (small%i == 0)){
            gcd = i;
        }
    }

    cout << gcd << endl;

    //최소공배수
    int i = 1;
    int a = small;
    while(1){
        a = small * i;
        if(a%big == 0){
            lcm =a;
            break;
        }
        i++;
    }

    cout << lcm << endl;


}