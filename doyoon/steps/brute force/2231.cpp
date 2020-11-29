#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    int result = -1;
    for(int i=1; i<n; i++){
        int sum = i;
        string s = to_string(i);
        for(int j=0; j<s.size(); j++){
            sum += s[j] - '0';
        }
        if(sum==n){
            result = i;
            break;
        }
    }

    if(result==-1) cout << 0 << endl;
    else cout << result << endl;

    return 0;
}