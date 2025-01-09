#include<bits/stdc++.h>
using namespace std;

bool bfs(int node,vector<vector<int>>& adj,vector<int>& vis){
    queue<int> q;
    q.push(node);
    vis[node]=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            //If the adjacent node is not colored then you will give it a color opposite to the current node.
            if(vis[it]==-1){
                vis[it]=!vis[node];
                q.push(it);
            }
            //If the adjacent node is colored and it is colored with the same color as the current node then return false.
            else if(vis[it]==vis[node])return false;
        }
    }
    return true;
}

bool checkBipartite(vector<vector<int>>& adj){
    int n=adj.size();
    int m=adj[0].size();
    vector<int> vis(n+1,-1);
    for(int i=1;i<n;i++){
        if(vis[i]==-1){
            if(!bfs(i,adj,vis))return false;
        }
    }
    return true;
    //T.C.-O(V+2E)
    //S.C.-O(V+E)
}

int main(){
    //Bipartite Graph is a graph whose any two nodes will not have same color if it is colored with 2 different colors.
    //A graph which is linear and do not have cycle is always a bipartite graph.
    //A graph which have even length cycle is a bipartite graph.
    //A graph which have odd length cycle is not a bipartite graph.
    vector<vector<int>> adj={{},{2},{1,3,6},{2,4},{3,5,7},{4,6},{2,5},{4,8},{7}};
    vector<vector<int>> adj2={{},{2},{1,3,5},{2,4},{3,5,6},{2,4},{4}};
    
    if(checkBipartite(adj))cout<<"Yes";
    else cout<<"No";
    return 0;
}