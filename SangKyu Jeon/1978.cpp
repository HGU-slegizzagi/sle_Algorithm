#include <iostream>
using namespace std;



int IsPrime(int isPrimeNumb){

    for( int j = 1 ; j <= isPrimeNumb/2; j++){
            if( isPrimeNumb%(j+1) == 0){
                return 0;
            }
    }
    return 1;

}


int main(){

    int n;
    int sum = 0;
    cin >> n;

    int number[n];

    for(int i = 0 ; i < n ; i++){
        cin >> number[i];
    }

    for(int i = 0 ; i < n ; i++){
        if(number[i] == 1){
            continue;
        }
        else if(number[i] == 2){
            sum++;
            continue;
        }
        else{
            sum += IsPrime(number[i]);
        }

    }

    cout << sum << endl;



}