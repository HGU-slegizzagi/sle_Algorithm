#include <iostream>
using namespace std;

int main(){

    int n ;
    cin >>n;
    int j;


    for(int i = 0; i < n-1; i++){
        for(int j = 0; j <= i; j++){
            cout << "*" ;
        }

        for(int j = 0; j < 2*n-2*(i+1); j++){
            cout << " " ;
        }

        for(int j = 0; j <= i; j++){
            cout << "*" ;
        }
        cout << endl;
    }

    for(int i = 0; i < 2*n; i++){
        cout << "*";
    }
    cout << endl;

    /*-----*/
    for(int i = n-1 ; i > 0; i--){

        for(int j = i; j > 0; j--){
            cout << "*" ;
        }

        for(int j = 0; j < 2*n-2*(i); j++){
            cout << " " ;
        }

        for(int j = i; j > 0; j--){
            cout << "*" ;
        }
        cout << endl;
    }


}