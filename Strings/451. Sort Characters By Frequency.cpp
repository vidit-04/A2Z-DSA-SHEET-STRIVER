#include<bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
    vector<pair<int,char>>hash('z'+1,{0,0});
    for(auto i:s){
        hash[i]={hash[i].first+1,i};
    }
    sort(hash.begin(),hash.end());
    string ans;
    for(auto i:hash){
        ans=string(i.first,i.second)+ans;
    }
    return ans;
}

int main(){
    string s="tree";
    cout<<frequencySort(s);    
    return 0;
}