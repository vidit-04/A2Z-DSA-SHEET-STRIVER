#include<bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src,int dest, int k){
    vector<vector<pair<int,int>>> adj(n);
    for(auto it: flights){
        adj[it[0]].push_back({it[1],it[2]});
    }
    queue<pair<int,pair<int,int>>> q; // {k,{node,dist}}
    q.push({0,{src,0}});
    vector<int> dist(n,1e9);
    dist[src]=0;
    while(!q.empty()){
        int stops=q.front().first;
        int node=q.front().second.first;
        int dis=q.front().second.second;
        q.pop();
        
        if(stops>k) continue;
        for(auto it: adj[node]){
            int nd=it.first;
            int wt=it.second;
            if(dis+wt<dist[nd] && stops<=k){
                dist[nd]=dis+wt;
                q.push({stops+1,{nd,dis+wt}});
            }
        }
    }
    if(dist[dest]==1e9) return -1;
    return dist[dest];

    //T.C: O(E logV) where E is the number of edges and V is the number of vertices.
}

int main(){
    int n=4;
    vector<vector<int>> flights={{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src=0;
    int dst=3;
    int k=1;
    cout<<findCheapestPrice(n,flights,src,dst,k)<<endl;
    return 0;
}