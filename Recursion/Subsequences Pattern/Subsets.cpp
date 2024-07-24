#include<bits/stdc++.h>
using namespace std;

void subsequence(vector<int>a, int index, int n, vector<vector<int>> &ans, vector<int> temp){
    if(index==n){
        ans.push_back(temp);
        return;
    }
    //Not Included
    subsequence(a,index+1,n,ans,temp);
    //Included
    temp.push_back(a[index]);
    subsequence(a,index+1,n,ans,temp);
    //TIME AND SPACE COMPLEXTY
    //TIME: O(2^n)
    //SPACE: O(2^n)
}
vector<vector<int>> subsets(vector<int>& a) {
    // int n=nums.size();
    // int subsets=1<<n;
    // vector<vector<int>> ans;
    // for(int i=0;i<subsets;i++){
    //     vector<int> temp;
    //     for(int j=0;j<n;j++){
    //         if(i&(1<<j)){
    //             temp.push_back(nums[j]);
    //         }
    //     }
    //     ans.push_back(temp);
    // }
    // return ans;
    vector<vector<int>> ans;
    vector<int> temp;
    subsequence(a,0,a.size(),ans,temp);
    return ans;
}

int main(){
    vector<int> a={1,2,3};
    vector<vector<int>> ans=subsets(a);
    for(auto x:ans){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}