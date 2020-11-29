#include <iostream>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int card[n];

    for(int i=0; i<n; i++) scanf("%d", &card[i]);

    int max = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                int no = 1;
                if(j!=i) no+=1;
                if(k!=i && k!=j) no+=1;
                int sum = card[i] + card[j] + card[k];
                if(no==3 && sum>max && sum<=m) max = sum;
            }
        }
    }

    cout << max;

    return 0;
}