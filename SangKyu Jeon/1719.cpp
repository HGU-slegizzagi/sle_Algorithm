#include <iostream>
#include <queue>
#include <vector>
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

    while(!pq.empty()){
        int weight = -pq.top().weight;
        int curNode = pq.top().index;
        int post = pq.top().post;
        pq.pop();
        map[src][curNode] = post;


        if(distance[curNode] < weight){
            continue;
        }

        for(int i = 0; i < adj[curNode].size(); i++){
            int nextNode = adj[curNode][i].first;
            int newWeight = weight + adj[curNode][i].second;

            if(distance[nextNode] > newWeight){
                // cout <<src <<" | "<< curNode <<" | "<<post << endl;
                distance[nextNode] = newWeight;
                pq.push(Vertex(nextNode,-newWeight,curNode+1));
            }
        }
    }

    for(int i = 0; i < nodeNum; i++){
        if(i == src){
            cout << "_ ";
        }
        else{
            cout << map[src][i] << " ";
        }
    }
    cout << endl;

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

    vector<pair<int, int> > adj[n*n];

    for(int i = 0; i < m; i++){
        cin >> src;
        cin >> des;
        cin >> weight;
        adj[src-1].push_back(make_pair(des-1,weight));
        adj[des-1].push_back(make_pair(src-1,weight));
    }



cout << endl;cout << endl;

    for(int i = 0; i < n;i++){
        dijstra(i,n,adj,map);
    }



}
