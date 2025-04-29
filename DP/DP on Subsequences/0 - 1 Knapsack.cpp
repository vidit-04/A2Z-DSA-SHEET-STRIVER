#include<bits/stdc++.h>
using namespace std;

int func(int capacity, vector<int> &val, vector<int> &wt,int i,vector<vector<int>>& dp) {
    if(i==0){
        if(wt[i]<=capacity) return val[i];
        else return 0;
    }
    if(dp[i][capacity]!=-1) return dp[i][capacity];
    int nt=func(capacity,val,wt,i-1,dp);
    int t=0;
    if(wt[i]<=capacity) t=val[i]+func(capacity-wt[i],val,wt,i-1,dp);
    return dp[i][capacity]=max(t,nt);
}

int tabulation(int capacity, vector<int> &val, vector<int> &wt) {
    int n=wt.size();
    vector<vector<int>> dp(n,vector<int>(capacity+1,0));
    
    for(int cap=wt[0];cap<=capacity;cap++) dp[0][cap]=val[0];
    
    for(int i=1;i<n;i++){
        for(int cap=0;cap<=capacity;cap++){
            int nt=dp[i-1][cap];
            int t=0;
            if(wt[i]<=cap) t=val[i]+dp[i-1][cap-wt[i]];
            dp[i][cap]=max(t,nt);
        }
    }
    return dp[n-1][capacity];
}

int spaceOpt(int capacity, vector<int> &val, vector<int> &wt) {
    int n=wt.size();
    vector<int>prev(capacity+1,0),curr(capacity+1,0);
    
    for(int cap=wt[0];cap<=capacity;cap++) prev[cap]=val[0];
    
    for(int i=1;i<n;i++){
        for(int cap=capacity;cap>=0;cap--){
            int nt=prev[cap];
            int t=0;
            if(wt[i]<=cap) t=val[i]+prev[cap-wt[i]];
            curr[cap]=max(t,nt);
        }
        prev=curr;
    }
    return prev[capacity];
}

int spaceOpt2(int capacity, vector<int> &val, vector<int> &wt) {
    int n=wt.size();
    vector<int>prev(capacity+1,0);
    
    for(int cap=wt[0];cap<=capacity;cap++) prev[cap]=val[0];
    
    for(int i=1;i<n;i++){
        for(int cap=capacity;cap>=0;cap--){
            int nt=prev[cap];
            int t=0;
            if(wt[i]<=cap) t=val[i]+prev[cap-wt[i]];
            prev[cap]=max(t,nt);
        }
    }
    return prev[capacity];
}

int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
    // int n=wt.size();
    // vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
    // return func(capacity,val,wt,n-1,dp);
    // return tabulation(capacity,val,wt);
    return spaceOpt(capacity,val,wt);
    // return spaceOpt2(capacity,val,wt);
}

int main(){
    int capacity = 4;
    vector<int> val = {1, 2, 3};
    vector<int> wt = {4, 5, 1};
    cout<<knapSack(capacity, val, wt)<<endl; // Output: 3
    return 0;
}