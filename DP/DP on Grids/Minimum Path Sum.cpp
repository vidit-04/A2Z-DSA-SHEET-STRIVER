#include<bits/stdc++.h>
using namespace std;

int dfs(int row,int col,int& m,int& n,vector<vector<int>>& grid,vector<vector<int>>& dp){
    if(row==m-1 && col==n-1) return grid[row][col];
    if(dp[row][col]!=-1) return dp[row][col];
    int ans=INT_MAX;
    
    if(row+1<m) ans=min(ans,grid[row][col]+dfs(row+1,col,m,n,grid,dp));
    if(col+1<n) ans=min(ans,grid[row][col]+dfs(row,col+1,m,n,grid,dp));
    return dp[row][col]=ans;
}

int tabulation(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<long long>> dp(m,vector<long long>(n,0));
    dp[m-1][n-1]=grid[m-1][n-1];
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i==m-1 && j==n-1) continue;
            long long ans=1e18;
            if(i+1<m) ans=min(ans,grid[i][j]+dp[i+1][j]);        
            if(j+1<n) ans=min(ans,grid[i][j]+dp[i][j+1]);        
            dp[i][j]=ans;
        }
    }
    return dp[0][0];
}

int spaceOpt(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    vector<long long> nxt(n,0);
    for(int i=m-1;i>=0;i--){
        vector<long long>curr(n,0);
        for(int j=n-1;j>=0;j--){
            if(i==m-1 && j==n-1) curr[n-1]=grid[m-1][n-1];
            else{
                long long ans=1e18;
                if(i+1<m) ans=min(ans,grid[i][j]+nxt[j]);        
                if(j+1<n) ans=min(ans,grid[i][j]+curr[j+1]);        
                curr[j]=ans;
            }
        }
        nxt=curr;
    }
    return nxt[0];
}

int minPathSum(vector<vector<int>>& grid) {
    // vector<vector<long long>> dp(m,vector<long long>(n,-1));
    // return dfs(0,0,m,n,grid,dp);
    // return tabulation(grid);
    return spaceOpt(grid);
}

int main(){
    vector<vector<int>> grid={{1,3,1},{1,5,1},{4,2,1}};
    cout<<minPathSum(grid)<<endl; //7
    return 0;
}