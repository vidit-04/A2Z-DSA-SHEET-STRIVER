#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,vector<vector<int>>& adj,vector<int>& visited,vector<int>& pathVisited){
    visited[node]=1;
    pathVisited[node]=1;
    for(auto i : adj[node]){
        if(!visited[i]){
            if(dfs(i,adj,visited,pathVisited)) return true;
        }
        else if(pathVisited[i]) return true;
    }
    pathVisited[node]=0;
    return false;
}

bool isCyclic(vector<vector<int>>& adj){
    int n = adj.size();
    vector<int> visited(n,0);
    vector<int> pathVisitied(n,0);
    for(int i=1;i<n;i++){
        if(!visited[i]){
            if(dfs(i,adj,visited,pathVisitied)) return true;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> adj={{},{2},{3},{4,7},{5},{6},{},{5},{2,9},{10},{8}};
    if(isCyclic(adj)) cout<<"Yes Cyclic";
    else cout<<"No";
    return 0;
}