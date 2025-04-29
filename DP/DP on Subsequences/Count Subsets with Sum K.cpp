#include<bits/stdc++.h>
using namespace std;

int func(vector<int>& arr, int target,int i,vector<vector<int>>& dp){
    if (i == 0) {
        if (target == 0 && arr[0] == 0)
            return 2; // both including and excluding the zero are valid
        if (target == 0 || target == arr[0])
            return 1;
        return 0;
    }

    if(dp[i][target]!=-1) return dp[i][target];
    
    int nt=func(arr,target,i-1,dp);
    int t=0;
    if(arr[i]<=target) t=func(arr,target-arr[i],i-1,dp);
    
    return dp[i][target]=t+nt;
}

int tabulation(vector<int>& arr, int target) {
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(target+1,0));
    dp[0][0]=(arr[0]==0)? 2 : 1;
    if(arr[0]<=target && arr[0]!=0) dp[0][arr[0]]=1;

    for(int i=1;i<n;i++){
        for(int sum=0;sum<=target;sum++){
            int nt=dp[i-1][sum];
            int t=0;
            if(arr[i]<=sum) t=dp[i-1][sum-arr[i]];
            dp[i][sum]=t+nt;
        }
    }
    return dp[n-1][target];
}
int perfectSum(vector<int>& arr, int target) {
    // int n=arr.size();
    // vector<vector<int>> dp(n,vector<int>(target+1,-1));
    // return func(arr,target,n-1,dp);
    return tabulation(arr,target);
    
}

int main(){
    vector<int> arr = {5, 2, 3, 10, 6, 8};
    int target = 10;
    cout<<perfectSum(arr, target)<<endl; // Output: 3
    return 0;
}