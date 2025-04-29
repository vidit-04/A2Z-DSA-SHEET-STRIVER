#include<bits/stdc++.h>
using namespace std;

bool isValid(int row,int col,int m,int n){
    return row>=0 && row<m && col>=0 && col<n;
}

int dfs(int row,int col,int& m,int& n,vector<vector<int>>& dp){
    if(row==m-1 && col==n-1) return 1;
    if(dp[row][col]!=-1) return dp[row][col];
    int down=0;
    if(isValid(row+1,col,m,n)) down=dfs(row+1,col,m,n,dp);
    int left=0;
    if(isValid(row,col+1,m,n)) left=dfs(row,col+1,m,n,dp);
    return dp[row][col]=down+left;
}

int tabulation(int m,int n){
    vector<vector<int>> dp(m,vector<int>(n,0));
    dp[m-1][n-1]=1;
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(isValid(i+1,j,m,n)) dp[i][j]+=dp[i+1][j];
            if(isValid(i,j+1,m,n)) dp[i][j]+=dp[i][j+1];
        }
    }
    return dp[0][0];
}

int spaceOptimised(int m,int n){
    vector<int> prev(n,0);
    for(int i=0;i<m;i++){
        vector<int>curr(n,0);
        for(int j=0;j<n;j++){
            if(i==0 && j==0) curr[j]=1;
            else{
                int up=0,left=0;
                if(i>0) up=prev[j]; //no need for if here
                if(j>0) left=curr[j-1];
                curr[j]=up+left;
            }
        }
        prev=curr;
    }
    return prev[n-1];
}

int uniquePaths(int m, int n) {
    // return dfs(0,0,m,n,dp);
    return tabulation(m,n);
    // return spaceOptimised(m,n);
}
    

int main(){
    int m=3,n=7;
    cout<<uniquePaths(m,n)<<endl; //28    
    return 0;
}