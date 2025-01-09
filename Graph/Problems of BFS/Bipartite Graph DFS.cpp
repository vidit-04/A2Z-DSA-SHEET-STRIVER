#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,int color,vector<vector<int>>& adj,vector<int>& vis){
    vis[node]=color;
    for(auto it:adj[node]){
        if(vis[it]==-1){
            if(!dfs(it,!color,adj,vis)) return false;
        }
        else if(vis[it]==vis[node]) return false;
    }
    return true;
}

bool checkBipartite(vector<vector<int>>& adj){
    int n=adj.size();
    int m=adj[0].size();
    vector<int> vis(n+1,-1);
    for(int i=1;i<n;i++){
        if(vis[i]==-1){ 
            if(!dfs(i,0,adj,vis))return false;
        }
    }
    return true;
    //T.C.-O(V+2E)
    //S.C.-O(V+E)
}

int main(){
    vector<vector<int>> adj={{},{2},{1,3,6},{2,4},{3,5,7},{4,6},{2,5},{4,8},{7}};
    vector<vector<int>> adj2={{},{2},{1,3,5},{2,4},{3,5,6},{2,4},{4}};
    
    if(checkBipartite(adj2))cout<<"Yes";
    else cout<<"No";
    return 0;
}