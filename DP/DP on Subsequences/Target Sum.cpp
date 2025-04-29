#include<bits/stdc++.h>
using namespace std;

int func(vector<int>& nums, int target,int i,vector<vector<int>>& dp){
    if(i==0){
        if(nums[i]==0 && target==0) return 2;
        if(nums[i]==target || target==0) return 1;
        return 0;
    }
    if(dp[i][target]!=-1) return dp[i][target];
    int nt=func(nums,target,i-1,dp);
    int t=0;
    if(nums[i]<=target) t=func(nums,target-nums[i],i-1,dp);
    return dp[i][target]=nt+t;
}
int tabulation(vector<int>& nums, int target){
    int n=nums.size();
    vector<vector<int>> dp(n,vector<int>(target+1,0));
    dp[0][0]= nums[0]==0 ? 2 : 1;
    if(nums[0]<=target && nums[0]!=0) dp[0][nums[0]]=1;
    
    for(int i=1;i<n;i++){
        for(int sum=0;sum<=target;sum++){
            int nt=dp[i-1][sum];
            int t=0;
            if(nums[i]<=sum) t=dp[i-1][sum-nums[i]];
            dp[i][sum]=nt+t;
        }
    }
    return dp[n-1][target];
}
int spaceOpt(vector<int>& nums, int target){
    int n=nums.size();
    vector<int> prev(target+1,0);
    prev[0]= nums[0]==0 ? 2 : 1;
    if(nums[0]<=target && nums[0]!=0) prev[nums[0]]=1;
    
    for(int i=1;i<n;i++){
        for(int sum=target;sum>=0;sum--){
            int nt=prev[sum];
            int t=0;
            if(nums[i]<=sum) t=prev[sum-nums[i]];
            prev[sum]=nt+t;
        }
    }
    return prev[target];
}
int spaceOpt2(vector<int>& nums, int target){
    int n=nums.size();
    vector<int> prev(target+1,0) ,curr(target+1,0);
    prev[0]= nums[0]==0 ? 2 : 1;
    if(nums[0]<=target && nums[0]!=0) prev[nums[0]]=1;
    
    for(int i=1;i<n;i++){
        for(int sum=0;sum<=target;sum++){
            int nt=prev[sum];
            int t=0;
            if(nums[i]<=sum) t=prev[sum-nums[i]];
            curr[sum]=nt+t;
        }
        prev=curr;
    }
    return prev[target];
}

int findTargetSumWays(vector<int>& nums, int target) {
    int total=accumulate(nums.begin(),nums.end(),0);
    if(total<target || (total-target)%2) return 0;
    int k=(total-target)/2;
    // int n=nums.size();
    // vector<vector<int>> dp(n,vector<int>(k+1,-1));
    // return func(nums,k,n-1,dp);
    // return tabulation(nums,k);
    // return spaceOpt(nums,k);
    return spaceOpt2(nums,k);
}
int main(){
    vector<int> nums={1,1,1,1,1};
    int target=3;
    cout<<findTargetSumWays(nums,target); //5
    return 0;
}