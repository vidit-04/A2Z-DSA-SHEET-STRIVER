#include<bits/stdc++.h>
using namespace std;

int func(vector<int>& val, vector<int>& wt, int capacity,int i,vector<vector<int>>& dp) {
    if(i==0){
        return ((int)capacity/wt[0])*val[0];
    }
    if(dp[i][capacity]!=-1) return dp[i][capacity];
    int np=func(val,wt,capacity,i-1,dp);
    int p=INT_MIN;
    if(wt[i]<=capacity) p=val[i]+func(val,wt,capacity-wt[i],i,dp);
    return dp[i][capacity]=max(p,np);
}

int tabulation(vector<int>& val, vector<int>& wt, int capacity) {
    int n=wt.size();
    vector<vector<int>> dp(n,vector<int>(capacity+1,0));
    for(int i=0;i<=capacity;i++){
        dp[0][i]=((int)i/wt[0])*val[0];
    }
    
    for(int i=1;i<n;i++){
        for(int cap=0;cap<=capacity;cap++){
            int np=dp[i-1][cap];
            int p=INT_MIN;
            if(wt[i]<=cap) p=val[i]+dp[i][cap-wt[i]];
            dp[i][cap]=max(p,np);
        }
    }
    return dp[n-1][capacity];
}
int spaceOpt(vector<int>& val, vector<int>& wt, int capacity) {
    int n=wt.size();
    vector<int> prev(capacity+1,0),curr(capacity+1,0);
    for(int i=0;i<=capacity;i++){
        prev[i]=((int)i/wt[0])*val[0];
    }
    
    for(int i=1;i<n;i++){
        for(int cap=0;cap<=capacity;cap++){
            int np=prev[cap];
            int p=INT_MIN;
            if(wt[i]<=cap) p=val[i]+curr[cap-wt[i]];
            curr[cap]=max(p,np);
        }
        prev=curr;
    }
    return prev[capacity];
}
int spaceOpt2(vector<int>& val, vector<int>& wt, int capacity) {
    int n=wt.size();
    vector<int> prev(capacity+1,0);
    for(int i=0;i<=capacity;i++){
        prev[i]=((int)i/wt[0])*val[0];
    }
    
    for(int i=1;i<n;i++){
        for(int cap=0;cap<=capacity;cap++){
            int np=prev[cap];
            int p=INT_MIN;
            if(wt[i]<=cap) p=val[i]+prev[cap-wt[i]];
            prev[cap]=max(p,np);
        }
    }
    return prev[capacity];
}
int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
    // int n=wt.size();
    // vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
    // return func(val,wt,capacity,n-1,dp);
    // return tabulation(val,wt,capacity);
    // return spaceOpt(val,wt,capacity);
    return spaceOpt2(val,wt,capacity);
}

int main(){
    vector<int> val={60,100,120};
    vector<int> wt={10,20,30};
    int capacity=50;
    cout<<knapSack(val,wt,capacity)<<endl; // 220
    return 0;
}