#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    char board[n][m];
    char str[52];
    for(int i=0;i<n; i++){
        scanf("%s", str);
        for(int j=0; j<m; j++){
            board[i][j] = str[j];
        }
    }

    char word = 'B', firstword = 'B';
    int sum = 0;
    int ans = INT_MAX;
    for(int starti=0; starti<=n-8; starti++){
        for(int startj=0; startj<=m-8; startj++){
            firstword = 'B';
            sum = 0;
            for(int i=starti; i<starti+8; i++){
                //cout << "start i " << starti << " startj " << startj << endl;
                word = firstword;
                if(firstword == 'B') firstword = 'W';
                else if(firstword == 'W') firstword = 'B';
                for(int j=startj; j<startj+8; j++){
                    if(word!=board[i][j]){
                        sum += 1;
                        //cout << "i " << i << " j " << j << " word " << word << " board " << board[i][j] << endl;
                    }
                    if(word=='B') word = 'W';
                    else if(word=='W') word = 'B';
                }
            }
            //cout << "sum " << sum << endl;
            ans = min(ans, sum);
        }
    }
    

    //cout << "sum " << sum << endl;
    sum = 0;
    firstword = 'W';

    //cout << "cut" << endl;

    for(int starti=0; starti<=n-8; starti++){
        for(int startj=0; startj<=m-8; startj++){
            firstword = 'W';
            sum = 0;
            for(int i=starti; i<starti+8; i++){
                word = firstword;
                if(firstword == 'B') firstword = 'W';
                else if(firstword == 'W') firstword = 'B';
                for(int j=startj; j<startj+8; j++){
                    if(word!=board[i][j]){
                        sum += 1;
                        //cout << "i " << i << " j " << j << " word " << word << " board " << board[i][j] << endl;
                    }
                    if(word=='B') word = 'W';
                    else if(word=='W') word = 'B';
                }
            }
            //cout << "sum " << sum << endl;
            ans = min(sum, ans);
        }
    }


    /*for(int i=0; i<n; i++){
        word = firstword;
        if(firstword == 'B') firstword = 'W';
        else if(firstword == 'W') firstword = 'B';
        for(int j=0; j<m; j++){
            if(word!=board[i][j]) sum += 1;
            if(word=='B') word = 'W';
            else if(word=='W') word = 'B';
        }
    }*/

    //ans = min(ans, sum);

    cout << ans;



    return 0;
}