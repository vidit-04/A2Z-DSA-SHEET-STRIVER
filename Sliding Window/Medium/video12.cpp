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

string MinimumWindowSubstringApproach2(string s,string t){
    //OPTIMAL APPROACH
    int n=s.size();
    int m=t.size();
    int minLen=INT_MAX;
    int sIndex=-1; 
    vector<int>hash(256,0);
    int l=0,r=0;
    int cnt=0;

    for(int i=0;i<m;i++){
        hash[t[i]]++;
    }

    while(r<n){
        if(hash[s[r]]>0) cnt++;
        hash[s[r]]--;

        while(cnt==m){
            if(r-l+1< minLen){
                minLen=r-l+1;
                sIndex=l;
            }
            hash[s[l]]++;
            if(hash[s[l]]>0) cnt--;
            l++;
        }
        r++;
    }
    
    return sIndex==-1?"":s.substr(sIndex,minLen);
    //T.C.-O(N)
    //S.C.-O(256)
}

int main(){
    //MINIMUM WINDOW SUBSTRING
    string s="ddaaabbca";
    string t="abc";
    cout<<MinimumWindowSubstringApproach2(s,t);
    return 0;
}