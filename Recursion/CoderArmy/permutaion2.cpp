#include<bits/stdc++.h>
using namespace std;

void permutations(vector<int>a,vector<vector<int>> &ans,int index){
    if(index==a.size()){
        ans.push_back(a);
        return;
    }
    vector<bool>used(21,0);
    for(int i=index;i<a.size();i++){
        if(used[a[i]+10]==0){
            swap(a[i],a[index]);
            permutations(a,ans,index+1);
            swap(a[i],a[index]);
            used[a[i]+10]=1;
        }
    }
}

int main(){
    vector<int>a={1,1,2};
    vector<vector<int>>ans;
    permutations(a,ans,0);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}