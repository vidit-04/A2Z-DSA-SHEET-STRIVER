#include<bits/stdc++.h>
using namespace std;

int func(vector<int>& height,int i,vector<int>& dp){
    if(i==0) return 0;
    if(dp[i]!=-1) return dp[i];
    int left=func(height,i-1,dp)+abs(height[i]-height[i-1]);
    int right=INT_MAX;
    if(i>1){
        right=func(height,i-2,dp)+abs(height[i]-height[i-2]);
    }
    return dp[i]=min(left,right);
    
}
int minCost(vector<int>& height) {
    //Memoization Approach
    int n=height.size();
    vector<int> dp(n+1,-1);
    return func(height,n-1,dp);
}

int main(){
    
    //BOTTOM UP DP
    int n;
    cin>>n;
    vector<int> height(n);
    vector<int>dp(n,0);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int fst=dp[i-1]+abs(height[i]-height[i-1]);
        int snd=INT_MAX;
        if(i>1){
            snd=dp[i-2]+abs(height[i]-height[i-2]);
        }
        dp[i]=min(fst,snd);
    }
    cout<<dp[n-1]<<endl;



    //Space Optimized DP
    int prev=0;
    int prev2=0;
    for(int i=1;i<n;i++){
        int fst=prev+abs(height[i]-height[i-1]);
        int snd=INT_MAX;
        if(i>1){
            snd=prev2+abs(height[i]-height[i-2]);
        }
        int curri=min(fst,snd);
        prev2=prev;
        prev=curri;
    }
    cout<<prev<<endl;
    
    return 0;
}