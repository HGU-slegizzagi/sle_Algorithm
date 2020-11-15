#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(){
    string input;
    int n;
    int alpha[26];

    scanf("%d", &n);

    int sum = 0;
    for(int i=0; i<n; i++){
        bool groupword = true;
        memset(alpha, -1, sizeof(alpha));
        cin >> input;
        for(int j=0; j<input.size(); j++){
            if(alpha[input[j]-97]==-1){
                if((j+1<input.size()) && input[j+1]!=input[j]) alpha[input[j]-97] = 1;
            }else{
                groupword=  false;
                break;
            }
        }
        if(groupword){
            //cout << input << endl;
            sum+=1;
        }
    }

    cout << sum;

    return 0;
}