#include<bits/stdc++.h>
using namespace std;

void dfs1(int node,vector<vector<int>>& adj,vector<int>& visited){
    visited[node]=1;
    for(int i=0;i<adj[0].size();i++){
        if(adj[node-1][i]==1 && !visited[i+1]){
            dfs1(i+1,adj,visited);
        }
    }
}

int NumberOfProvince1(vector<vector<int>>& isConnected) {   
    int V=isConnected.size();
    vector<int>visited(V+1,0);
    int cnt=0;
    for(int i=1;i<V+1;i++){
        if(!visited[i]){
            dfs1(i,isConnected,visited);
            cnt++;
        }
    }
    return cnt;
}

void dfs2(int node, vector<vector<int>>& adj,vector<int>& visited){
    visited[node]=1;
    for(auto i : adj[node]){
        if(!visited[i]) dfs2(i,adj,visited);
    }
}
int numProvinces2(vector<vector<int>> adj, int V) {
    // code here
    vector<vector<int>> adjLst(V);
    for(int i=0;i<V;i++){
        for(int j=0;j<adj[0].size();j++){
            if(adj[i][j]==1 && i!=j){
                adjLst[i].push_back(i);
                adjLst[j].push_back(j);
            }
        }
    }
    vector<int> visited(V,0);
    int cnt=0;
    for(int i=1;i<V;i++){
        if(visited[i]==0){
            dfs2(i,adjLst,visited);
            cnt++;
        }
    }
    return cnt;
}

int main(){
    vector<vector<int>> isConnected={{1,1,0},{1,1,0},{0,0,1}};
    cout<<NumberOfProvince1(isConnected);

    vector<vector<int>> adj={{1,0,1},{0,1,0},{1,0,1}};
    cout<<numProvinces2(adj,3);
    return 0;
}