#include<bits/stdc++.h>
using namespace std;

int func(vector<int>& prices,int i,bool buy,vector<vector<int>>& dp) {
    if(i>=prices.size()) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    if(buy) return dp[i][buy]=max(-prices[i]+func(prices,i+1,0,dp),func(prices,i+1,1,dp)); // buy, not buy
    else return dp[i][buy]=max(prices[i]+func(prices,i+2,1,dp),func(prices,i+1,0,dp)); //sell, not sell
}
int tabulation(vector<int>& prices) {
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            if(buy) dp[i][buy]=max(-prices[i]+dp[i+1][0],dp[i+1][1]); // buy, not buy
            else dp[i][buy]=(i+2<=n) ? max(prices[i]+dp[i+2][1],dp[i+1][0]) : max(prices[i],dp[i+1][0]); //sell, not sell
        }
    }
    return dp[0][1];
}   

int maxProfit(vector<int>& prices) {
    // vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
    // return func(prices,0,1,dp);
    return tabulation(prices);
}

int main(){
    vector<int> prices = {1,2,3,0,2};
    cout<<maxProfit(prices)<<endl; //3
    return 0;
}