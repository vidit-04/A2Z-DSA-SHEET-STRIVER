#include<bits/stdc++.h>
using namespace std;

int func(string& word1, string& word2,int i,int j,vector<vector<int>>& dp) {
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(word1[i]==word2[j]) return dp[i][j]=func(word1,word2,i-1,j-1,dp);
    else return dp[i][j]=1+min(func(word1,word2,i,j-1,dp),min(func(word1,word2,i-1,j,dp),func(word1,word2,i-1,j-1,dp)));
}
int func2(string& word1, string& word2,int i,int j,vector<vector<int>>& dp) {
    if(i==0) return j;
    if(j==0) return i;
    if(dp[i][j]!=-1) return dp[i][j];
    if(word1[i-1]==word2[j-1]) return dp[i][j]=func2(word1,word2,i-1,j-1,dp);
    else return dp[i][j]=1+min(func2(word1,word2,i,j-1,dp),min(func2(word1,word2,i-1,j,dp),func2(word1,word2,i-1,j-1,dp)));
}
int tabulation(string word1, string word2) {
    int n=word1.size(),m=word2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int j=0;j<=m;j++) dp[0][j]=j;
    for(int i=0;i<=n;i++) dp[i][0]=i;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
        }
    }
    return dp[n][m];
}
int spaceOpt(string word1, string word2) {
    int n=word1.size(),m=word2.size();
    vector<int> prev(m+1),curr(m+1,0);
    for(int j=0;j<=m;j++) prev[j]=j;

    for(int i=1;i<=n;i++){
        curr[0]=i;
        for(int j=1;j<=m;j++){
            if(word1[i-1]==word2[j-1]) curr[j]=prev[j-1];
            else curr[j]=1+min(curr[j-1],min(prev[j],prev[j-1]));
        }
        prev=curr;
    }
    return prev[m];
}
int minDistance(string word1, string word2) {
    // int n=word1.size(),m=word2.size();
    // vector<vector<int>> dp(n,vector<int>(m,-1));
    // return func(word1,word2,n-1,m-1,dp);

    // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    // return func2(word1,word2,n,m,dp);
    // return tabulation(word1,word2);
    return spaceOpt(word1,word2);
}

int main(){
    string s1="sea",s2="eat";
    cout<<minDistance(s1,s2)<<endl; //2
    return 0;
}