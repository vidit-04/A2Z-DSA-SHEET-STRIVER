#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank,parent,size;
public:
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

int spanningTree(vector<vector<int>>& adj,int n){
    vector<pair<int,pair<int,int>>> edges(n);
    //O(N+E)
    for(auto i: adj){
        int adjNode=i[0];
        int adjWt=i[1];
        int node=i[2];

        edges.push_back({adjWt,{adjNode,node}});
    }
    sort(edges.begin(),edges.end());
    DisjointSet ds(n);
    //O(MLOGm)
    int mstWt=0;
    for(auto it: edges){
        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if(ds.findParent(u)!=ds.findParent(v)){
            ds.unionBySize(u,v);
            mstWt+=wt;
        }
    }
    return mstWt;
    //T.C. O(ElogE)
    //S.C. O(E)
}

int main(){
    vector<vector<int>> adj={{0,1,5},{1,2,3},{0,2,1}};
    int n=3;
    cout<<spanningTree(adj,n);
    return 0;
}

// Dijkstra : from a single source, find shortest paths to all nodes.

// Floyd-Warshall : shortest path from every node as a source.

// Bellman-Ford : same as Dijkstra, but works for negative weights.

// Topological Sort : print the nodes with no incoming edges first.

// MST : connect all the nodes with minimum costs (n nodes // n-1 edges).

// Prim's Algo : build the MST by starting from any node and expanding the tree one edge at a time.

// Kruskal Algo : build the MST by sorting all edges and adding them one by one, ensuring no cycles are formed.

// Disjoint Set : union by rank, union by size, path compression.

// Dijkstra: Works on both directed and undirected graph with non-negative edge weights, Greedy approach

// Bellman Ford: Works on both directed and undirected graph with non-negative edge weights as well as directed graph with negative edge weights as long as no negative cycles are present, Dynamic Programming approach

