#include<bits/stdc++.h>
using namespace std;

int subs(string& s, string& t,int i,int j,vector<vector<int>>& dp){
    if(j<0) return 1;
    if(i==0){
        return s[i]==t[j] && j==0? 1 : 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int nt=subs(s,t,i-1,j,dp);
    int ta=0;
    if(s[i]==t[j]) ta=subs(s,t,i-1,j-1,dp);
    return dp[i][j]=ta+nt;
}
int tabulation(string s,string t){
    int n=s.size(),m=t.size();
    vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(m+1,0));
    dp[0][0]=1;
    for(int i=1;i<=n;i++) {
        dp[i][0]=1;
        for(int j=1;j<=m;j++){
            unsigned long long nt=dp[i-1][j];
            unsigned long long ta=0;
            if(s[i-1]==t[j-1]) ta=dp[i-1][j-1];
            dp[i][j]=ta+nt;
        }
    }
    return dp[n][m];
}
int spaceOpt(string s,string t){
    int n=s.size(),m=t.size();
    vector<unsigned long long> prev(m+1,0),curr(m+1,0);
    prev[0]=1;
    for(int i=1;i<=n;i++) {
        curr[0]=1;
        for(int j=1;j<=m;j++){
            unsigned long long nt=prev[j];
            unsigned long long ta=0;
            if(s[i-1]==t[j-1]) ta=prev[j-1];
            curr[j]=ta+nt;
        }
        prev=curr;
    }
    return prev[m];
}
int spaceOpt2(string s,string t){
    int n=s.size(),m=t.size();
    vector<unsigned long long> prev(m+1,0);
    prev[0]=1;
    for(int i=1;i<=n;i++) {
        for(int j=m;j>=1;j--){
            // unsigned long long nt=prev[j];
            // unsigned long long ta=0;
            // if(s[i-1]==t[j-1]) ta=prev[j-1];
            // prev[j]=ta+nt;
            if(s[i-1]==t[j-1]) prev[j]=prev[j]+prev[j-1];
        }
    }
    return prev[m];
}
int numDistinct(string s, string t) {
    // vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
    // return subs(s,t,s.size()-1,t.size()-1,dp);
    // return tabulation(s,t);
    // return spaceOpt(s,t);
    return spaceOpt2(s,t);
    //BOTTOM TOP
    // vector<vector<unsigned long long>> dp(s.size()+1,vector<unsigned long long>(t.size()+1,0));
    // dp[0][0]=1;
    // for(int i=1;i<=s.size();i++){
    //     dp[i][0]=1;
    //     for(int j=1;j<=t.size();j++){
    //         if(s[i-1]!=t[j-1]) dp[i][j]=dp[i-1][j];
    //         else dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
    //     }
    // }
    // return dp[s.size()][t.size()];
}

int main(){
    string s="rabbbit",t="rabbit";
    
    return 0;
}