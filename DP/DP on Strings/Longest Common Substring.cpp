#include<bits/stdc++.h>
using namespace std;

int longestCommonSubstr(string& text1, string& text2) {
    int n=text1.size(),m=text2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(text1[i-1]==text2[j-1]) {
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(ans,dp[i][j]);
            }
            else dp[i][j]=0;
        }
    }
    return ans;

}


int longestCommonSubstr2(string& text1, string& text2) {
    int n=text1.size(),m=text2.size();
    vector<int> prev(m+1,0),curr(m+1,0);
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(text1[i-1]==text2[j-1]) {
                curr[j]=1+prev[j-1];
                ans=max(ans,curr[j]);
            }
            else curr[j]=0;
        }
        prev=curr;
    }
    return ans;

}

int main(){
    string s1="abcde";
    string s2="abfce";
    //Code is picked from longest Common subsequence
    cout<<longestCommonSubstr(s1,s2)<<endl; //3
    cout<<longestCommonSubstr2(s1,s2)<<endl; //3
    return 0;
}