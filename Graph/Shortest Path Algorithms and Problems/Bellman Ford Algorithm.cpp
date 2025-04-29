#include<bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> dist(V,1e8);
    dist[src]=0;
    // Relax all edges (V-1) times.
    for(int i=0;i<V-1;i++){
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            int d=it[2];
            if(dist[u]!=1e8 && dist[u]+d < dist[v]){
                dist[v]=dist[u]+d;
            }
        }
    }
    // Check for negative-weight cycles by iterating through the edges one more time.
    for(auto it : edges){
        int u=it[0];
        int v=it[1];
        int d=it[2];
        if(dist[u]!=1e8 && dist[u]+d < dist[v]){
            return {-1};
        }
    }
    return dist;
    //T.C- O(v*e)
}

int main(){
    //BELLMAN FORD ALGORTHM IS USED TO FIND THE SHORTEST PATH FROM A SOURCE TO ALL OTHER VERTICES IN A GRAPH
    //IT CAN BE USED IN NEGATIVE WEIGHTED EDGES as Dijkstra's Algorithm cannot be used in negative weighted edges
    //IT is used in graph which are directed
    //It can be used in undirected graph also but we need to convert it into directed graph
    //It is single source shortest path algorithm which means it can be used to find the shortest path from a source to all other vertices
    //It can also be used to detect negative weight cycle in a graph.
    
    vector<vector<int>> edges={{0,1,5},{1,0,3},{1,2,-1},{2,0,1}};
    int src=2;
    vector<int> ans=bellmanFord(3,edges,src);
    for(auto it:ans){
        cout<<it<<" ";
    }

    return 0;
}