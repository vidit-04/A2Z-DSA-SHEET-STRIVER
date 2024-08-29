#include<bits/stdc++.h>
using namespace std;

string MinimumWindowSubstring(string s,string t){
    //BRUTE FORCE
    int n=s.size();
    int m=t.size();
    int minLen=INT_MAX;
    int sIndex=0; 
    for(int i=0;i<n;i++){
        vector<int>hash(256,0);
        int cnt=0;
        for(int j=0;j<m;j++){
            hash[t[j]]++;
        }
        for(int j=i;j<n;j++){
            if(hash[s[j]]>0) cnt++;
            hash[s[j]]--;
            if(cnt==m){
                if(minLen>j-i+1){
                    minLen=j-i+1;
                    sIndex=i;
                }
                break;
            }
        }
    }
    return s.substr(sIndex,minLen);
    //T.C.-O(N^2)
    //S.C.-O(256)
}

int main(){
    //MINIMUM WINDOW SUBSTRING
    string s="ddaaabbca";
    string t="abc";
    cout<<MinimumWindowSubstring(s,t);
    return 0;
}