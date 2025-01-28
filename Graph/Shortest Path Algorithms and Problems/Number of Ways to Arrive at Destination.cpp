#include<bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>> roads){
    vector<vector<pair<int,int>>> adj(n);
    for(auto it: roads){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //{dist,node}
    pq.push({0,0});
    vector<int>dist(n,1e9);
    vector<int>ways(n,0);
    int mod=1e9+7;
    dist[0]=0;
    ways[0]=1;
    while(!pq.empty()){
        int node=pq.top().second;
        int d=pq.top().first;
        pq.pop();

        for(auto it: adj[node]){
            int num=it.first;
            int wt=it.second;
            //First time we arrive at the node
            //We need not think about that if after sometime we reach the node with less distance because we are using Dijkstra's Algorithm and we are using priority queue
            if(dist[num]>d+wt){
                ways[num]=ways[node];
                dist[num]=d+wt;
                pq.push({dist[num],num});
            }
            else if(dist[num]==d+wt){
                ways[num]+=ways[node];
                ways[num]%=mod;
            }
        }
    }
    return ways[n-1];
    //T.C.- O(e)logv
}

int main(){
    vector<vector<int>> roads={{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
    int n=7;
    cout<<countPaths(n,roads)<<endl;
    return 0;
}