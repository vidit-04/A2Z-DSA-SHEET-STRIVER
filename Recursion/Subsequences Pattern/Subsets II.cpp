#include<bits/stdc++.h>
using namespace std;

void subs(vector<int>a,int n,int index,set<vector<int>> &ans,vector<int> &temp){
    if(index==a.size()){
        ans.insert(temp);
        return;
    }
    subs(a,n,index+1,ans,temp);
    temp.push_back(a[index]);
    subs(a,n,index+1,ans,temp);
    temp.pop_back();        
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    set<vector<int>> ans;
    vector<int> temp;
    sort(nums.begin(), nums.end());
    subs(nums,nums.size(),0, ans,temp);
    return vector<vector<int>>(ans.begin(), ans.end());
}

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    vector<vector<int>> ans=subsetsWithDup(a);
    for(auto x:ans){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }    
    return 0;
}