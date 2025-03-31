#include<bits/stdc++.h>
using namespace std;

int func(vector<int>& nums,int& n,int i, bool flag,vector<vector<int>>& dp){
    if(i>=n) return 0;
    if(dp[i][flag]!=-1) return dp[i][flag];
    int np=func(nums,n,i+1,flag,dp);
    int p=INT_MIN;
    if(i==0) p=nums[i]+func(nums,n,i+2,!flag,dp);
    else if(i==n-1 && flag==true) p=INT_MIN;
    else p=nums[i]+func(nums,n,i+2,flag,dp);
    return dp[i][flag]=max(p,np);
}

int tabulation(vector<int>& nums) {
    int n=nums.size();
    bool flag=0;
    vector<vector<int>>dp(n,vector<int>(2,-1));
    
    dp[n-1][0]=nums[n-1];
    dp[n-1][1]=0;
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=1;j++){
            int np=dp[i+1][j];
            int p=nums[i];
            if(i==0) p+=dp[i+2][1];
            else p+=dp[i+2][j];
            dp[i][j] = max(p, np);
        }
    }
    return max(dp[0][0],dp[0][1]);
}

int rob(vector<int>& nums) {
    int n=nums.size();
    bool flag=0;
    vector<vector<int>>dp(n,vector<int>(2,-1));
    return func(nums,n,0,flag,dp);
}


int main(){
    vector<int>nums={2,3,2};
    cout<<rob(nums);
    return 0;
}