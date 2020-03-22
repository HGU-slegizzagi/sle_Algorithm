#include <iostream>
using namespace std;

int main(){

    int n ;
    cin >>n;
    int j;

    for(int i = 0 ; i <n-1;i++){

       for( j = 0; j < n-i-1; j++){
            cout << " ";
        }
        for( int k = 0; k < (2*n-1)-2*j; k ++){
            cout << "*";
        }
        
        cout << endl;
        
    }



    for(int i = 0 ; i < n;i++){
        //spacing    
        for( j = 0; j < i; j++){
            cout << " ";
        }
        //drawing
        for( int k = 0; k < (2*n-1)-j*2; k ++){
            cout << "*";
        }
        
        cout << endl;
        
    }

    
}