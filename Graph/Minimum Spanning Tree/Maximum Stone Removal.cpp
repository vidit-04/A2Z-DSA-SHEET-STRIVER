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
        if(ulp_u==ulp_v) return;
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

int maxRemove(vector<vector<int>>& stones, int n) {
    int maxrow=0;
    int maxcol=0;
    for(auto it: stones){
        maxrow=max(maxrow,it[0]);
        maxcol=max(maxcol,it[1]);
    }
    DisjointSet ds(maxrow+maxcol+1);
    unordered_map<int,int> stoneNodes;
    for(auto it: stones){
        int noderow=it[0];
        int nodecol=it[1]+maxrow+1;
        ds.unionBySize(noderow,nodecol);
        stoneNodes[noderow]=1;
        stoneNodes[nodecol]=1;
    }
    int cnt=0;
    for(auto it: stoneNodes){
        if(ds.findParent(it.first)==it.first) cnt++;
    }
    return n-cnt;
}

int main(){
    vector<vector<int>> stones={{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    int n=6;
    cout<<maxRemove(stones,n)<<endl;    
    return 0;
}