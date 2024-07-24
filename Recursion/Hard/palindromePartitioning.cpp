#include<bits/stdc++.h>
using namespace std;

bool ispalindrome(string s, int start, int end){
    while(start<=end){
        if(s[start++]!=s[end--]) return false;
    }
    return true;
}
void func(string s,vector<vector<string>> &ans,vector<string> &temp,int index){
    if(index==s.size()){
        ans.push_back(temp);
        return;
    }
    for(int i=index;i<s.size();++i){
        if(ispalindrome(s,index,i)){
            temp.push_back(s.substr(index,i-index+1));
            func(s,ans,temp,i+1);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string>temp;
    func(s,ans,temp,0);
    return ans;
}

int main(){
    
    return 0;
}