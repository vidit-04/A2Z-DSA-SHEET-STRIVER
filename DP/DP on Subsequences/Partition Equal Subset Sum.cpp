#include<bits/stdc++.h>
using namespace std;

bool func(vector<int>& nums,int i,int target,int n,vector<vector<int>>& dp){
    if(target==0) return 0;
    if(i==0) return nums[i]==target;
    if(dp[i][target]!=-1) return dp[i][target];
    bool nt=func(nums,i-1,target,n,dp);
    bool t=false;
    if(nums[i]<=target) t=func(nums,i-1,target-nums[i],n,dp);
    return dp[i][target]=t||nt;
}

bool tabulation(vector<int>& nums,int total){
    int n=nums.size();
    vector<vector<int>> dp(n,vector<int>(total+1,false));
    for(int i=0;i<n;i++) dp[i][0]=1;
    if(nums[0] <= total) dp[0][nums[0]]=1;
    for(int i=1;i<n;i++){
        for(int sum=1;sum<=total;sum++){
            bool nt=dp[i-1][sum];
            bool t=false;
            if(nums[i]<=sum) t=dp[i-1][sum-nums[i]];
            dp[i][sum]=t||nt;
        }
    }
    return dp[n-1][total];
}

bool spaceOptimization(vector<int>& nums,int total){
    int n=nums.size();
    vector<int> prev(total+1,false),curr(total+1,false);
    prev[0]=curr[0]=1;
    if(nums[0] <= total) prev[nums[0]]=1;
    for(int i=1;i<n;i++){
        for(int sum=1;sum<=total;sum++){
            bool nt=prev[sum];
            bool t=false;
            if(nums[i]<=sum) t=prev[sum-nums[i]];
            curr[sum]=t||nt;
        }
        prev=curr;
    }
    return prev[total];
}

bool canPartition(vector<int>& nums) {
    int totalSum=0;
    for(auto it: nums){
        totalSum+=it;
    }
    if(totalSum&1) return false;
    int total=totalSum/2;
    int n=nums.size();
    // vector<vector<int>> dp(n,vector<int>(total+1,-1));
    // return func(nums,n-1,total,nums.size(),dp);
    // return tabulation(nums,total);
    return spaceOptimization(nums,total);
}

int main(){
    vector<int> nums={1,5,11,5};
    cout<<canPartition(nums)<<endl;
    return 0;
}