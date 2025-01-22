#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,vector<int>& visited,vector<int>& pathVisited,vector<vector<int>>& adj,vector<int>& check){
    //Approach is that if there is a cycle in the graph then we mark it as 0 and return because every path of that node should lead to the terminal node to be a safe node.
    //If there is no cycle then we mark it as 1 and return.
    visited[node]=1;
    pathVisited[node]=1;
    check[node]=0;
    for(auto i : adj[node]){
        if(!visited[i]){
            if(dfs(i,visited,pathVisited,adj,check)){
                check[node]=0;
                return true;
            }
        }
        else if(pathVisited[i]) return true;
    }
    check[node]=1;
    pathVisited[node]=0;
    return false;
}

vector<int> safeState(vector<vector<int>>& adj){
    int n=adj.size();
    vector<int> visited(n,0);
    vector<int> pathVisited(n,0);
    vector<int> check(n,0);
    vector<int> safe;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,visited,pathVisited,adj,check);
        }
    }
    for(int i=0;i<n;i++){
        if(check[i]) safe.push_back(i);
    }
    //The below code also works fine as whenever we find dont find a cycle  we mark it as 1 and then unmark it to 0 and return. But if there is a cycle then we just mark it as 0 and return.
    // for(int i=0;i<n;i++){
    //     if(!pathVisited[i]) safe.push_back(i);
    // }
    return safe;

}

int main(){
    //Concept for who cannot be a safe node
    //Safe node is a node that leads to a terminal node or a node that is not part of a cycle.
    //If a node is part of a cycle then it cannot be a safe node
    //Any node that leads to a cycle that also cannot be a safe nodez5z
    vector<vector<int>> adj={{1},{2},{3},{4,5},{6},{6},{7},{},{1,9},{10},{8},{9}};
    vector<int> safe=safeState(adj);
    for(auto i : safe) cout<<i<<" ";
    return 0;
}