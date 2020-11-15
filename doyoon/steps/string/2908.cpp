#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;

    string reverse_a, reverse_b;
    for(int i=a.size()-1; i>=0; i--){
        reverse_a += a[i];
    }
    for(int i=b.size()-1; i>=0; i--){
        reverse_b += b[i];
    }

    int result = max(stoi(reverse_a), stoi(reverse_b));

    cout << result;

    return 0;
}