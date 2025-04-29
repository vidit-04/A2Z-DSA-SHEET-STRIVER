#include<bits/stdc++.h>
using namespace std;

bool isValid(int row,int col,int m,int n,vector<vector<int>>& obstacleGrid){
    return row>=0 && row<m && col>=0 && col<n && obstacleGrid[row][col]==0;
}

int dfs(int row,int col,int& m,int& n,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
    if(row==m-1 && col==n-1 && obstacleGrid[row][col]!=1) return 1;
    if(dp[row][col]!=-1) return dp[row][col];
    int ans=0;
    if(isValid(row+1,col,m,n,obstacleGrid)) ans+=dfs(row+1,col,m,n,obstacleGrid,dp);
    if(isValid(row,col+1,m,n,obstacleGrid)) ans+=dfs(row,col+1,m,n,obstacleGrid,dp);
    return dp[row][col]=ans;
}

int tabulation(vector<vector<int>>& obstacleGrid) {
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
    if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;
    vector<vector<long long>> dp(m,vector<long long>(n,0));
    // return dfs(0,0,m,n,obstacleGrid,dp);
    dp[m-1][n-1]=1;
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(isValid(i+1,j,m,n,obstacleGrid)) dp[i][j]+=dp[i+1][j];
            if(isValid(i,j+1,m,n,obstacleGrid)) dp[i][j]+=dp[i][j+1];
        }
    }
    return dp[0][0];
}
    
int spaceOptimized(vector<vector<int>>& obstacleGrid) {
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
    if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;
    vector<long long> next(n,0);
    for(int i=m-1;i>=0;i--){
        vector<long long> curr(n,0);
        for(int j=n-1;j>=0;j--){
            if(i==m-1 && j==n-1) curr[j]=1;
            else if(obstacleGrid[i][j]==1) curr[j]=0;
            else{
                long long down=0,right=0;
                if(i<m-1) down=next[j];
                if(j<n-1) right=curr[j+1];
                curr[j]=down+right;
            }
        }
        next=curr;
    }
    return next[0];
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    // vector<vector<long long>> dp(m,vector<long long>(n,-1));
    // return dfs(0,0,m,n,obstacleGrid,dp);
    // return tabulation(obstacleGrid);
    return spaceOptimized(obstacleGrid);
}

int main(){
    vector<vector<int>> obstacleGrid={{0,0,0},{0,1,0},{0,0,0}};
    cout<<uniquePathsWithObstacles(obstacleGrid)<<endl; //2    
    return 0;
}