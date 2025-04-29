#include<bits/stdc++.h>
using namespace std;

bool func(vector<int>& arr,int i, int target,int n,vector<vector<int>>& dp){
    if(target==0) return true;
    if(i==0) return arr[0]==target;
    if(dp[i][target]!=-1) return dp[i][target];
    
    bool nt=func(arr,i-1,target,n,dp);
    bool t=false;
    if(arr[i]<=target) t=func(arr,i-1,target-arr[i],n,dp);
    
    return dp[i][target]=nt||t;
}

bool tabulation(vector<int>& arr, int tgt){
    vector<vector<bool>> dp(arr.size(),vector<bool>(tgt+1,false));
    for(int i=0;i<arr.size();i++) dp[i][0]=1;
    dp[0][arr[0]]=1;
    for(int i=1;i<arr.size();i++){
        for(int target=1;target<=tgt;target++){
            bool nt=dp[i-1][target];
            bool t=false;
            if(arr[i]<=target) t=dp[i-1][target-arr[i]];
            dp[i][target]=nt||t;
        }
    }
    return dp[arr.size()-1][tgt];
}

bool spaceOpt(vector<int>& arr, int tgt){
    vector<bool>prev(tgt+1,false), curr(tgt+1,false);
    prev[0]=curr[0]=true;
    
    prev[arr[0]]=1;
    for(int i=1;i<arr.size();i++){
        for(int target=1;target<=tgt;target++){
            bool nt=prev[target];
            bool t=false;
            if(arr[i]<=target) t=prev[target-arr[i]];
            curr[target]=nt||t;
        }
        prev=curr;
    }
    return prev[tgt];
}



bool isSubsetSum(vector<int>& arr, int target) {
    // vector<vector<int>> dp(arr.size(),vector<int>(target+1,-1));
    // return func(arr,arr.size()-1,target,arr.size(),dp);
    // return tabulation(arr,target);
    return spaceOpt(arr,target);
}

int main(){
    vector<int> arr={3, 34, 4, 12, 5, 2};
    int target=9;
    cout<<isSubsetSum(arr,target)<<endl;
    return 0;
}