#include<bits/stdc++.h>
using namespace std;

bool IsomorphicStrings(string s, string t){
    if(s.length()!=t.length()) return false;
    unordered_map<char,char>mp;
    int i=0;
    while(i<s.size()){
        if(mp.find(s[i])==mp.end()){
            for(auto it:mp){
                if(it.second==t[i]) return false;
            }
            mp[s[i]]=t[i];  
        }
        else{
            if(mp[s[i]]!=t[i]) return false;
        }
        i++;
    }
    return true;
}

int main(){
    string s="library";
    string t="privacy";
    cout<<IsomorphicStrings(s,t);        
    return 0;
}