#include<bits/stdc++.h>
using namespace std;

int func(vector<int>& nums,int i,int j,vector<vector<int>>& dp){
    if(i>j) return 0;
    int maxi=INT_MIN;
    // if(dp[i][j]!=-1) return dp[i][j];
    for(int ind=i;ind<=j;ind++){
        int coins=nums[i-1]*nums[ind]*nums[j+1]+func(nums,i,ind-1,dp)+func(nums,ind+1,j,dp);
        maxi=max(maxi,coins);
    }
    return dp[i][j]=maxi;
}
int tabulation(vector<int>& nums){
    int n=nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(),1);
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
            if(i>j) continue;
            int maxi=INT_MIN;
            for(int ind=i;ind<=j;ind++){
                int coins=nums[i-1]*nums[ind]*nums[j+1]+dp[i][ind-1]+dp[ind+1][j];
                maxi=max(maxi,coins);
            }
            dp[i][j]=maxi;
        }
    }
    return dp[1][n];
}

int maxCoins(vector<int>& nums) {
    // int n=nums.size();
    // nums.push_back(1);
    // nums.insert(nums.begin(),1);
    // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    // return func(nums,1,n,dp);
    return tabulation(nums);
}

int main(){
    vector<int> nums = {3,1,5,8};
    cout<<maxCoins(nums)<<endl; // 167
    // 167 is the maximum coins we can get by bursting the balloons in the order {1,3,5,8}
    // 3*1*5 + 1*5*8 + 3*1*8 + 3*5*8 = 15 + 40 + 24 + 120 = 167   
    return 0;
}