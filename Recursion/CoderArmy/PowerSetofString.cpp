#include<bits/stdc++.h>
using namespace std;

void subsequence(string a, int index, int n, vector<string> &ans,string temp){
    if(index==n){
        ans.push_back(temp);
        return;
    }
    //Not Included
    subsequence(a,index+1,n,ans,temp);
    //Included
    temp+=a[index];
    subsequence(a,index+1,n,ans,temp);
    //TIME AND SPACE COMPLEXTY
    //TIME: O(2^n)
    //SPACE: O(2^n)
}

int main(){
    string a="abcd";
    vector<string> ans;
    string temp;

    subsequence(a,0,a.size(),ans,temp);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}