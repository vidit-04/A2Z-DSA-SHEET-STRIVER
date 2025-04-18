#include<bits/stdc++.h>
using namespace std;

bool func(string& s, string& p,int i,int j,vector<vector<int>>& dp) {
    if(i<0 && j<0) return true;
    if(i<0 && j>=0)return false;
    if(j<0 && i>=0){
        for(int k=0;k<=i;k++){
            if(s[k]!='*') return false;
        }
        return true;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==p[j] || s[i]=='?') return dp[i][j]=func(s,p,i-1,j-1,dp);
    if(s[i]=='*') return dp[i][j]=func(s,p,i-1,j,dp) | func(s,p,i,j-1,dp);
    return dp[i][j]=false;
}
bool func2(string& s, string& p,int i,int j,vector<vector<int>>& dp) {
    if(i==0 && j==0) return true;
    if(i==0 && j>0) return false;
    if(j==0 && i>0){
        for(int k=1;k<=i;k++){
            if(s[k-1]!='*') return false;
        }
        return true;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i-1]==p[j-1] || s[i-1]=='?') return dp[i][j]=func2(s,p,i-1,j-1,dp);
    if(s[i-1]=='*') return dp[i][j]=func2(s,p,i-1,j,dp) | func2(s,p,i,j-1,dp);
    return dp[i][j]=false;
}
bool tabulation(string& s, string& p) {
    int n=s.size(),m=p.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        bool flag=true;
        for(int k=1;k<=i;k++){
            if(s[k-1]!='*'){
                flag= false;
                break;
            }
        }
        dp[i][0]=flag;
        if(!flag) break;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==p[j-1] || s[i-1]=='?') dp[i][j]=dp[i-1][j-1];
            else if(s[i-1]=='*') dp[i][j]=dp[i-1][j] | dp[i][j-1];
            else dp[i][j]=false;
        }
    }
    return dp[n][m];
}
bool spaceOpt(string& s, string& p) {
    int n=s.size(),m=p.size();
    vector<int> prev(m+1,0),curr(m+1,0);
    prev[0]=1;
    for(int i=1;i<=n;i++){
        curr[0]=s[i-1]=='*'? prev[0]: 0;
        for(int j=1;j<=m;j++){
            if(s[i-1]==p[j-1] || s[i-1]=='?') curr[j]=prev[j-1];
            else if(s[i-1]=='*') curr[j]=prev[j] | curr[j-1];
            else curr[j]=false;
        }
        prev=curr;
    }
    return prev[m];
}

bool isMatch(string s, string p) {
    // int n=s.size(),m=p.size();
    // vector<vector<int>> dp(m,vector<int>(n,-1));
    // return func(p,s,m-1,n-1,dp);
    // int n=s.size(),m=p.size();
    // vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    // return func2(p,s,m,n,dp);
    // return tabulation(p,s);
    return spaceOpt(p,s);
}

int main(){
    string s="adceb",p="*a*b";
    cout<<isMatch(s,p)<<endl; //1    
    return 0;
}