#include<bits/stdc++.h>
using namespace std;

int func(vector<int>& prices,int i,bool buy,int cap,vector<vector<vector<int>>>& dp) {
    if(cap==0) return 0;
    if(i==prices.size()) return 0;
    if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
    if(buy) return dp[i][buy][cap]=max(-prices[i]+func(prices,i+1,0,cap,dp),func(prices,i+1,1,cap,dp));
    else return dp[i][buy][cap]=max(prices[i]+func(prices,i+1,1,cap-1,dp),func(prices,i+1,0,cap,dp));        
}
int tabulation(vector<int>& prices) {
    int n=prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){
                if(buy) dp[i][buy][cap]=max(-prices[i]+dp[i+1][0][cap],dp[i+1][1][cap]);
                else dp[i][buy][cap]=max(prices[i]+dp[i+1][1][cap-1],dp[i+1][0][cap]);        
            }
        }
    }
    return dp[0][1][2];
}
int spaceOpt(vector<int>& prices) {
    int n=prices.size();
    vector<vector<int>> after(2,vector<int>(3,0)),curr(2,vector<int>(3,0));
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){
                if(buy) curr[buy][cap]=max(-prices[i]+after[0][cap],after[1][cap]);
                else curr[buy][cap]=max(prices[i]+after[1][cap-1],after[0][cap]);        
            }
            after=curr;
        }
    }
    return after[1][2];
}
int func2(vector<int>& prices,int i,int trans,vector<vector<int>>& dp){
    if(i==prices.size()) return 0;
    if(trans==4) return 0;
    if(dp[i][trans]!=-1) return dp[i][trans];
    if(trans%2==0){
        return dp[i][trans]=max(-prices[i]+func2(prices,i+1,trans+1,dp),func2(prices,i+1,trans,dp));
    }
    else return dp[i][trans]=max(prices[i]+func2(prices,i+1,trans+1,dp),func2(prices,i+1,trans,dp));
}
int tabulation2(vector<int>& prices) {
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int>(5,0));
    for(int i=n-1;i>=0;i--){
        for(int trans=0;trans<=3;trans++){
            if(trans%2==0) dp[i][trans]=max(-prices[i]+dp[i+1][trans+1],dp[i+1][trans]);
            else dp[i][trans]=max(prices[i]+dp[i+1][trans+1],dp[i+1][trans]);
        }
    }
    return dp[0][0];
}
int spaceOpt2(vector<int>& prices) {
    int n=prices.size();
    vector<int> after(5,0),curr(5,0);
    for(int i=n-1;i>=0;i--){
        for(int trans=0;trans<=3;trans++){
            if(trans%2==0) curr[trans]=max(-prices[i]+after[trans+1],after[trans]);
            else curr[trans]=max(prices[i]+after[trans+1],after[trans]);
        }
        after=curr;
    }
    return after[0];
}
int spaceOpt3(vector<int>& prices) {
    int n=prices.size();
    vector<int> after(5,0);
    for(int i=n-1;i>=0;i--){
        for(int trans=0;trans<=3;trans++){
            if(trans%2==0) after[trans]=max(-prices[i]+after[trans+1],after[trans]);
            else after[trans]=max(prices[i]+after[trans+1],after[trans]);
        }
    }
    return after[0];
}
int maxProfit(vector<int>& prices) {
    // int n=prices.size();
    // vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    // return func(prices,0,1,2,dp);
    // return tabulation(prices);
    // return spaceOpt(prices);

    // int n=prices.size();
    // vector<vector<int>> dp(n,vector<int>(4,-1));
    // return func2(prices,0,0,dp);
    // return tabulation2(prices);
    // return spaceOpt2(prices);
    return spaceOpt3(prices);
}

int main(){
    vector<int> prices = {3,2,6,5,0,3};
    cout<<maxProfit(prices)<<endl; //7    
    return 0;
}