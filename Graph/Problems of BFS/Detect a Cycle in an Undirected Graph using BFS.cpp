#include<bits/stdc++.h>
using namespace std;

bool detect(vector<vector<int>>& adj,vector<bool>& visited, int src){
    queue<pair<int,int>> q;
    q.push({src,-1});
    visited[src] = true;

    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();

        for(auto i: adj[node]){ 
            if(!visited[i]){
                visited[i]=1;
                q.push({i,node});
            }
            else if(i!=parent) return true;
        }
    }
    return false;

}

bool cycle(vector<vector<int>> adj){
    vector<bool> visited(adj.size(),0);
    for(int i=0;i<adj.size();i++){
        if(!visited[i]){
            if(detect(adj,visited,i)) return true;
        }
    }
    return false;
    //T.C.= O(V+2E)+O(N)
    //S.C.= O(N)+O(N)
}

int main(){
    vector<vector<int>> adj={{},{0,2,4},{1,3},{2,4},{1,3}};
    if(cycle(adj)) cout<<"Cycle is present";
    else cout<<"Cycle is not present";
    return 0;
}