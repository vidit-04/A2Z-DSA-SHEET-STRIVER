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
    //It goes same as fibonacci series as we can take 1 step or 2 steps at a time
    int n=5;
    vector<int> dp(n+1,-1);
    //Top down approach
    cout<<fib(n,dp)<<endl;
    return 0;
}