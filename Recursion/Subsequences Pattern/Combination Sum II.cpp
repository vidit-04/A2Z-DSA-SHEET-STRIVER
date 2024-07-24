#include<bits/stdc++.h>
using namespace std;

void subs(vector<int>a,vector<vector<int>> &ans,vector<int> &temp,int index,int target){
    if(target==0){
        ans.push_back(temp);
        return;
    }
    for(int i=index;i<a.size();i++){
        if(i>index && a[i]==a[i-1]) continue;
        if(a[i]>target) break;
        temp.push_back(a[i]);
        subs(a,ans,temp,i+1,target-a[i]);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>>ans;
    vector<int>temp;
    sort(candidates.begin(),candidates.end());
    subs(candidates,ans,temp,0,target);
    return ans;
}

int main(){
    int n,target;
    cin>>n>>target;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    vector<vector<int>> ans=combinationSum2(a,target);
    for(auto x:ans){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }    
    return 0;
}