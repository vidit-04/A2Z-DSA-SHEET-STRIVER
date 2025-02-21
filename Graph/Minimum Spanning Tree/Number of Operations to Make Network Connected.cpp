#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int> rank,parent,size;
    DisjointSet(int n){ 
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findParent(int node){
        if(node==parent[node]) return node;
        parent[node]=findParent(parent[node]);
        return parent[node];// path compression
    }
    void unionByRank(int u,int v){
        //ramk is nothing but the height of the tree
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_u]=ulp_v;
            rank[ulp_u]++;
        }   
    }
    void unionBySize(int u,int v){
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        if(ulp_u==ulp_v) {
            return;
        }
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }   
    }
};

int MinNumberOfOperations(vector<vector<int>>& edges, int n){
    DisjointSet ds(n);
    int extraEdges=0;
    for(auto i: edges){
        int u=i[0];
        int v=i[1];
        if(ds.findParent(u)==ds.findParent(v)){
            extraEdges++;
        }
        else ds.unionBySize(u,v);
    }
    int compo=0;
    for(int i=0;i<n;i++){
        if(ds.findParent(i)==i){
            compo++;
        }
    }
    if(compo -1 > extraEdges) return -1;
    return compo-1;
}

int main(){
    // vector<vector<int>> edges = { {0, 1}, {0, 2}, {1, 2} };
    vector<vector<int>> edges = { {0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3} };
    int n = 6; // Number of total nodes
    cout<<MinNumberOfOperations(edges, n);
    return 0;
}