#include<bits/stdc++.h>
using namespace std;

int func(vector<int>& val, int capacity,int i,vector<vector<int>>& dp) {
    if(i==0){
        return capacity*val[0];
    }
    if(dp[i][capacity]!=-1) return dp[i][capacity];
    int np=func(val,capacity,i-1,dp);
    int p=INT_MIN;
    int rodlength=i+1;
    if(rodlength<=capacity) p=val[i]+func(val,capacity-rodlength,i,dp);
    return dp[i][capacity]=max(p,np);
}

int tabulation(vector<int>& val, int capacity) {
    int n=val.size();
    vector<vector<int>> dp(n,vector<int>(capacity+1,0));
    for(int i=0;i<=capacity;i++){
        dp[0][i]=i*val[0];
    }
    
    for(int i=1;i<n;i++){
        for(int cap=0;cap<=capacity;cap++){
            int np=dp[i-1][cap];
            int p=INT_MIN;
            int rodlength=i+1;
            if(rodlength<=cap) p=val[i]+dp[i][cap-rodlength];
            dp[i][cap]=max(p,np);
        }
    }
    return dp[n-1][capacity];
}
int spaceOpt(vector<int>& val, int capacity) {
    int n=val.size();
    vector<int> prev(capacity+1,0),curr(capacity+1,0);
    for(int i=0;i<=capacity;i++){
        prev[i]=i*val[0];
    }
    
    for(int i=1;i<n;i++){
        for(int cap=0;cap<=capacity;cap++){
            int np=prev[cap];
            int p=INT_MIN;
            int rodlength=i+1;
            if(rodlength<=cap) p=val[i]+curr[cap-rodlength];
            curr[cap]=max(p,np);
        }
        prev=curr;
    }
    return prev[capacity];
}
int spaceOpt2(vector<int>& val,int capacity) {
    int n=val.size();
    vector<int> prev(capacity+1,0);
    for(int i=0;i<=capacity;i++){
        prev[i]=i*val[0];
    }
    
    for(int i=1;i<n;i++){
        for(int cap=0;cap<=capacity;cap++){
            int np=prev[cap];
            int p=INT_MIN;
            int rodlength=i+1;
            if(rodlength<=cap) p=val[i]+prev[cap-rodlength];
            prev[cap]=max(p,np);
        }
    }
    return prev[capacity];
}
int cutRod(vector<int> &price) {
    // code here
    int n=price.size();
    // vector<vector<int>>dp(n,vector<int>(n+1,-1));
    // return func(price,n,n-1,dp);
    // return tabulation(price,n);
    // return spaceOpt(price,n);
    return spaceOpt2(price,n);
}

int main(){
    vector<int>price={1, 5, 8, 9, 10, 17, 17, 20};
    cout<<cutRod(price)<<endl; //22
    return 0;
}