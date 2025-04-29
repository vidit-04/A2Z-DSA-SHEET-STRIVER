#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> tabulation(string text1, string text2) {
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
    return dp;
}
string all_longest_common_subsequences(string s, string t) {
    // Code here
    vector<vector<int>> dp=tabulation(s,t);
    int i=s.size(),j=t.size();
    string ans;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            ans=s[i-1]+ans;
            i--;j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else j--;
    }
    return ans;
}

int main(){
    string s="abcde",t="ace";
    cout<<all_longest_common_subsequences(s,t)<<endl; //ace
    return 0;
}