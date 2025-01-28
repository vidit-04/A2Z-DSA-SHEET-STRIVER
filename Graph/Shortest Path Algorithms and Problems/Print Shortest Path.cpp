#include<bits/stdc++.h>
using namespace std;

vector<int> ShortestPath(vector<vector<pair<int,int>>> adj,int V,int src,int dest){
    set<pair<int,int>> s; // {distance,vertex}
    vector<int> dist(V+1,INT_MAX);
    vector<int> parent(V+1,-1);
    s.insert({0,src});
    dist[src]=0;
    while(!s.empty()){
        auto x=*(s.begin());
        s.erase(x);
        int node=x.second;
        int dis=x.first;
        if(node==dest) break;
        for(auto it: adj[node]){
            int adjNode=it.first;   
            int edgeWeight=it.second
            ;
            if(dist[adjNode] > dist[node]+edgeWeight){

                if(dist[adjNode]!=INT_MAX){
                    s.erase({dist[adjNode],adjNode});
                }

                dist[adjNode]=edgeWeight+dist[node];
                s.insert({dist[adjNode],adjNode});
                parent[adjNode]=node;
            }
        }
    }
    if(dist[dest]==INT_MAX) return {-1};
    vector<int> path;
    path.push_back(dest);
    while(parent[dest]!=-1){
        path.push_back(parent[dest]);
        dest=parent[dest];
    }
    reverse(path.begin(),path.end());
    return path;
    //T>C->O(ElogV)+O(N)
    //S.C->O(V)
}

int main(){
    vector<vector<pair<int,int>>> adj={{},{{2,2},{4,1}},{{1,2},{3,4},{5,5}},{{2,4},{4,3},{5,1}},{{1,1},{3,3}},{{2,5},{3,1}}};
    int src=1;
    int n=adj.size();
    int dest=5;
    vector<int> path=ShortestPath(adj,n,src,dest);
    for(int i=0;i<path.size();i++) cout<<path[i]<<" ";
    return 0;
}