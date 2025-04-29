#include<bits/stdc++.h>
using namespace std;

int func(vector<int>& nums,int i,int prev, map<pair<int,int>,int>& mp){
    if(i>=nums.size()) return 0;
    if(mp.count({i,prev})>0) return mp[{i,prev}];
    int t=0;
    if(prev==-1e5 || prev<nums[i]){
        t=1+func(nums,i+1,nums[i],mp);
    }
    int nt=func(nums,i+1,prev,mp);
    return mp[{i,prev}]=max(t,nt);
}
int func2(vector<int>& nums,int i,int prevInd,vector<vector<int>>& dp) {
    if(i==nums.size()) return 0;
    if(dp[i][prevInd+1]!=-1) return dp[i][prevInd+1];
    int t=0;
    if(prevInd==-1 || nums[prevInd]<nums[i]){
        t=1+func2(nums,i+1,i,dp);
    }
    int nt=func2(nums,i+1,prevInd,dp);
    return dp[i][prevInd+1]=max(t,nt);
}
int tabulation(vector<int>& nums) {
    int n=nums.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=n-1;i>=0;i--){
        for(int prevInd=-1;prevInd<i;prevInd++){
            int t=0;
            if(prevInd==-1 || nums[prevInd]<nums[i]){
                t=1+dp[i+1][i+1];
            }
            int nt=dp[i+1][prevInd+1];
            dp[i][prevInd+1]=max(t,nt);
        }
    }
    return dp[0][0];
}
int spaceOpt(vector<int>& nums) {
    int n=nums.size();
    vector<int> after(n+1,0),curr(n+1,0);
    for(int i=n-1;i>=0;i--){
        for(int prevInd=-1;prevInd<i;prevInd++){
            int t=0;
            if(prevInd==-1 || nums[prevInd]<nums[i]){
                t=1+after[i+1];
            }
            int nt=after[prevInd+1];//we shifted indexes of dp by +1
            curr[prevInd+1]=max(t,nt);
        }
        after=curr;
    }
    return after[-1+1];
}
int usingBS(vector<int>& arr) {
    //this method can only give longest increasing subsequence length not the actual subsequence
    //it uses binary search to find the position of the current element in the dp array
    vector<int>dp;
    int len=1;
    dp.push_back(arr[0]);
    for(int i=1;i<arr.size();i++){
        if(dp.back()<arr[i]) {
            dp.push_back(arr[i]); 
            len++;
        }
        else{
            int ind=lower_bound(dp.begin(),dp.end(),arr[i])-dp.begin();
            dp[ind]=arr[i];
        }
    }
    return len;
}
int lengthOfLIS(vector<int>& nums) {
    // map<pair<int,int>,int> mp;
    // return func(nums,0,-1e5,mp);

    // int n=nums.size();
    // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    // return func2(nums,0,-1,dp);
    // return tabulation(nums);
    // return spaceOpt(nums);
    return usingBS(nums);

    //to print LIS
    int n=nums.size();
    vector<int>dp(n,1);
    vector<int> hash(n); //to print the LIS
    int lastIndex=0;
    int maxi=1;
    for(int i=0;i<n;i++){
        hash[i]=i;
        for(int prev=0;prev<i;prev++){
            if(nums[prev]<nums[i]  && dp[prev]+1>dp[i]){
                dp[i]=dp[prev]+1;
                hash[i]=prev;
            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
            lastIndex=i;
        }
    }
    //this method is used to get the actual LIS for each index of dp[i]
    vector<int> ans;
    ans.push_back(nums[lastIndex]);
    while(hash[lastIndex]!=lastIndex){
        lastIndex=hash[lastIndex];
        ans.push_back(nums[lastIndex]);
    }
    reverse(ans.begin(),ans.end());
    for(auto i: ans){
        cout<<i<<" ";
    }
    return maxi;
}

int main(){
    
    return 0;
}