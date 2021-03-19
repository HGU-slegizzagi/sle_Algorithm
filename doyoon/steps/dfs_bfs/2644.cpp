#include <iostream>
#include <vector>

using namespace std;

int answer = -1;
bool visit[101] = { false };
vector<int> family[101]; 

void dfs(int parent, int child, int cnt){
    visit[parent] = true;
    if(parent == child){
        answer = cnt;
    }else{
        for(int i=0; i<family[parent].size(); i++){
            if(!visit[family[parent][i]]) dfs(family[parent][i], child, cnt+1);
        }
    }
    return;
}

int main(){
    int n, m, tarX, tarY;

    cin >> n >> tarX >> tarY >> m;
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        
        family[x].push_back(y);
        family[y].push_back(x);
    }

    dfs(tarX, tarY, 0);

    cout << answer;

    return 0;
}