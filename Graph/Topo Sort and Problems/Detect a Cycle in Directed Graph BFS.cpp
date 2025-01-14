#include<bits/stdc++.h>
using namespace std;

bool KahnAlgorithm(vector<vector<int>>& adj){
    int V = adj.size();
    vector<int> indegree(V,0);
    for(auto i : adj){
        for(auto j : i){
            indegree[j]++;
        }
    }

    queue<int> q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0) q.push(i);
    }

    int cnt=0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;

        for(auto i : adj[node]){
            indegree[i]--;
            if(indegree[i]==0) q.push(i);
        }
    }
    return cnt==V;
    //T.C.-O(V+E)
    //S.C.-O(V)
}


int main(){
    vector<vector<int>> adj={{},{},{3},{1},{0,1},{0,2}};   
    cout<<KahnAlgorithm(adj);
    return 0;
}