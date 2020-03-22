#include <iostream>
using namespace std;

const int SIZE  = 27;

void cleanUp(int** map,int sx,int sy, int size){

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            map[sx+i][sy+j] = 0;
        }
    }
}

void evade(int** map,int sx, int sy, int size){

    if(size/3 < 1){
        return;
    }
    

    for(int i = 0; i < size; i+=size/3){
        for(int j = 0; j < size; j+=size/3){
            evade(map,sx+i,sy+j,size/3);
        }
    }

    cleanUp(map,sx+size/3,sy+size/3,size/3);


}



int main(){




    int size = SIZE;
    
    cin >> size;


    

    int** map = new int*[size];
    for(int i = 0; i < size; ++i){
        map[i] = new int[size];
    }


    for(int i = 0; i<size; i++){
        for(int j = 0; j<size;j++){
            map[i][j] = 1;
        }
    }

    evade(map,0,0,size);

    for(int i = 0; i<size; i++){
        for(int j = 0; j<size;j++){
            // cout <<map[i][j];
            if(map[i][j] == 1){
                cout <<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout << endl;
    }



}
