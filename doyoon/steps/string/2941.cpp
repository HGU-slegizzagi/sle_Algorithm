#include <iostream>
#include <string>
using namespace std;

int main(){
    string input;
    cin >> input;

    int sum = 0;
    int size = input.size();
    for(int i=0; i<size; i++){
        //cout << input[i] << " " << sum << endl;
        if(input[i]=='c'){
            if((i+1)<size && (input[i+1]=='=' || input[i+1]=='-')){
                sum += 1;
                i += 1;
            }else{
                sum += 1;
            }
        }else if(input[i]=='d'){
            if((i+1)<size && input[i+1]=='z'){
                if((i+2)<size && input[i+2]=='='){
                    sum += 1;
                    i += 2;
                }else{
                    sum += 1;
                }
            }else if((i+1)<size && input[i+1]=='-'){
                sum += 1;
                i += 1;
            }else{
                sum += 1;
            }
        }else if(input[i]=='l'){
            if((i+1)<size && input[i+1]=='j'){
                sum += 1;
                i += 1;
            }else{
                sum += 1;
            }
        }else if(input[i]=='n'){
            if((i+1)<size && input[i+1]=='j'){
                sum += 1;
                i += 1;
            }else{
                sum += 1;
            }
        }else if(input[i]=='s'){
            if((i+1)<size && input[i+1]=='='){
                sum += 1;
                i += 1;
            }else{
                sum += 1;
            }
        }else if(input[i]=='z'){
            if((i+1)<size && input[i+1]=='='){
                sum += 1;
                i += 1;
            }else{
                sum += 1;
            }
        }else{
            sum += 1;
        }
    }

    cout << sum;
    
    return 0;
}