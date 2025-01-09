#include<bits/stdc++.h>
using namespace std;



int main(){
    //Graph Representation
    int n,m;
    cin>>n>>m;
    // int adj[n+1][m+1];
    // for(int i=0;i<m;i++){
    //     int u,v;
    //     cin>>u>>v;
    //     adj[u][v]=1;
    //     adj[v][u]=1;
    // }


    //Adjacency List
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //S.C.-O(2E) where E is the number of edges
    return 0;
}