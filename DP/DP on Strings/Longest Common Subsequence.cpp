#include<bits/stdc++.h>
using namespace std;

int func(string text1, string text2,int i,int j,vector<vector<int>>& dp) {
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(text1[i]==text2[j]) return dp[i][j]=1+func(text1,text2,i-1,j-1,dp);
    else return dp[i][j]=max(func(text1,text2,i-1,j,dp),func(text1,text2,i,j-1,dp));
}

int func2(string text1, string text2,int i,int j,vector<vector<int>>& dp) {
    if(i==0 || j==0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(text1[i-1]==text2[j-1]) return dp[i][j]=1+func2(text1,text2,i-1,j-1,dp);
    else return dp[i][j]=max(func2(text1,text2,i-1,j,dp),func2(text1,text2,i,j-1,dp));
}

int tabulation(string text1, string text2) {
    int n=text1.size(),m=text2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    // for(int i=0;i<=n;i++) dp[i][0]=0;
    // for(int i=0;i<=m;i++) dp[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int spaceOpt(string text1, string text2) {
    int n=text1.size(),m=text2.size();
    vector<int> prev(m+1,0),curr(m+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(text1[i-1]==text2[j-1]) curr[j]=1+prev[j-1];
            else curr[j]=max(prev[j],curr[j-1]);
        }
        prev=curr;
    }
    return prev[m];
}

int longestCommonSubsequence(string text1, string text2) {
    int n=text1.size(),m=text2.size();
    // vector<vector<int>> dp(n+1,vector<int>(m,-1));
    // return func(text1,text2,n-1,m-1,dp);
    // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    // return func2(text1,text2,n,m,dp);
    // return tabulation(text1,text2);
    return spaceOpt(text1,text2);
}


int main(){
    string text1="abcde",text2="ace";
    cout<<longestCommonSubsequence(text1,text2)<<endl; //3

    return 0;
}