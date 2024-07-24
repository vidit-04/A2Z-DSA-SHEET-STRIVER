#include<bits/stdc++.h>
using namespace std;

void subs(vector<int>a,int n,vector<vector<int>> &ans,vector<int> &temp,int index,int k,int sum){
    if(temp.size()==k && sum==0){
        ans.push_back(temp);
        return;
    }
    if(index==n || sum<0) return;
    subs(a,n,ans,temp,index+1,k,sum);
    temp.push_back(a[index]);
    subs(a,n,ans,temp,index+1,k,sum-a[index]);
    temp.pop_back();
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<int>a={1,2,3,4,5,6,7,8,9};
    vector<vector<int>>ans;
    vector<int>temp;
    subs(a,a.size(),ans,temp,0,k,n);
    return ans;
}

int main(){
    int k,n;
    cin>>k>>n;
    vector<vector<int>> ans=combinationSum3(k,n);
    for(auto x:ans){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }    
    return 0;
}