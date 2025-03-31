#include<bits/stdc++.h>
using namespace std;

int func(vector<int>& nums,int i,vector<int>& dp){
    if(i>=nums.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    int nottake=func(nums,i+1,dp);
    int take=nums[i]+func(nums,i+2,dp);
    return dp[i]=max(take,nottake);
}

int tabulation(vector<int>& nums){
    vector<int>dp(nums.size()+1,0);
    int prev=nums[0];
    int prev2=0;
    for(int i=1;i<nums.size();i++){
        int np=prev;
        int take=nums[i];
        if(i>1) take+=prev2;
        prev2=prev;
        prev=max(take,np);
    }
    return prev;
}

int rob(vector<int>& nums) {
    // vector<int>dp(nums.size()+1,-1);
    // return func(nums,0,dp);
    // bottom up-with space optimaztion
    return tabulation(nums);
}

int main(){
    //House Robber
    vector<int> nums={1,2,3,1};
    cout<<rob(nums);
    return 0;
}