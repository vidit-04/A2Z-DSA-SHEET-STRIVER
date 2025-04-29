#include<bits/stdc++.h>
using namespace std;

void dfs(int node,int parent,vector<vector<int>>& adj, vector<int>& vis, vector<int>& tin, vector<int>& low, int& timer, vector<int>& mark){
    vis[node]=1;
    tin[node]=low[node]=timer++;
    int child=0;
    for(auto it: adj[node]){
        if(it==parent) continue;
        if(!vis[it]){
            dfs(it,node,adj,vis,tin,low,timer,mark);
            low[node]=min(low[node],low[it]);
            if(low[it]>=tin[node] && parent!=-1){
                mark[node]=1;
            }
            child++;
        }
        else{
            low[node]=min(low[node],low[it]);
        }
    }
    if(parent==-1 && child>1){
        mark[node]=1;
    }
}

int main(){
    //5 5
// 0 1
// 1 4
// 2 4
// 3 4
// 2 3

    vector<vector<int>> adj={{1},{0,2,3},{1,3},{1,2,4},{3,2}};
    int n=5;
    vector<int> vis(n,0);
    vector<int> tin(n,-1);
    vector<int> low(n,-1);
    vector<int> mark(n,0);
    int timer=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,-1,adj,vis,tin,low,timer,mark);
        }
    }
    for(int i=0;i<n;i++){
        if(mark[i]){
            cout<<i<<endl;
        }
    }

    return 0;
}