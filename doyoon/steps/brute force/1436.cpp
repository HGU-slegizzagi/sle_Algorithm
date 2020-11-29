#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    int sum = 0;
    int num = 666;
    while(sum<n){
        int count_six = 0;
        string numstr = to_string(num);
        for(int i=0; i<numstr.size(); i++){
            if(numstr[i]=='6') count_six += 1;
            else count_six = 0;
            if(count_six==3){
                sum += 1;
                break;
            }
        }
        num += 1;
    }

    cout << num-1 << endl;



    return 0;
}