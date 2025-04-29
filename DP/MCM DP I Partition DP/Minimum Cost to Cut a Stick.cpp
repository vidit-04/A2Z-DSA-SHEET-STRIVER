#include<bits/stdc++.h>
using namespace std;

int func(vector<int>& cuts,int i,int j,vector<vector<int>>& dp){
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mini=INT_MAX;
    for(int ind=i;ind<=j;ind++){
        int cost=cuts[j+1]-cuts[i-1]+func(cuts,i,ind-1,dp)+func(cuts,ind+1,j,dp);
        mini=min(mini,cost);
    }
    return dp[i][j]=mini;
}
int tabulation(int n,vector<int>& cuts){
    int c=cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    vector<vector<int>> dp(c+2,vector<int>(c+2,0));
    for(int i=c;i>=1;i--){
        for(int j=1;j<=c;j++){
            if(i>j) continue;
            int mini=INT_MAX;
            for(int ind=i;ind<=j;ind++){
                int cost=cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
                mini=min(mini,cost);
            }
            dp[i][j]=mini;
        }
    }
    return dp[1][c];
}
int minCost(int n, vector<int>& cuts) {
    // int c=cuts.size();
    // cuts.push_back(n);
    // cuts.insert(cuts.begin(),0);
    // sort(cuts.begin(),cuts.end());
    // vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
    // return func(cuts,1,c,dp); //n points to last element bcz One element is added to vector
    return tabulation(n,cuts);
}

int main(){
    int n=7;
    vector<int> cuts = {1,2,3,4,5};
    cout<<minCost(n,cuts)<<endl; //16
    // 16 is the minimum cost to cut the stick of length 7 at cuts {1,2,3,4,5}
        
    return 0;
}