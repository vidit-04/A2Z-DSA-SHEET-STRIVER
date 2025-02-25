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

int NumberOfProvinces(vector<vector<int>>& matrix){
    //O(N^2)
    DisjointSet ds(matrix.size());
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if(matrix[i][j]==1){
                ds.unionBySize(i+1,j+1);
            }
        }
    }
    int count=0;
    for(int i=1;i<=matrix.size();i++){
        //O(1) if parent array , if we use recursion then it will be O(4alpha(n)) where alpha(n) is the inverse Ackermann function
        if(ds.parent[i]==i){
            count++;
        }
    }
    return count;
    //Time Complexity: O(n^2)+O(n)+O(1)=O(n^2)
    //Space Complexity: O(n)    
}

int main(){
    vector<vector<int>> matrix={{1,0,1},{0,1,0},{1,0,1}};
    cout<<NumberOfProvinces(matrix)<<endl;
    return 0;
}