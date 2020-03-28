#include <iostream>
#include <set>

using namespace std;


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
        int **map = new int*[size*size];
        for(int i = 0; i < size*size; i++){
            map[i] = new int [size*size];
        }
        
        int *distance = new int[size*size];
        set<int> s;


        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                cin >> data[i][j];
            }
        }

        for(int i = 0; i < size*size; i++){
            for(int j = 0; j < size*size; j++){
                map[i][j] = -1;
            }
        }

        for(int i = 0; i < size*size; i++){
            distance[i] = -1;
        }

        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                int index = (i*size)+(j);
                int adjIndex;
                //self
                map[index][index] = data[i][j];


                //left
                if(j-1 >= 0){
                    adjIndex = (i*size)+(j-1);
                    map[index][adjIndex] = data[i][j-1];
                }

                //right
                if(j+1<size){
                    adjIndex = (i*size)+(j+1);
                    map[index][adjIndex] = data[i][j+1];
                }

                //up
                if(i-1 >= 0){
                    adjIndex = ((i-1)*size)+(j);
                    map[index][adjIndex] = data[i-1][j];
                }
                //down
                if(i+1 < size){
                    adjIndex = ((i+1)*size)+(j);
                    map[index][adjIndex] = data[i+1][j];
                }
            }
        }

        //---------------weight done
        //start point always 1
        set<int>::iterator iter;



        distance[0] = map[0][0];


        while(s.size()<size*size){

            //select
            int minIndex = -1;

            for(int i = 0; i < size*size; i++){

                iter = s.find(i);
                if( iter == s.end() && distance[i] != -1){
                    
                    if(minIndex == -1){
                        minIndex = i;
                        continue;
                    }
                    //check min value
                    minIndex = distance[minIndex] > distance[i] ? i : minIndex ;
                }
            }
            
            // cout << s.size()<<endl;
            s.insert(minIndex);
            
            //update
            for(int i = 0; i < size*size; i++){
                
                iter = s.find(i);

                if(iter == s.end()  && map[minIndex][i] != -1){

                    //inf
                    if(distance[i] == -1) {
                        distance[i] = distance[minIndex]+map[minIndex][i];
                    }
                    else{
                        distance[i] = distance[minIndex]+map[minIndex][i] > distance[i] ? distance[i]: distance[minIndex]+map[minIndex][i];
                    }
                }
                
            }
        }

        cout << "Problem "<<count<<": "<< distance[size*size-1]<<endl;
        for(int i = 0; i < size; i++){
            delete[] data[i];
        }
        delete[] data;
        for(int i = 0; i < size*size; i++){
            delete[] map[i];
        }
        delete[] map;
        delete[] distance;

    }

    

}

/*
3
5 5 4
3 9 1
3 2 7

weight
5 5 _ 3 _ _ _ _ _
5 5 4 _ 9 _ _ _ _
_ 5 4 _ _ 1 _ _ _
5 _ _ 3 9 _ 3 _ _
_ 5 _ 3 9 1 _ 2 7
_ _ 4 _ 9 1 _ _ 7
_ _ _ 3 _ _ 3 2 _
_ _ _ _ 9 _ 3 2 7
_ _ _ _ _ 1 _ 2 7

distance[9]
*/