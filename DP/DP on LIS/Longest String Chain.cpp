#include<bits/stdc++.h>
using namespace std;

bool checkPossible(string& s1,string& s2){
    if(s1.size()!=s2.size()+1) return false;
    int first=0;
    int second=0;
    while(first<s1.size()){
        if(s1[first]==s2[second]){
            first++;
            second++;
        }
        else first++;
    }
    return first==s1.size() && second==s2.size();
}
static bool cmp(string a,string b){
    return a.size()<b.size();
}
int longestStrChain(vector<string>& words) {
    sort(words.begin(),words.end(),cmp); //sort on the basis of short strings
    int n=words.size();
    vector<int>dp(n,1);//to print the LIS
    int maxi=1;
    for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(checkPossible(words[i],words[prev])  && dp[prev]+1>dp[i]){
                dp[i]=dp[prev]+1;
            }
        }
        maxi=max(maxi,dp[i]);
    }
    return maxi;        
}

int main(){
    vector<string> words = {"a","b","ba","bca","bda","bdca"};
    cout<<longestStrChain(words)<<endl; //5   
    return 0;
}