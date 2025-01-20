#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>& visited,stack<int>& s,vector<vector<int>>& adj){
   visited[node]=1;
   for(auto i: adj[node]){
        if(!visited[i]){
            dfs(i,visited,s,adj);
        }
   }
   s.push(node);
}

vector<int> TopologicalSort(vector<vector<int>>& adj){
    int n=adj.size();
    vector<int> vis(n,0);
    vector<int> ans;
    stack<int>s;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,vis,s,adj);
        }
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
    //T.C.-O(V+E)
    //S.C.-O(V)
}

int main(){
    //Topological sort is only created of DAG(Directed Acyclic Graph)
    vector<vector<int>> adj={{},{},{3},{1},{0,1},{0,2}};
    vector<int>ans= TopologicalSort(adj);
    for(auto i : ans) cout<<i<<" ";
    return 0;
}