#include <iostream>
#include <vector>
using namespace std;


static int n, m;

class CCTV{

    public:
        int type;
        int dir;
        int x;
        int y;

    CCTV(int y, int x,int type){
    
        this -> x = x;
        this -> y = y;
        this -> type = type;
        this -> dir = 1;
    }

    void Turn(){
        if(dir+1 > 4){
            dir = 1;
        }
        else{
            dir++;
        }
    }

    void Watch(int **map){
        
        switch(type){
            case 1:{
                switch(dir){
                    case 1:{
                        WatchRight(map);
                        break;
                    }
                    case 2:{
                        WatchUp(map);
                        break;
                    }
                    case 3:{
                        WatchLeft(map);
                        break;
                    }
                    case 4:{
                        WatchDown(map);
                        break;
                    }
                }

                break;
            }
             case 2:{
                 switch(dir){
                    case 1:{
                        WatchLeft(map);
                        WatchRight(map);
                        break;
                    }
                    case 2:{
                        WatchUp(map);
                        WatchDown(map);
                        break;
                    }

                    case 3:{
                        WatchLeft(map);
                        WatchRight(map);
                        break;
                    }
                    case 4:{
                        WatchUp(map);
                        WatchDown(map);
                        break;
                    }
                }
                break;
            }
            case 3:{
                 switch(dir){
                    case 1:{
                        WatchRight(map);
                        WatchUp(map);
                        break;
                    }
                    case 2:{
                        WatchUp(map);
                        WatchLeft(map);
                        break;
                    }
                    case 3:{
                        WatchLeft(map);
                        WatchDown(map);
                        break;
                    }
                    case 4:{
                        WatchRight(map);
                        WatchDown(map);
                        break;
                    }
                }

                break;
            }
             case 4:{
                 switch(dir){
                    case 1:{
                        WatchRight(map);
                        WatchUp(map);
                        WatchLeft(map);
                        break;
                    }
                    case 2:{
                        WatchUp(map);
                        WatchLeft(map);
                        WatchDown(map);
                        break;
                    }
                    case 3:{
                        WatchRight(map);
                        WatchLeft(map);
                        WatchDown(map);
                        break;
                    }
                    case 4:{
                        WatchRight(map);
                        WatchUp(map);
                        WatchDown(map);
                        break;
                    }
                }

                break;
            }
             case 5:{
                WatchRight(map);
                WatchUp(map);
                WatchDown(map);
                WatchLeft(map);

                break;
            }
            default :{

                break;
            }

        }
      

    }

    void WatchRight(int **map){

        int mapRows = n;
        int mapCols = m;

        for(int j = this -> x+1 ; j < mapCols; j++){
            //none
            if(map[this -> y][j] == 0){
                map[this -> y][j] = 9;
            }
            else if(map[this -> y][j] != 6){
                //cctv
                continue;
            }
            else if(map[this -> y][j] == 6){
                //block
                break;
            }
        }
    }

    void WatchLeft(int **map){

        int mapRows = n;
        int mapCols = m;

        for(int j = this -> x-1 ; j >= 0; j--){
            //none
            if(map[this -> y][j] == 0){
                map[this -> y][j] = 9;
            }
            else if(map[this -> y][j] != 6){
                //cctv
                continue;
            }
            else if(map[this -> y][j] == 6){
                //block
                break;
            }
        }
    }

    void WatchUp(int **map){

        int mapRows = n;
        int mapCols = m;

        for(int j = this -> y-1 ; j >= 0; j--){
            //none
            if(map[j][this -> x] == 0){
                map[j][this -> x] = 9;
            }
            else if(map[j][this -> x] != 6){
                //cctv
                continue;
            }
            else if(map[j][this -> x] == 6){
                //block
                break;
            }
        }
    }

    void WatchDown(int **map){

        int mapRows = n;
        int mapCols = m;
        for(int j = this -> y+1 ; j < mapRows; j++){
            //none
            if(map[j][this -> x] == 0){
                map[j][this -> x] = 9;
            }
            else if(map[j][this -> x] != 6){
                //cctv
                continue;
            }
            else if(map[j][this -> x] == 6){
                //block
                break;
            }
        }
    }
};


int CalMap(int **map){
    int mapRows = n;
    int mapCols = m;

    int sum = 0;
    // cout << endl;

    for(int i = 0 ; i < mapRows; i++){
        for(int j = 0 ; j < mapCols; j++){
            // cout << map[i][j] ;
            if( map[i][j] == 0){
                sum++;
            }
        }
        // cout << endl;
    }

    return sum;

}
void CopyMap(int **newMap, int **origMap){

    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m; j++){
            newMap[i][j] = origMap[i][j] ;
        }
    }
}

int Check(vector<CCTV> cctvs, int **map,int index,int sum){

    int **beforeMap;

    beforeMap = new int*[n];
    for(int i = 0 ; i < n; i++){
        beforeMap[i] = new int[m];
    }

     //watc

    if(index > 0){
        cctvs[index-1].Watch(map);
    }

    CopyMap(beforeMap,map);

    if(index >= cctvs.size()){
        //check map and return
        int result = CalMap(map);

        if(sum < result){
            return sum;
        }
        else{
            return result;
        }
    }

    
    //first turn
    sum = Check(cctvs,map,index+1,sum);
    cctvs[index].Turn();
    CopyMap(map,beforeMap);

    //second turn
    sum = Check(cctvs,map,index+1,sum);
    cctvs[index].Turn();
    CopyMap(map,beforeMap);
    
    //third turn
    sum = Check(cctvs,map,index+1,sum);
    cctvs[index].Turn();
    CopyMap(map,beforeMap);
    
    //fourth turn
    sum = Check(cctvs,map,index+1,sum);
    cctvs[index].Turn();
    CopyMap(map,beforeMap);

    return sum;
}



int main(){

    
    cin >> n;
    cin >> m;
    int ** map;

    vector<CCTV> cctvs;
    

    map = new int*[n];
    cctvs.push_back(CCTV(0,0,0));
    for(int i = 0 ; i < n; i++){
        map[i] = new int[m];
        for(int j = 0 ; j < m; j++){
            cin >> map[i][j];
            if(map[i][j] != 0 && map[i][j] != 6){
                cctvs.push_back(CCTV(i,j,map[i][j]));
            }

        }
    }



    //done with map
    cout << Check(cctvs,map,0,(n+1)*(m+1)) << endl;




}