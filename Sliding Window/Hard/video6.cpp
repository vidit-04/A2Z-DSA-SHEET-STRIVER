#include<bits/stdc++.h>
using namespace std;

int LongestSubstringWithKDistinctCharacters(string s,int k){
    //BRUTE FORCE
    int maxLen=0;
    map<char,int>mpp;
    int n=s.length();
    for(int i=0;i<n;i++){
        mpp.clear();
        for(int j=i;j<n;j++){
            mpp[s[j]]++;
            if(mpp.size()>k){
                break;
            }
            else{
                maxLen=max(maxLen,j-i+1);
            }
        }
    }
    return maxLen;
    //T.C.-O(N^2)*log(256)
    //S.C.-O(3)
}

int LongestSubstringWithKDistinctCharactersApproach2(string s,int k){
    //BETTER SOLUTION
    int maxLen=0;
    map<char,int>mpp;
    int n=s.length();
    int l=0,r=0;
    while(r<n){
        mpp[s[r]]++;
        while(mpp.size()>k){
            mpp[s[l]]--;
            if(mpp[s[l]]==0){
                mpp.erase(s[l]);
            }
            l++;
        }
        
        if(mpp.size()<=k){
            maxLen=max(maxLen,r-l+1);
        }
        r++;
    }
    return maxLen;
    //T.C.-O(2N)*O(log256)
    //S.C.-O(3)
}

int LongestSubstringWithKDistinctCharactersApproach3(string s,int k){
    //BETTER SOLUTION
    int maxLen=0;
    map<char,int>mpp;
    int n=s.length();
    int l=0,r=0;
    while(r<n){
        mpp[s[r]]++;
        if(mpp.size()>k){
            mpp[s[l]]--;
            if(mpp[s[l]]==0){
                mpp.erase(s[l]); 
            }
            l++;
        }
        if(mpp.size()<=k){
            maxLen=max(maxLen,r-l+1);
        }
        r++;
    }
    return maxLen;
    //T.C.-O(N)*O(log256)
    //S.C.-O(3)
}

int main(){
    //LONGEST SUBSTRING WITH K DISTINCT CHARACTERS
    string s="aaabbccd";
    int k=2;
    cout<<LongestSubstringWithKDistinctCharactersApproach2(s,k);
    return 0;
}