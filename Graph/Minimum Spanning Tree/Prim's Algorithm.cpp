#include<bits/stdc++.h>
using namespace std;

int MinimumSpanningTreeSum(vector<vector<int>>& matrix,int n){
    //Here we need to calculate only sum of the minimum spanning tree
    vector<vector<pair<int,int>>> adj(n);
    for(auto i: matrix){
        adj[i[0]].push_back({i[1],i[2]});
        adj[i[1]].push_back({i[0],i[2]});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0}); //wt,node, parent
    vector<bool> vis(n,0);
    int sum=0;
    //O(ElogE)
    while(!pq.empty()){
        // log E
        auto it=pq.top();
        pq.pop();
        int node=it.second;
        int wt=it.first;

        if(vis[node]) continue;
        //add it to the mst
        vis[node]=1;
        sum+=wt;
            //O(E)
        for(auto i: adj[node]){
            int adjNode=i.first;
            int adjWt=i.second;
            if(!vis[adjNode]){
                // log E
                pq.push({adjWt,adjNode});
            }
        }
    }
    return sum;
    //T.C. O(ElogE)
    //S.C. O(E)
}

int main(){
    vector<vector<int>> adj={{0,1,5},{1,2,3},{0,2,1}};
    int n=3;
    int ans=MinimumSpanningTreeSum(adj,n);
    cout<<ans<<endl;
    return 0;
}