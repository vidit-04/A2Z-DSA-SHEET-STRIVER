#include<bits/stdc++.h>
using namespace std;

void dfs(int row,int col,int iniColor,int newColor,vector<vector<int>>& ans,vector<vector<int>> grid,int n,int m,vector<int>& delrow,vector<int>& delcol){
   ans[row][col]=newColor;
    for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==iniColor && ans[nrow][ncol]!=newColor)dfs(nrow,ncol,iniColor,newColor,ans,grid,n,m,delrow,delcol);
    }
}

vector<vector<int>> FloodFill(vector<vector<int>> grid,int sr,int sc,int newColor,int n,int m){
    int iniColor=grid[sr][sc];
    vector<vector<int>> ans=grid;
    vector<int>delrow={-1,0,+1,0};
    vector<int>delcol={0,+1,0,-1};
    dfs(sr,sc,iniColor,newColor,ans,grid,n,m,delrow,delcol);
    return ans;
    //T.C.-O(n*m)
    //S.C.-O(n*m)+O(n*m)
}

int main(){
    vector<vector<int>> grid = {
        {1,1,0},
        {2,2,0},
        {2,2,2}
    };    
    int sr=2;
    int sc=0;
    int newColor=3;
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> ans=FloodFill(grid,sr,sc,newColor,n,m);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }   
    return 0;
}