#include <iostream>
using namespace std;

int main(){

    int n ;
    cin >>n;
    int j;


    //1
    for(int i = 0; i < n-1 ; i++){

        for(int j = 0; j < i; j++){
            cout << " ";
        }

        for(int j = 0; j <2*n-1-2*i; j++){
            cout << "*";
        }

        cout << endl;


    }
    
    for(int j = 0; j <n-1; j++){
        cout << " ";
    }
    cout << "*" << endl;

    //3
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < n-i; j++){
            cout << " ";
        }
        for(int j=0; j < 3+(2*(i-2));j++){
            cout << "*";
        }
        cout << endl;
    }


}