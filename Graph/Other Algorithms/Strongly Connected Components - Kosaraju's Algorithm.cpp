#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj,vector<int> &vis,stack<int>& st, int node){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(adj,vis,st,it);
        }
    }
    st.push(node);
}
void dfs3(vector<vector<int>> &adj,vector<int> &vis, int node){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs3(adj,vis,it);
        }
    }
}

int kosaraju(vector<vector<int>> &adj) {
    // code here
    vector<int> vis(adj.size(),0);
    stack<int> st;
    for(int i=0;i<adj.size();i++){
        if(!vis[i]){
            dfs(adj,vis,st,i);
        }
    }
    vector<vector<int>> adjT(adj.size(),vector<int>(adj[0].size(),0));
    for(int i=0;i<adj.size();i++){
        // i-> it
        //it-> i
        vis[i]=0;
        for(auto it: adj[i]){
            adjT[it].push_back(i);
        }
    }
    int scc=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!vis[node]){
            scc++;
            dfs3(adjT,vis,node);
        }
    }
    return scc;
}

int main(){
    //Strongly Connected Components (SCG)- Kosaraju's Algorithm
    // it can be used to print the strongly connected components of a graph
    // also to find number of strongly connected components
    //strongly connected components are those components of a graph in which every vertex is reachable from every other vertex
    // and it is directed graph always

    //Time Complexity: O(V+E)
    //Space Complexity: O(V+E)

    vector<vector<int>> adj={{2,3},{0},{1},{4},{}};
    cout<<kosaraju(adj)<<endl;

    return 0;
}