#include <iostream>
using namespace std;



void Kaprekar(int* checkList, int numb, int range ){

    if(numb > range){
        return;
    }

    int  result = numb;
    int temp = numb;
    
    for(int i = 0; i < to_string(temp).length(); i++){
        result += numb%10;
        numb = int(numb/10);
    }

    // cout << result << endl;
    if(result > range){
        return;
    }

    checkList[result] = 1;
    Kaprekar(checkList,result,range);

}

int main(){


    int range = 10000;
    int checkList[range+1];

    for(int i = 1; i <= range; i++){
        checkList[i] = 0;
    }

    // Kaprekar(checkList,3,range);

    for(int i = 1; i <= range; i++){
        if(checkList[i] == 0){
            Kaprekar(checkList,i,range);
        }
    }


    for(int i = 1; i <= range; i++){
        if(checkList[i] == 0){
            cout << i << endl;
        }
    }


}
