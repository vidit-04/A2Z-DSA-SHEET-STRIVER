#include<bits/stdc++.h>
using namespace std;

int func(string word1, string word2,int i,int j,vector<vector<int>>& dp){
    if(i==0 || j==0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(word1[i-1]==word2[j-1]) return dp[i][j]= 1+func(word1,word2,i-1,j-1,dp);
    else return dp[i][j]= max(func(word1,word2,i-1,j,dp),func(word1,word2,i,j-1,dp));
}

int tabulation(string word1, string word2) {
    int n=word1.size(),m=word2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(word1[i-1]==word2[j-1]) dp[i][j]= 1+dp[i-1][j-1];
            else dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}
int spaceOpt(string word1, string word2) {
    int n=word1.size(),m=word2.size();
    vector<int> prev(m+1,0),curr(m+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(word1[i-1]==word2[j-1]) curr[j]= 1+prev[j-1];
            else curr[j]= max(prev[j],curr[j-1]);
        }
        prev=curr;
    }
    return prev[m];
}
int minDistance(string word1, string word2) {
    int n=word1.size(),m=word2.size();
    // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    // int ans=func(word1,word2,n,m,dp); //longest common subsequence
    // int ans=tabulation(word1,word2);
    int ans=spaceOpt(word1,word2);
    return (n-ans)+(m-ans);
}

int main(){
    string s1="sea",s2="eat";
    cout<<minDistance(s1,s2)<<endl; //2
    return 0;
}