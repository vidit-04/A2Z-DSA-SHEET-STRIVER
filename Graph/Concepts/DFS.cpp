#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &adj,int node,vector<int> &vis,vector<int>& dfs){
    vis[node]=1;
    dfs.push_back(node);
    for(auto it: adj[node]){
        if(!vis[it]){
            DFS(adj,it,vis,dfs);
        }
    }
}

int main(){
    vector<vector<int>> adj={{2,3,1},{0},{0,4},{0},{2}};
    int V=5;
    vector<int> vis(V,0);
    vector<int> dfs;
    DFS(adj,0,vis,dfs);
    for(auto it: dfs){
        cout<<it<<" ";
    }

    return 0;
}