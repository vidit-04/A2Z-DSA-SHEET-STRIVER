#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>>& adj, int src){
    queue<int> q; //node, distance
    vector<int>dist(adj.size(),1e9);
    q.push(src);
    dist[src]=0;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        
        for(auto it: adj[node]){
            if(dist[it] > dist[node]+1){
                dist[it]=dist[node]+1;
                q.push(it);
            }
        }
    }
    return dist;
    //T.C.-O(V+2E)
    //S.C.-O(V)
}

int main(){
    vector<vector<int>> adj={{1,3},{0,2,3},{1,6},{0,4},{3,5},{4,6},{2,5,7,8},{6,8},{6,7}};
    vector<int> dist=shortestPath(adj,0);
    for(auto i : dist) cout<<i<<" ";
    return 0;
}