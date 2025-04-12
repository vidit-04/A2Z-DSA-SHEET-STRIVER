#include<bits/stdc++.h>
using namespace std;

long long func(int row,int i,vector<vector<int>>& triangle,vector<vector<long long>>& dp){
    if(row>=triangle.size()) return 0;
    if(dp[row][i]!=-1) return dp[row][i];
    long long ans=LLONG_MAX;
    if(i<triangle[row].size()) ans=min(ans,triangle[row][i]+func(row+1,i,triangle,dp));
    if(i+1<triangle[row].size()) ans=min(ans,triangle[row][i+1]+func(row+1,i+1,triangle,dp));
    return dp[row][i]=ans;
}

int tabulation(vector<vector<int>>& triangle){
    int n=triangle.size();
    vector<vector<long long>> dp(n);
    for(int i=0;i<n;i++){
        dp[i]=vector<long long>(triangle[i].size(),0);
    }
    dp[0][0]=triangle[0][0];
    for(int i=1;i<n;i++){
        for(int j=0;j<triangle[i].size();j++){
            long long mini=LLONG_MAX;
            if(j<triangle[i-1].size()) mini=min(mini,dp[i-1][j]);
            if(j-1>=0) mini=min(mini,dp[i-1][j-1]);
            dp[i][j]=triangle[i][j]+mini;
        }
    }
    long long ans=LLONG_MAX;
    for(int i=0;i<triangle[n-1].size();i++){
        ans=min(ans,dp[n-1][i]);
    }
    return ans;
}

int spaceOptimization(vector<vector<int>>& triangle){
    int n=triangle.size();
    vector<int> front(n,0);
    for(int i=0;i<n;i++){
        front[i]=triangle[n-1][i];
    }

    for(int i=n-2;i>=0;i--){
        vector<int>curr(n,0);
        for(int j=triangle[i].size()-1;j>=0;j--){
            int d=triangle[i][j]+front[j];
            int dg=triangle[i][j]+front[j+1];
            curr[j]=min(d,dg);
        }
        front=curr;
    }
    return front[0];
}

int minimumTotal(vector<vector<int>>& triangle) {
    // int n=triangle.size();
    // vector<vector<long long>> dp(n);
    // for(int i=0;i<n;i++){
    //     dp[i]=vector<long long>(triangle[i].size(),-1);
    // }
    // return func(0,0,triangle,dp);
    // return tabulation(triangle);
    return spaceOptimization(triangle);
}

int main(){
    vector<vector<int>>triangle={{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<minimumTotal(triangle);
    return 0;
}