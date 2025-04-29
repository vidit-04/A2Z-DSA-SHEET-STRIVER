#include<bits/stdc++.h>
using namespace std;

vector<int> Dijkstra(int V,vector<vector<pair<int,int>>> adj, int src){
    set<pair<int,int>> st;
    vector<int>dist(V,1e9);
    dist[src]=0;
    st.insert({0,src}); // {dist,node}
    while(!st.empty()){
        auto it=*(st.begin());
        int dis=it.first;
        int node=it.second;
        st.erase(it);

        for(auto i: adj[node]){
            int adjNode=i.first;
            int edgeWeight=i.second;
            if(dis+edgeWeight<dist[adjNode]){
                //erase if already present
                if(dist[adjNode]!=1e9){
                    st.erase({dist[adjNode],adjNode});
                }

                dist[adjNode]=dis+edgeWeight;
                st.insert({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
    //Not much faster than  priority_queue because it takes O(logV) time to erase an element from set. 
    //And due to which it all depends on the number of vertices and edges what to use.
}

int main(){
    vector<vector<pair<int,int>>> adj={{{1,4},{2,4}},{{0,4},{2,2}},{{0,4},{1,2},{3,3},{4,1},{5,6}},{{2,3},{5,2}},{{2,1},{5,3}},{{2,6},{3,2},{4,3}}};
    int src=0;
    vector<int>dist=Dijkstra(adj.size(),adj,src);
    for(int i=0;i<dist.size();i++){
        cout<<src<<"->"<<i<<"="<<dist[i]<<endl;
    }
    return 0;
}