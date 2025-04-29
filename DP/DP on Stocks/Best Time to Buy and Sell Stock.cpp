#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int buy = prices[0];
    int profit = 0;
    for (int i = 1; i < prices.size(); i++) {
        profit=max(profit,prices[i]-buy);
        buy=min(buy,prices[i]);
    }
    return profit;
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout<<maxProfit(prices)<<endl; //5
    return 0;
}