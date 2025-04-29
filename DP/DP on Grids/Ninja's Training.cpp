#include<bits/stdc++.h>
using namespace std;

int func(vector<vector<int>>& arr,int row,int prev,vector<vector<int>>& dp){
    if(row<0) return 0;
    if(dp[row][prev]!=-1) return dp[row][prev];
    int maxi=INT_MIN;
    for(int i=0;i<3;i++){
        if(i!=prev) maxi=max(maxi,arr[row][i]+func(arr,row-1,i,dp));
    }
    return dp[row][prev]=maxi;
}

int maximumPoints(vector<vector<int>>& arr) {
      // Code here
      int n=arr.size();
      vector<vector<int>> dp(n,vector<int>(4,-1));
      return func(arr,n-1,3,dp);
      // for (int j = 0; j < 3; j++) {
      //     dp[n-1][j] = arr[n-1][j];
      // }

      // for(int i=n-2;i>=0;i--){
      //     for(int j=0;j<3;j++){
      //         int x=INT_MIN;
      //         for(int k=0;k<3;k++){
      //             if(k!=j) x=max(x,arr[i][j]+dp[i+1][k]);
      //         }
      //         dp[i][j]=x;
      //     }
      // }
      // int maxi=0;
      // for(int i=0;i<3;i++){
      //     maxi=max(maxi,dp[0][i]);
      // }
      // return maxi;
}

int main(){
    vector<vector<int>> arr={{1,2,3},{4,5,6},{7,8,9}};
    cout<<maximumPoints(arr)<<endl; //15
    return 0;
}