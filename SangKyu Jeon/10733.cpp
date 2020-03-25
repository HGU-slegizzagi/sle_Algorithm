#include <iostream>
#include <stack>

using namespace std;

int main(){

    stack<int> count;

    int numb;
    int temp;
    int skipNum = 0;
    int sum =0;

    cin >> numb;

    for(int  i = 0 ; i< numb; i++){
        cin >> temp;
        count.push(temp);
    }

    while(!count.empty()){

        if(count.top() == 0){
            skipNum++;
        }
        else  if(skipNum > 0){
            skipNum--;
        }
        else{
            sum += count.top();
        }

        count.pop();
    }

    cout << sum << endl;



}