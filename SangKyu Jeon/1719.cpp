#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#define INF 10000
using namespace std;

class Vertex{

    public:
        int index;
        int weight;
        int post;

        Vertex(int index,int weight,int post):index(index),weight(weight),post(post){

        }
        bool operator <(const Vertex& vertex)const{
            return weight < vertex.weight;
        }

        bool operator >(const Vertex& vertex)const{
            return weight > vertex.weight;
        }


};

vector<int> dijstra(int src,int nodeNum,vector<pair<int,int> >* adj,int **map){

    vector<int> distance(nodeNum,INF);
    distance[src] = 0;
    priority_queue<Vertex> pq;
    pq.push(Vertex(src,0,-1));
    stack<Vertex> path;
    int road[nodeNum];

    while(!pq.empty()){
        int weight = -pq.top().weight;
        int curNode = pq.top().index;
        int post = pq.top().post;
        // path.push(Vertex(nextNode,-newWeight,curNode));
        path.push(pq.top());
        pq.pop();


        if(distance[curNode] < weight){
            continue;
        }

        for(int i = 0; i < adj[curNode].size(); i++){
            int nextNode = adj[curNode][i].first;
            int newWeight = weight + adj[curNode][i].second;

            if(distance[nextNode] > newWeight){
                
                distance[nextNode] = newWeight;
                pq.push(Vertex(nextNode,-newWeight,curNode));
            }
        }
    }


    while(!path.empty()){

        road[path.top().index] = path.top().post;

        path.pop();
    }



    for(int i = 0; i < nodeNum; i++){
        int adjIndex = i;

        while(1){
    
            if(adjIndex == -1 || road[adjIndex] == src){
                map[src][i] = adjIndex;
                break;
            }
            else{
                adjIndex = road[adjIndex];
            }
        }
    }

    return distance;


}


int main(){

    int n,m;
    int src,des,weight;
    int **map;

    cin >> n;
    cin >> m;
    


    map = new int*[n];
    for(int i = 0; i < n; i++){
        map[i] = new int[n];
    }

    vector<pair<int, int> > adj[n];

    for(int i = 0; i < m; i++){
        cin >> src;
        cin >> des;
        cin >> weight;
        adj[src-1].push_back(make_pair(des-1,weight));
        adj[des-1].push_back(make_pair(src-1,weight));
    }

    for(int i = 0; i < n;i++){
        dijstra(i,n,adj,map);
    }

    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                cout << "- ";
            }
            else{
                cout << map[i][j]+1 << " ";
            }
        }
        cout << endl;
    }
}

/*
5 8
5 2 4
5 4 2
4 2 1
4 3 1
2 1 3
1 4 3
1 3 6
3 4 2
*/
