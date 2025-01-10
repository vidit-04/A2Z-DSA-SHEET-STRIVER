#include<bits/stdc++.h>
using namespace std;

bool detect(int node,vector<vector<int>>& adj,vector<int>& visited,int parent){
    visited[node]=1;
    for(auto i: adj[node]){
        if(!visited[i]){
            if(detect(i,adj,visited,node)) return true;
        }
        else if(i!=parent) return true;
    }
    return false;
}

bool check(vector<vector<int>>& adj){
    vector<int>visited(adj.size(),0);
    for(int i=0;i<adj.size();i++){
        if(!visited[i]){
            if(detect(i,adj,visited,-1)) return true;
        }
    }
    return false;
    //T.C.-o(N+2E)+O(N)
    //S.C.-O(n)+O(N)
}

int main(){
    vector<vector<int>> adj={{1},{0,2,4},{1,3},{2,4},{1,3}};
    if(check(adj)) cout<<"Cycle is present";
    else cout<<"Cycle is not present";
    return 0;
}