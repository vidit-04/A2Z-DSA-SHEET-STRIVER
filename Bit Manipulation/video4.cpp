#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> SubsetsOfArray(vector<int> a){
    int n=a.size();
    vector<vector<int>> ans;
    int subsets=1<<n;  //If size of a=3 then all the subset will count to be 2^3=8
    for(int i=0;i<subsets;i++){
        vector<int> temp;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                temp.push_back(a[j]);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

int main(){
    vector<int>a={1,2,3};
    vector<vector<int>> ans=SubsetsOfArray(a);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}