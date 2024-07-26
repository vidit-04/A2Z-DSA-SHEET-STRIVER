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
    // For ex- if we have a.size()=3, then number ofsubsets will be 2^n
    //We map characters with this
    // 000->{}
    // 001->{3}
    // 010->{2}
    // 011->{2,3}
    // 100->{1}
    // 101->{1,3}
    // 110->{1,2}
    // 111->{1,2,3}
    // So, we can see that all the subsets are there
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