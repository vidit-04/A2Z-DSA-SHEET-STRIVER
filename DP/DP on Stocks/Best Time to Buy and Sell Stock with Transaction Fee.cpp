#include<bits/stdc++.h>
using namespace std;

int tabulation(vector<int>& prices,int fee){
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            if(buy) dp[i][buy]=max(-prices[i]+dp[i+1][0],dp[i+1][1]); // buy, not buy
            else dp[i][buy]=max(prices[i]+dp[i+1][1]-fee,dp[i+1][0]); //sell, not sell
        }
    }
    return dp[0][1];
}
int spaceOpt3(vector<int>& prices,int fee){ //buy and sell stock 2
    int n=prices.size();
    int nextNotBuy=0,nextBuy=0,currNotBuy=0,currBuy=0;
    for(int i=n-1;i>=0;i--){
        currNotBuy=max(prices[i]+nextBuy,nextNotBuy);
        currBuy=max(-prices[i]+nextNotBuy-fee,nextBuy);
        nextNotBuy=currNotBuy;
        nextBuy=currBuy;
    }
    return nextBuy;
}
int maxProfit(vector<int>& prices, int fee) {
    // return tabulation(prices,fee);
    return spaceOpt3(prices,fee);
}

int main(){
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;    
    cout<<maxProfit(prices,fee)<<endl; //8    
    return 0;
}