#include<bits/stdc++.h>
using namespace std;

vector<int> Dijkstra(int V,vector<vector<pair<int,int>>> adj, int src){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int>dist(V,1e9);
    dist[src]=0;
    pq.push({0,src}); // {dist,node}
    while(!pq.empty()){
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        for(auto it: adj[node]){
            int adjNode=it.first;
            int edgeWeight=it.second;
            if(dis+edgeWeight<dist[adjNode]){
                dist[adjNode]=dis+edgeWeight;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
    //T.C: O(E logV) where E is the number of edges and V is the number of vertices.
}

int main(){
    //Dijkstra works only for non-negative weights.
    //If there are negative weights then it will enter in infirnite loop.
    vector<vector<pair<int,int>>> adj={{{1,4},{2,4}},{{0,4},{2,2}},{{0,4},{1,2},{3,3},{4,1},{5,6}},{{2,3},{5,2}},{{2,1},{5,3}},{{2,6},{3,2},{4,3}}};
    int src=0;
    vector<int>dist=Dijkstra(adj.size(),adj,src);
    for(int i=0;i<dist.size();i++){
        cout<<src<<"->"<<i<<"="<<dist[i]<<endl;
    }
    return 0;
}