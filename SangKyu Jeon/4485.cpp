#include <iostream>
#include <queue>

using namespace std;

int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

int main(){

    int size = 1;
    int count = 0;


    while(1){
        count++;

        cin >> size;
        if(size == 0){
            return 0;
        }
        int **data = new int*[size];
        for(int i = 0; i < size; i++){
            data[i] = new int [size];
        }


        int *distance = new int[size*size];
        int *check = new int[size*size];
        queue<int> s;


        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                cin >> data[i][j];
            }
        }



        for(int i = 0; i < size*size; i++){
            distance[i] = -1;
            check[i] = 0;
        }

        
        //---------------weight done
        //start point always 1




        distance[0] = data[0][0];


        while(s.size()<size*size){

            //select
            int minIndex = -1;

            for(int i = 0; i < size*size; i++){

            
               
                if( check[i] ==0 && distance[i] != -1){
                    
                    if(minIndex == -1){
                        minIndex = i;
                        continue;
                    }
                    //check min value
                    minIndex = distance[minIndex] > distance[i] ? i : minIndex ;
                }
            }
            
            s.push(minIndex);
            check[minIndex] = 1;

            if(minIndex == size*size-1){
                cout << "Problem "<<count<<": "<< distance[size*size-1]<<endl;
                break;
            }
            
            int y = minIndex/size;
            int x = minIndex%size;
            


            for(int i = 0; i < 4;i++){
                int dirX = x+dir[i][1];
                int dirY = y+dir[i][0];

                if(check[dirY*size+dirX] == 1){
                    continue;
                }

                if( dirX >= 0 && dirX < size && dirY >= 0 && dirY < size){
                    if(distance[dirY*size+dirX] == -1) {
                        distance[dirY*size+dirX] = distance[minIndex]+data[dirY][dirX];
                    }
                    else{
                        distance[dirY*size+dirX] = distance[dirY*size+dirX]+data[dirY][dirX] > distance[dirY*size+dirX] ? distance[dirY*size+dirX]: distance[dirY*size+dirX]+data[dirY][dirX];
                    }
                } 
            }
        }
        // cout << "-count-" << endl;
        // for(int i = 0; i < size*size ; i++){
        //     cout << distance[i] << " | " ;
        // }
        // cout << endl;

        for(int i = 0; i < size; i++){
            delete[] data[i];
        }
        delete[] data;

        delete[] distance;

    }

    

}

/*
3
5 5 4
3 9 1
3 2 7
5
3 7 2 0 1
2 8 0 9 1
1 2 1 8 1
9 8 9 2 0
3 6 5 1 5
7
9 0 5 1 1 5 3
4 1 2 1 6 5 3
0 7 6 1 6 8 5
1 1 7 8 3 2 3
9 4 0 7 6 4 1
5 8 3 2 4 8 3
7 4 8 4 8 3 4
0
*/