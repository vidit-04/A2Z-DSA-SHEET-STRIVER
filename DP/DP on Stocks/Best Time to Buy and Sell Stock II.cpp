#include<bits/stdc++.h>
using namespace std;

int func(vector<int>& prices,int i,bool buy,vector<vector<int>>& dp) {
    if(i==prices.size()) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    if(buy) return dp[i][buy]=max(-prices[i]+func(prices,i+1,0,dp),func(prices,i+1,1,dp)); // buy, not buy
    else return dp[i][buy]=max(prices[i]+func(prices,i+1,1,dp),func(prices,i+1,0,dp)); //sell, not sell
}
int tabulation(vector<int>& prices){
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            if(buy) dp[i][buy]=max(-prices[i]+dp[i+1][0],dp[i+1][1]); // buy, not buy
            else dp[i][buy]=max(prices[i]+dp[i+1][1],dp[i+1][0]); //sell, not sell
        }
    }
    return dp[0][1];
}
int spaceOpt(vector<int>& prices){
    int n=prices.size();
    vector<int> next(2,0),curr(2,0);
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            if(buy) curr[buy]=max(-prices[i]+next[0],next[1]); // buy, not buy
            else curr[buy]=max(prices[i]+next[1],next[0]); //sell, not sell
        }
        next=curr;
    }
    return next[1];
}
int spaceOpt2(vector<int>& prices){
    int n=prices.size();
    vector<int> next(2,0);
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            if(buy) next[buy]=max(-prices[i]+next[0],next[1]); // buy, not buy
            else next[buy]=max(prices[i]+next[1],next[0]); //sell, not sell
        }
    }
    return next[1];
}
int spaceOpt3(vector<int>& prices){
    int n=prices.size();
    int nextNotBuy=0,nextBuy=0,currNotBuy=0,currBuy=0;
    for(int i=n-1;i>=0;i--){
        currNotBuy=max(prices[i]+nextBuy,nextNotBuy);
        currBuy=max(-prices[i]+nextNotBuy,nextBuy);
        nextNotBuy=currNotBuy;
        nextBuy=currBuy;
    }
    return nextBuy;
}

int maxProfit(vector<int>& prices) {
    // vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
    // return func(prices,0,1,dp);
    // return tabulation(prices);
    // return spaceOpt(prices);
    // return spaceOpt2(prices);
    return spaceOpt3(prices);
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout<<maxProfit(prices)<<endl; //5    
    return 0;
}