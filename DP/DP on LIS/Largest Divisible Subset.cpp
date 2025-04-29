#include<bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n=nums.size();
    vector<int>dp(n,1);
    vector<int> hash(n); //to print the LIS
    int lastIndex=0;
    int maxi=1;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        hash[i]=i;
        for(int prev=0;prev<i;prev++){
            if(nums[i]%nums[prev]==0  && dp[prev]+1>dp[i]){
                dp[i]=dp[prev]+1;
                hash[i]=prev;
            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
            lastIndex=i;
        }
    }
    vector<int> ans;
    ans.push_back(nums[lastIndex]);
    while(hash[lastIndex]!=lastIndex){
        lastIndex=hash[lastIndex];
        ans.push_back(nums[lastIndex]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    vector<int> ans=largestDivisibleSubset(nums);
    for(auto i:ans) cout<<i<<" ";
    cout<<endl;
    // 1 2 4 8   
    return 0;
}