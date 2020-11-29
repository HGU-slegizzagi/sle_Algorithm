#include <iostream>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int x[n], y[n];

    for(int i=0; i<n; i++){
        scanf("%d %d", &x[i], &y[i]);
    }
    
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=0; j<n; j++){
            if(x[j]>x[i] && y[j]>y[i]) sum += 1;
        }
        printf("%d ", sum + 1);
    }

    return 0;
}