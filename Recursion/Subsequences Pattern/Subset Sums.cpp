#include<bits/stdc++.h>
using namespace std;

void subs(vector<int>a,vector<int> &ans,int index,int sum){
    if(index==a.size()){
        ans.push_back(sum);
        return;
    }
    subs(a,ans,index+1,sum);
    sum+=a[index];
    subs(a,ans,index+1,sum);
    sum-=a[index];
}
vector<int> subsetSums(vector<int> arr, int n) {
    // Write Your Code here
    vector<int> ans;
    int sum=0;
    subs(arr,ans,0,sum);
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    vector<int> ans=subsetSums(a,n);
    for(auto x:ans){
        cout<<x<<" ";
    }    
    return 0;
}