#include<bits/stdc++.h>
using namespace std;

vector<int> KahnAlgorithm(vector<vector<int>>& adj){
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

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto i : adj[node]){
            indegree[i]--;
            if(indegree[i]==0) q.push(i);
        }
    }
    return topo;
    //T.C.-O(V+E)
    //S.C.-O(V)
}

int main(){
    //Topological sort with BFS is called Kahn Algorithm
    vector<vector<int>> adj={{},{},{3},{1},{0,1},{0,2}};
    vector<int> ans=KahnAlgorithm(adj);
    for(auto i : ans) cout<<i<<" ";
    return 0;
}