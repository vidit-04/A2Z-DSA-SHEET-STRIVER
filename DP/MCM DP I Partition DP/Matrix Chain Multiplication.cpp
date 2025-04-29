#include<bits/stdc++.h>
using namespace std;

int func(vector<int> &arr,int i,int j,vector<vector<int>>& dp){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mini=1e9;
    for(int k=i;k<j;k++){
        int steps=arr[i-1]*arr[k]*arr[j]+func(arr,i,k,dp)+func(arr,k+1,j,dp);
        mini=min(mini,steps);
    }
    return dp[i][j]=mini;
}
int tabulation(vector<int> &arr){
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<n;j++){
            int mini=1e9;
            for(int k=i;k<j;k++){
                int steps=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                mini=min(mini,steps);
            }
            dp[i][j]=mini;
        }
    }
    return dp[1][n-1];
    
}
int matrixMultiplication(vector<int> &arr) {
    // code here
    // int n=arr.size();
    // vector<vector<int>> dp(n,vector<int>(n,-1));
    // return func(arr,1,n-1,dp);
    return tabulation(arr);
}

int main(){
    vector<int> arr = {1, 2, 3, 4};
    cout<<matrixMultiplication(arr)<<endl; // 18   
    return 0;
}