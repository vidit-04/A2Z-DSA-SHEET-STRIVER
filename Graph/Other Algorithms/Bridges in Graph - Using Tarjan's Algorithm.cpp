#include<bits/stdc++.h>
using namespace std;

void CriticalConnection(int node,int parent,vector<vector<int>>& adj,vector<int>& vis, int& timer,vector<int>&tin,vector<int>& low, vector<vector<int>>& ans){
    vis[node]=1;
    tin[node]=low[node]=timer++;
    for(auto it: adj[node]){
        if (it == parent) continue;
        if(!vis[it]){
            CriticalConnection(it,node,adj,vis,timer,tin,low,ans);
            low[node]=min(low[node],low[it]);
            if(low[it]>tin[node]){
                ans.push_back({node,it});
            }
        }
        else{
            low[node]=min(low[node],low[it]);
        }
    }
}

int main(){
    // n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]

    int n=4;
    vector<vector<int>> connections{{0,1},{1,2},{2,0},{1,3}};
    vector<vector<int>> adj(n);
    for(auto it: connections){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> vis(n,0);
    vector<int> tin(n,-1);
    vector<int> low(n,-1);
    vector<vector<int>> ans;
    int timer=0;
    CriticalConnection(0,-1,adj,vis,timer,tin,low,ans);
    for(auto it: ans){
        cout<<it[0]<<" "<<it[1]<<endl;
    }

    return 0;
}