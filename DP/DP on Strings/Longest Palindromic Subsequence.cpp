#include<bits/stdc++.h>
using namespace std;

int LPS(string& s,int i,int j,vector<vector<int>>& dp){
    if(i==j) return 1;
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==s[j]) dp[i][j]= 2+LPS(s,i+1,j-1,dp);
    else dp[i][j]= max(LPS(s,i+1,j,dp),LPS(s,i,j-1,dp));
    return dp[i][j];
}
int longestPalindromeSubseq(string s) {
    vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,-1));
    return LPS(s,0,s.size()-1,dp);
}

int main(){
    string s="bbabcbcab";
    return longestPalindromeSubseq(s);
    int n=s.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        dp[i][i]=1;
    }
    //diagonal fill up for bottom top
    int k=1;
    while(k<n){
        int i=0;
        int j=k;
        while(i<n && j<n){
            if(s[i]==s[j]) dp[i][j]=2+dp[i+1][j-1];
            else dp[i][j]= max(dp[i+1][j],dp[i][j-1]);
            i++;
            j++;
        }
        k++;
    }
    cout<<dp[0][n-1];
    return 0;
}