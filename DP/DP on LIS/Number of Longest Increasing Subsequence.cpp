#include<bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int>& nums) {
    int n=nums.size();
    vector<int>dp(n,1);
    vector<int>cnt(n,1);
    int maxi=1;
    for(int i=1;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(nums[prev]<nums[i] && dp[i]<dp[prev]+1){
                dp[i]=dp[prev]+1;
                cnt[i]=cnt[prev];
            }
            else if(nums[prev]<nums[i] && dp[i]==dp[prev]+1) cnt[i]+=cnt[prev];
        }
        maxi=max(maxi,dp[i]);
    }
    int nos=0;
    for(int i=0;i<n;i++){
        if(dp[i]==maxi) nos+=cnt[i];
    }
    return nos;
}

int main(){
    vector<int> nums = {1,3,5,4,7,8,6,5};
    cout<<findNumberOfLIS(nums)<<endl; //4     
    return 0;
}