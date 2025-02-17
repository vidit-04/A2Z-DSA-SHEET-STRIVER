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

bool isValid(int nrow,int ncol, int n, int m){
    return (nrow>=0 && nrow<n && ncol>=0 && ncol<m);
}
vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
    // code here
    DisjointSet ds(n*m);
    vector<vector<int>> vis(n,vector<int> (m,0));
    vector<int> ans;
    int cnt=0;
    
    for(auto it: operators){
        int row=it[0];
        int col=it[1];
        if(vis[row][col]==1){
            ans.push_back(cnt);
            continue;
        }
        vis[row][col]=1;
        cnt++;
        
        vector<int> delrow={-1,0,+1,0};
        vector<int> delcol={0,+1,0,-1};
        
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            
            if(isValid(nrow,ncol,n,m) && vis[nrow][ncol]==1){
                int nodeNo=row*m+col;
                int adjNodeNo=nrow*m+ncol;
                if(ds.findParent(nodeNo)!=ds.findParent(adjNodeNo)){
                    cnt--;
                    ds.unionBySize(nodeNo,adjNodeNo);
                }
            }   
        }
        ans.push_back(cnt);
    }
    
    return ans;
}

int main(){
    int n=4,m=4;
    vector<vector<int>> operators={{0,0},{0,1},{1,2},{2,1},{2,2},{3,3}};
    vector<int> ans=numOfIslands(n,m,operators);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}