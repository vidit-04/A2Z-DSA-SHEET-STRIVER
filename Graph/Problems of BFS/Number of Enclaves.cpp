#include<bits/stdc++.h>
using namespace std;

void dfs(int row,int col,vector<vector<int>>& matrix,vector<vector<int>>& vis,vector<int>& delrow,vector<int>& delcol ){
    vis[row][col]=1;
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && matrix[nrow][ncol]==1 && !vis[nrow][ncol]){
            dfs(nrow,ncol,matrix,vis,delrow,delcol);
            vis[nrow][ncol]=1;
        }
    }
}

int NumberOfEnclaves(vector<vector<int>>& matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<int>delrow={-1,0,+1,0};
    vector<int>delcol={0,+1,0,-1};

    for(int j=0;j<m;j++){
        if(matrix[0][j]==1 && !vis[0][j]) dfs(0,j,matrix,vis,delrow,delcol);
        if(matrix[n-1][j]==1 && !vis[n-1][j]) dfs(n-1,j,matrix,vis,delrow,delcol);
    }
    for(int i=0;i<n;i++){
        if(matrix[i][0]==1 && !vis[i][0]) dfs(i,0,matrix,vis,delrow,delcol);
        if(matrix[i][m-1]==1 && !vis[i][m-1]) dfs(i,m-1,matrix,vis,delrow,delcol);
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==1 && !vis[i][j]) count++;
        }
    }
    return count;
    //T.C.-O(N*M)*4
    //S.C.-O(N*M)
}

int main(){
    vector<vector<int>> matrix={{0,0,0,1,1},{0,0,1,1,0},{0,1,0,0,0},{0,1,1,0,0},{0,0,0,1,1}};
    int ans=NumberOfEnclaves(matrix);
    cout<<ans;
    return 0;
}