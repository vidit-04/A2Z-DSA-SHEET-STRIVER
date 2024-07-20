#include<bits/stdc++.h>
using namespace std;

void subsequence(vector<int>a, int index, int n, vector<vector<int>> &ans, vector<int> &temp){
    if(index==n){
        ans.push_back(temp);
        return;
    }
    //Not Included
    subsequence(a,index+1,n,ans,temp);
    //Included
    temp.push_back(a[index]);
    subsequence(a,index+1,n,ans,temp);
    temp.pop_back();
    //TIME AND SPACE COMPLEXTY
    //TIME: O(2^n)
    //SPACE: O(2^n)
}

int main(){
    vector<int>a={1,2,3};
    vector<vector<int>> ans;
    vector<int> temp;

    subsequence(a,0,a.size(),ans,temp);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}