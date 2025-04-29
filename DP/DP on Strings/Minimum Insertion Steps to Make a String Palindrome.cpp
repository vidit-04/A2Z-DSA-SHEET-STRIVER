#include<bits/stdc++.h>
using namespace std;

int func(string& text1, string& text2,int i,int j,vector<vector<int>>& dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(text1[i]==text2[j]) dp[i][j]= 1+func(text1,text2,i-1,j-1,dp);
    else dp[i][j]=max(func(text1,text2,i-1,j,dp),func(text1,text2,i,j-1,dp));
    return dp[i][j];
}
int minInsertions(string s) {
    vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
    string srev=s;
    reverse(srev.begin(),srev.end());
    return s.size()-func(s,srev,s.size()-1,s.size()-1,dp);
    
}

int main(){
    string s="bbabcbcab";
    cout<<minInsertions(s)<<endl; //3

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
    cout<< n-dp[0][n-1];
    return 0;
}