#include<bits/stdc++.h>
using namespace std;

void subsequence(vector<int>a,vector<vector<int>> &ans,vector<int> &temp,int index,int target){
    if(target==0){
        ans.push_back(temp);
        return;
    }
    if(index==a.size() || target<0) return;
    subsequence(a,ans,temp,index+1,target);
    temp.push_back(a[index]);
    subsequence(a,ans,temp,index,target-a[index]);
    temp.pop_back();
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>>ans;
    vector<int>temp;
    subsequence(candidates,ans,temp,0,target);
    return ans;
}

int main(){
    int n,target;
    cin>>n>>target;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    vector<vector<int>> ans=combinationSum(a,target);
    for(auto x:ans){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
        
    return 0;
}