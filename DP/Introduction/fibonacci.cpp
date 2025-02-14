#include<bits/stdc++.h>
using namespace std;

int fib(int n,vector<int>& dp){
    if(n==0 || n==1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n]=fib(n-1,dp)+fib(n-2,dp);
}

int main(){
    int n=5;
    vector<int> dp(n+1,-1);
    //Top down approach
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n]<<endl;
    //Bottom up approach
    vector<int> dp1(n+1,-1);
    cout<<fib(n,dp1)<<endl;

    //Space Optimized approach
    int prev2=0,prev1=1;
    for(int i=2;i<=n;i++){
        int curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    cout<<prev1<<endl;
    return 0;
}