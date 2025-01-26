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

bool isValid(int nrow,int ncol, int n, int m){
    return (nrow>=0 && nrow<n && ncol>=0 && ncol<m);
}

int MaxConnection(vector<vector<int>>& grid){
    int n=grid.size();
    int m=grid[0].size();
    DisjointSet ds(n*m);
    //step 1 make the disjoint set type of graph
    for(int row=0;row<n;row++){
        for(int col=0;col<m;col++){
            if(grid[row][col]==0) continue;

            vector<int> delrow={-1,0,1,0};
            vector<int> delcol={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(isValid(nrow,ncol,n,m) && grid[nrow][ncol]==1){
                    int nodeNo=row*m+col;
                    int adjNodeNo=nrow*m+ncol;
                    ds.unionBySize(nodeNo,adjNodeNo);
                }
            }
        }
    }
    //step 2 find the maximum connection
    int maxi=1;
    for(int row=0;row<n;row++){
        for(int col=0;col<m;col++){
            if(grid[row][col]==1) continue;

            set<int> components;
            vector<int> delrow={-1,0,1,0};
            vector<int> delcol={0,1,0,-1};

            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(isValid(nrow,ncol,n,m) && grid[nrow][ncol]==1){
                    int adjNodeNo=nrow*m+ncol;
                    components.insert(ds.findParent(adjNodeNo));
                }
            }
            int sizeTotal=0;
            for(auto it: components){
                sizeTotal+=ds.size[it];
            }
            maxi=max(maxi,sizeTotal+1);
        }
    }
    for(int cell=0;cell<=n*m;cell++){
        maxi=max(maxi,ds.size[cell]); //if the whole grid is filled with 1 then this will be the answer
    }
    return maxi;
}


int main(){
    vector<vector<int>> grid={{1,1,0,1,1},{1,1,0,1,1},{1,1,0,1,1},{0,0,1,0,0},{0,0,1,1,1},{0,0,1,1,1}};
    cout<<MaxConnection(grid)<<endl;

    return 0;
}