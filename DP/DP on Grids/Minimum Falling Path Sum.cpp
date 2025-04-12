#include<bits/stdc++.h>
using namespace std;

long long func(vector<vector<int>>& matrix,int row,int col,int n,vector<vector<int>>& dp){
    if(row==n) return 0;
    if(col!=-1 && dp[row][col]!=-1) return dp[row][col];
    long long ans=LLONG_MAX;
    if(col==-1){
        for(int i=0;i<n;i++){
            ans=min(ans,matrix[row][i]+func(matrix,row+1,i,n,dp));
        }
        return ans;
    }
    else{
        if(col-1>=0 && col-1<n) ans=min(ans,matrix[row][col-1]+func(matrix,row+1,col-1,n,dp));
        if(col>=0 && col<n) ans=min(ans,matrix[row][col]+func(matrix,row+1,col,n,dp));
        if(col+1>=0 && col+1<n) ans=min(ans,matrix[row][col+1]+func(matrix,row+1,col+1,n,dp));
    }
    return dp[row][col]=ans;
}
int tabulation(vector<vector<int>>& matrix) {
    int n=matrix.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0){
                dp[i][j]=matrix[i][j];
                continue;
            }
            int ans=INT_MAX;
            for(int k=-1;k<=1;k++){
                if(j+k>=0 && j+k<n) ans=min(ans,dp[i-1][j+k]);
            }
            dp[i][j]=matrix[i][j]+ans;
        }
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        ans=min(ans,dp[n-1][i]);
    }
    return ans;
}
int spaceOpt(vector<vector<int>>& matrix) {
    int n=matrix.size();
    vector<int> prev(n,0);
    for(int j=0;j<n;j++){
        prev[j]=matrix[n-1][j];
    }
    for(int i=n-2;i>=0;i--){
        vector<int> curr(n,0);
        for(int j=0;j<n;j++){
            int ans=INT_MAX;
            for(int k=-1;k<=1;k++){
                if(j+k>=0 && j+k<n) ans=min(ans,prev[j+k]);
            }
            curr[j]=matrix[i][j]+ans;
        }
        prev=curr;
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        ans=min(ans,prev[i]);
    }
    return ans;
}
int minFallingPathSum(vector<vector<int>>& matrix) {
    // int n=matrix.size();
    // vector<vector<int>> dp(n,vector<int>(n,-1));
    // return func(matrix,0,-1,n,dp);
    // return tabulation(matrix);
    return spaceOpt(matrix);
}

int main(){
    vector<vector<int>>matrix={{2,1,3},{6,5,4},{7,8,9}};
    cout<<minFallingPathSum(matrix);
    return 0;
}