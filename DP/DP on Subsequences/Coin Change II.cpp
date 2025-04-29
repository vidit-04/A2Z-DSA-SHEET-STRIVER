#include<bits/stdc++.h>
using namespace std;

int func(int amount, vector<int>& coins,int i,vector<vector<int>>& dp){
    if(i==0){
        if(amount%coins[0]==0) return 1;
        return 0;
    }
    if(dp[i][amount]!=-1) return dp[i][amount];
    int nt=func(amount,coins,i-1,dp);
    int t=0;
    if(coins[i]<=amount) t=func(amount-coins[i],coins,i,dp);
    return dp[i][amount]=t+nt;
}

int tabulation(int amount, vector<int>& coins) {
    int n=coins.size();
    vector<vector<int>> dp(n,vector<int>(amount+1,0));
    for(int sum=0;sum<=amount;sum++) dp[0][sum]= (sum%coins[0])==0 ? 1 : 0;
    for(int i=1;i<n;i++){
        for(int sum=0;sum<=amount;sum++){
            long long nt=dp[i-1][sum];
            long long t=0;
            if(coins[i]<=sum) t=dp[i][sum-coins[i]];
            dp[i][sum]=(int)(t+nt);
        }
    }
    return (int)dp[n-1][amount];
}

int spaceOpt(int amount, vector<int>& coins) {
    int n=coins.size();
    vector<int> prev(amount+1,0),curr(amount+1,0);
    for(int sum=0;sum<=amount;sum++) prev[sum]= (sum%coins[0])==0 ? 1 : 0;
    for(int i=1;i<n;i++){
        for(int sum=0;sum<=amount;sum++){
            long nt=prev[sum];
            long t=0;
            if(coins[i]<=sum) t=curr[sum-coins[i]];
            curr[sum]=(t+nt);
        }
        prev=curr;
    }
    return prev[amount];
}

int spaceOpt2(int amount, vector<int>& coins) {
    int n=coins.size();
    vector<int> prev(amount+1,0);
    for(int sum=0;sum<=amount;sum++) prev[sum]= (sum%coins[0])==0 ? 1 : 0;
    for(int i=1;i<n;i++){
        for(int sum=0;sum<=amount;sum++){
            long nt=prev[sum];
            long t=0;
            if(coins[i]<=sum) t=prev[sum-coins[i]];
            prev[sum]=(t+nt);
        }
    }
    return prev[amount];
}

int change(int amount, vector<int>& coins) {
    // int n=coins.size();
    // vector<vector<int>> dp(n,vector<int>(amount+1,-1));
    // return func(amount,coins,n-1,dp);
    // return tabulation(amount,coins);
    // return spaceOpt(amount,coins);
    return spaceOpt2(amount,coins);
}


int main(){
    vector<int> coins={1,2,5};
    cout<<change(5,coins); //4    
    return 0;
}