#include <iostream>
using namespace std;



class Map{
    public:
        int width;
        int height;
        int ** mapValue;

        int diceX;
        int diceY;

    Map(int height, int width, int diceY, int diceX){
        
        this -> height = height;
        this -> width = width;

        this -> diceX = diceX;
        this -> diceY = diceY;

        mapValue = new int*[height];
        for(int i = 0; i < height;i++){
                mapValue[i] = new int[width];
                for(int j = 0; j < width; j++){
                    cin >> mapValue[i][j];
                }        
        }
        mapValue[diceY][diceX] = 0;

    }

    void PrintMap(){
        for(int i = 0; i < height;i++){
                for(int j = 0; j < width; j++){
                    cout << mapValue[i][j];
                }        
                cout << endl;
        }
    }

    int GetValue(){
        return mapValue[diceY][diceX];
    }
    void SetValue(int value){
        mapValue[diceY][diceX] = value;
    }

    bool MoveDice(int dir){
        switch(dir){
            case 1:{
                //동
                if(diceX+1 >= width){
                    return false;
                }
                else{
                    diceX += 1;
                }
                break;
            }
            case 2:{
                //서
                if(diceX-1 < 0){
                    return false;
                }
                else{
                    diceX -= 1;
                }
                break;
            }
            case 3:{
                //북
                if(diceY-1 < 0){
                    return false;
                }
                else{
                    diceY -= 1;
                }
                break;
            }
            case 4:{
                //남
                if(diceY+1 >= height){
                    return false;
                }
                else{
                    diceY += 1;
                }
                break;
            }
            default:{
                return false;
                break;
            }
        }

        return true;
    }

};

class Dice{


    public:
        //vert[0] is top
        //vert[2] is bottom
        int hori[4];
        int vert[4];

        int value[6];

    
    Dice(){
        for(int i = 0 ; i < 6; i++){
            value[i] = 0;
        }

        hori[0] = 4;
        hori[1] = 5;
        hori[2] = 3;
        hori[3] = 2;

        vert[0] = 1;
        vert[1] = 5;
        vert[2] = 6;
        vert[3] = 2;
    }

    void Roll(int dir, Map* map){

        int temp;
        switch(dir){
            case 1:{
                //동
                temp = hori[0];
                hori[0] =vert[2];
                vert[2] = hori[2];
                hori[2]=vert[0];
                vert[0]= temp;
                break;
            }
            case 2:{
                //서
                temp = hori[0];
                hori[0] = vert[0];
                vert[0] = hori[2];
                hori[2] = vert[2];
                vert[2] = temp;
                break;
            }
            ///
            case 3:{
                //북
                temp = vert[3];
                vert[3] = vert[2];
                vert[2] = vert[1];
                vert[1] = vert[0];
                vert[0] = temp;
                break;
            }
            case 4:{
                //남
                temp = vert[0];
                vert[0] = vert[1];
                vert[1] = vert[2];
                vert[2] = vert[3];
                vert[3] = temp;
                break;
            }
            default:{
                break;
            }
        }

        if(map->GetValue() == 0){
            map->SetValue(value[vert[2]]);
        }
        else{
            value[vert[2]] = map->GetValue();
            map->SetValue(0);
        }

    }

    void PrintTop(){
        cout << value[vert[0]] << endl;
    }


};




int main(){

    int width,height,r,c,cmdNum;
    cin >> width;
    cin >> height;
    cin >> r;
    cin >> c;
    cin >> cmdNum;

    Map* map = new Map(width,height,r,c);
    Dice * dice = new Dice();    

    

    int * cmd = new int[cmdNum];
    for(int i = 0; i < cmdNum; i++){
        cin >> cmd[i];
    }
    // map -> PrintMap();

    for(int i = 0 ; i < cmdNum; i++){
        if(map->MoveDice(cmd[i])){
            dice->Roll(cmd[i],map);
            dice->PrintTop();
        }
    }


}


