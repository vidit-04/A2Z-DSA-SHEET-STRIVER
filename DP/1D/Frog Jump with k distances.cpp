#include<bits/stdc++.h>
using namespace std;

int func(int& k, vector<int>& arr,int idx,vector<int>& dp){
    if(idx>=arr.size()-1) return 0;
    if(dp[idx]!=-1) return dp[idx];
    int ans=INT_MAX;
    for(int i=1;i<=k;i++){
        if(idx+i <= arr.size()-1) ans=min(ans,abs(arr[idx]-arr[idx+i])+func(k,arr,idx+i,dp));
    }
    return dp[idx]=ans;
}

int minimizeCost(int k, vector<int>& arr) {
    // Code here
    int n=arr.size();
    vector<int> dp(n,-1);
    dp[n-1]=0;
    for(int idx=n-2;idx>=0;idx--){
        int ans=INT_MAX;
        for(int i=1;i<=k;i++){
            if(idx+i <= arr.size()-1) ans=min(ans,abs(arr[idx]-arr[idx+i])+dp[idx+i]);
        }
        dp[idx]=ans;
    }
    return dp[0];
}

int main(){
    int k=3;
    vector<int> arr={10,30,40,50,20};
    cout<<minimizeCost(k,arr);
    return 0;
}