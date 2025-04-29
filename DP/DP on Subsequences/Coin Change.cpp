#include<bits/stdc++.h>
using namespace std;

int func(vector<int>& coins, int amount,int i,vector<vector<int>>& dp){
    if(i==0){
        if(amount%coins[0]==0) return amount/coins[0];
        return 1e8;
    }
    if(dp[i][amount]!=-1) return dp[i][amount];
    int np=func(coins,amount,i-1,dp);
    int p=1e8;
    if(coins[i]<=amount) p=1+func(coins,amount-coins[i],i,dp);
    return dp[i][amount]=min(np,p);
}

int tabulation(vector<int>& coins, int amount) {
    int n=coins.size();
    vector<vector<int>> dp(n,vector<int>(amount+1,1e8));
    for (int amt=0;amt<=amount;amt++){
        if(amt%coins[0]==0) dp[0][amt]=amt/coins[0];
    }
    for(int i=1;i<n;i++){
        for(int amt=0;amt<=amount;amt++){
            int np=dp[i-1][amt];
            int p=1e8;
            if(coins[i]<=amt) p=1+dp[i][amt-coins[i]];
            dp[i][amt]=min(np,p);
        }
    }
    return dp[n-1][amount];
}
int spaceOpt(vector<int>& coins, int amount) {
    int n=coins.size();
    vector<int> prev(amount+1,1e8),curr(amount+1,1e8);
    for (int amt=0;amt<=amount;amt++){
        if(amt%coins[0]==0) prev[amt]=amt/coins[0];
    }
    for(int i=1;i<n;i++){
        for(int amt=0;amt<=amount;amt++){
            int np=prev[amt];
            int p=1e8;
            if(coins[i]<=amt) p=1+curr[amt-coins[i]];
            curr[amt]=min(np,p);
        }
        prev=curr;
    }
    return prev[amount];
}
int spaceOpt2(vector<int>& coins, int amount) {
    int n=coins.size();
    vector<int> prev(amount+1,1e8);
    for (int amt=0;amt<=amount;amt++){
        if(amt%coins[0]==0) prev[amt]=amt/coins[0];
    }
    for(int i=1;i<n;i++){
        for(int amt=0;amt<=amount;amt++){  //bcz we need curr iteration value in picking case you can see in tabulation we choose current row amt-coins[i] value
            int np=prev[amt];
            int p=1e8;
            if(coins[i]<=amt) p=1+prev[amt-coins[i]];
            prev[amt]=min(np,p);
        }
    }
    return prev[amount];
}
    
int coinChange(vector<int>& coins, int amount) {
    int n=coins.size();
    vector<vector<int>> dp(n,vector<int>(amount+1,-1));
    // int ans=func(coins,amount,n-1,dp);
    // int ans=tabulation(coins,amount);
    int ans=spaceOpt(coins,amount);
    // int ans=spaceOpt2(coins,amount);
    return ans==1e8 ? -1 : ans;
}

int main(){
    vector<int> coins={1,2,5};
    int amount=11;
    cout<<coinChange(coins,amount);
    return 0;
}