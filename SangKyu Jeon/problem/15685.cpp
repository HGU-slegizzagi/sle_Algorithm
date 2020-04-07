#include <iostream>
#include <stack>
using namespace std;


const int rotateMatrix[2][2] = {{0,-1},{1,0}};
const int size = 1000;

class Points{
    public:
        int x;
        int y;

    Points(){
        x = 0;
        y = 0;
    }

    Points(int x, int y){
        this->x = x;
        this->y = y;
    }

};


int ChecRec(int map[][size],int x, int y){

    if(y+1 > size || x+1 > size){
        return 0;
    }
    
    if(map[y][x] == 1 && map[y][x+1] == 1 && map[y+1][x+1] == 1 && map[y+1][x] == 1){
        return 1;
    }
    
    return 0;

}

void RotateTranslate(stack<Points*>& mapInfo){

    stack<Points*> tempMapInfo(mapInfo); 


    //distance
    Points* lastPoint =  tempMapInfo.top();
    
    int a =lastPoint->x - (rotateMatrix[0][0]*lastPoint->x+rotateMatrix[0][1]*lastPoint->y);
    int b =lastPoint->y - (rotateMatrix[1][0]*lastPoint->x+rotateMatrix[1][1]*lastPoint->y);
    

    Points * distancePoints = new Points(a,b);


    //rotate translate
    tempMapInfo.pop();
    while(!tempMapInfo.empty()){
        Points* tempPoint = tempMapInfo.top();
        tempMapInfo.pop();

        //rotate
        int ta = rotateMatrix[0][0]*tempPoint->x+rotateMatrix[0][1]*tempPoint->y+distancePoints->x;
        int tb = rotateMatrix[1][0]*tempPoint->x+rotateMatrix[1][1]*tempPoint->y+distancePoints->y;

        mapInfo.push(new Points(ta,tb));

    }


}


//  4
// 3 3 0 1
// 4 2 1 3
// 4 2 2 1
// 2 7 3 4


int main(){

    stack <Points*> finalMapInfo;
    stack <Points*> mapInfo;

    int map[size][size];
    for(int i = 0; i < size; i++){
        for(int j = 0 ; j < size; j++){
            map[i][j] = 0;
        }
    }

    int curveNum;

    cin >> curveNum;

    int **curveInfo;

    curveInfo = new int*[curveNum];
    for(int i  = 0 ; i < curveNum; i++){
        curveInfo[i] = new int[4];
    }

    for(int i = 0; i < curveNum; i++){
        cin >> curveInfo[i][0];
        cin >> curveInfo[i][1];
        cin >> curveInfo[i][2];
        cin >> curveInfo[i][3];
    }


///

    for(int i = 0; i < curveNum; i++){
        mapInfo.push(new Points(curveInfo[i][0],curveInfo[i][1]));
        
        switch(curveInfo[i][2]){
            case 0:{
                mapInfo.push(new Points(curveInfo[i][0]+1,curveInfo[i][1]));
                break;
            }
            case 1:{
                mapInfo.push(new Points(curveInfo[i][0],curveInfo[i][1]-1));                
                break;
            }
            case 2:{
                mapInfo.push(new Points(curveInfo[i][0]-1,curveInfo[i][1]));
                break;
            }
            case 3:{
                mapInfo.push(new Points(curveInfo[i][0],curveInfo[i][1]+1));
                break;
            }
            default:{
                break;
            }
        }
        
        for(int k = 0 ; k < curveInfo[i][3]; k++){
            RotateTranslate(mapInfo);
        }

        while(!mapInfo.empty()){
            finalMapInfo.push( mapInfo.top());
            mapInfo.pop();
        }

    }
    
    while(!finalMapInfo.empty()){
        Points* tempP = finalMapInfo.top();
        // cout << "x: " << tempP->x << "  y:" << tempP->y << endl;
        map[tempP->y+size/2][tempP->x+size/2] = 1;
        finalMapInfo.pop();

    }
//ChecRec
    int rec = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0 ; j < size; j++){
            if(map[i][j] == 1){
                rec+=ChecRec(map,j,i);
            }
        }
        
    }

    cout <<rec<< endl;

}