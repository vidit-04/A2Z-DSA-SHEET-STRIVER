#include<bits/stdc++.h>
using namespace std;

int trade(int index,vector<int>& prices, int transaction, int k,vector<vector<int>>& dp){
    if(index>=prices.size() || transaction==2*k){
        return 0;
    }
    if(dp[index][transaction]!=-1) return dp[index][transaction];
    int profit=trade(index+1,prices,transaction,k,dp);
    if(transaction & 1){
        profit=max(profit,prices[index]+trade(index+1,prices,transaction+1,k,dp));
    }
    else profit=max(profit,-prices[index]+trade(index+1,prices,transaction+1,k,dp));
    return dp[index][transaction]=profit;
}       
int spaceOpt3(vector<int>& prices,int k) {//buy and sell stock 3
    int n=prices.size();
    vector<int> after(k+1,0);
    for(int i=n-1;i>=0;i--){
        for(int trans=0;trans<k;trans++){
            if(trans%2==0) after[trans]=max(-prices[i]+after[trans+1],after[trans]);
            else after[trans]=max(prices[i]+after[trans+1],after[trans]);
        }
    }
    return after[0];
}
int maxProfit(int k, vector<int>& prices) {
    // vector<vector<int>> dp(prices.size()+1,vector<int>(2*k+1,-1));
    // return trade(0,prices,0,k,dp);
    return spaceOpt3(prices,2*k);
}

int main(){
    vector<int> prices = {3,2,6,5,0,3};
    cout<<maxProfit(2,prices)<<endl; //7
    return 0;
}