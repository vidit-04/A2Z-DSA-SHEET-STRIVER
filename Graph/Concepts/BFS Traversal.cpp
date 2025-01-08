#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(vector<vector<int>> &adj) {
    // Code here
    int V=adj.size();
    vector<int> vis(V,0);
    vis[0]=1;
    queue<int>q;
    q.push(0);
    vector<int>bfs;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
}

int main(){
    vector<vector<int>> adj={{2,3,1},{0},{0,4},{0},{2}};
    vector<int> ans=bfsOfGraph(adj);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}