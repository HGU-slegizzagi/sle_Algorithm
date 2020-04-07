#include <iostream>
using namespace std;

int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}}; //right,left,down, up

void Check(string *map, int **checkMap, int y, int x, int *kv,  int row,int column){



 
    for(int i = 0; i < 4; i++){

        if(x+dir[i][0] >= column || x+dir[i][0] < 0 ||y+dir[i][1] >= row || y+dir[i][1] < 0){
            return ;
        }
        if(map[y+dir[i][1]][x+dir[i][0]] != '#' && checkMap[y+dir[i][1]][x+dir[i][0]] != 1){
            if(map[y+dir[i][1]][x+dir[i][0]] == 'k'){
                kv[0]++;
            }
            else if(map[y+dir[i][1]][x+dir[i][0]] == 'v'){
                kv[1]++;
            }
            
            checkMap[y+dir[i][1]][x+dir[i][0]] = 1;
            Check(map,checkMap,y+dir[i][1],x+dir[i][0],kv,row,column);
        }
    }

    return;
}


int main(){

    int column;
    int row;
    string *map;
    int **checkMap;
    int k = 0;
    int v = 0;
    int * kv = new int [2];


    cin >> row;
    cin >> column;

    
    map = new string[row];
    checkMap = new int*[row];

    for(int i = 0; i < row; i++){
        cin >> map[i];
        checkMap[i] = new int [column];
        for(int j = 0 ; j < column; j++){
            checkMap[i][j] = 0;
        }
    }


    kv[0] = 0;
    kv[1] = 0;

    for(int i = 0; i < row; i++){
        for(int j = 0 ; j < column; j++){

            if(map[i][j] != '#' && checkMap[i][j] != 1){
                
                if(map[i][j] == 'k'){
                    kv[0]++;
                }
                else if(map[i][j] == 'v'){
                    kv[1]++;
                }
                
                checkMap[i][j] = 1;
                Check(map,checkMap,i,j,kv,row,column);
        
                if(kv[0] > kv[1]){
                    k += kv[0];
                }
                else{
                    v += kv[1];
                }

                kv[0] = 0;
                kv[1] = 0;
            }
        }
    }

    cout << k << " " << v << endl;


}