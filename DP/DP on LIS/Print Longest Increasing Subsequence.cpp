#include<bits/stdc++.h>
using namespace std;

vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
    // Code here
    vector<int> par(n),lis(n,1);
    int max_lis=1,ans_idx=0;
    par[0]=0; //in par we just keep the track of which index is the previous index of the current index in the longest increasing subsequence
    for(int i=1;i<n;i++){
        par[i]=i;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] && 1+lis[j]>lis[i]){
                lis[i]=1+lis[j];
                par[i]=j;
            }
        }
        if(max_lis<lis[i]){
            max_lis=lis[i];
            ans_idx=i;
        }
    }
    vector<int> ans;
    while(1){
        ans.push_back(arr[ans_idx]);
        if(ans_idx==par[ans_idx]) break;
        ans_idx=par[ans_idx];
    }
    reverse(ans.begin(),ans.end());
    return ans;
    
}

int main(){
    int n=7;
    vector<int> arr={1,2,3,4,5,6,7};
    vector<int> ans=longestIncreasingSubsequence(n,arr);
    for(auto i:ans) cout<<i<<" ";
    cout<<endl;
    // 1 2 3 4 5 6 7   
    return 0;
}