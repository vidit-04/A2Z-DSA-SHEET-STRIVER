#include<bits/stdc++.h>
using namespace std;

void Generateparenthesis(int n,string &temp,vector<string> &ans, int l, int r){
    if(l==n && r==n){
        ans.push_back(temp);
        return;
    }
    if(l<n){
        temp+="(";
        Generateparenthesis(n,temp,ans,l+1,r);
        temp.pop_back();
    }
    if(l>r){
        temp+=")";
        Generateparenthesis(n,temp,ans,l,r+1);
        temp.pop_back();
    }
    //T.C.-O(2^n)
    //S.C.-O(2^n)
}

int main(){
    int n=3;
    vector<string> ans;
    string temp;
    Generateparenthesis(n,temp,ans,0,0);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}