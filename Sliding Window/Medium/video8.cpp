#include<bits/stdc++.h>
using namespace std;

int LongestRepeatingCharacterReplacement(string s,int k){
    //BRUTE FORCE
    int maxLen=0;
    int maxF=0;
    int n=s.length();
    for(int i=0;i<n;i++){
        vector<int>hash(26);
        for(int j=i;j<n;j++){
            hash[s[j]-'A']++;
            maxF=max(maxF,hash[s[j]-'A']);
//Here number of different characters are mapped as the number of different characters will be the (number of characters mapped-max frequency element of substring)
            int changes=j-i+1-maxF;
            if(changes<=k){
                maxLen=max(maxLen,j-i+1);
            }
            else{
                break;
            }
        }
    }
    return maxLen;
    //T.C.-O(N^2)
    //S.C.-O(26)
}

int LongestRepeatingCharacterReplacementApproach2(string s,int k){
    //BETTER APPORACH
    int maxLen=0;
    int maxF=0;
    int n=s.length();
    int l=0,r=0;
    vector<int>hash(26,0);
    while(r<n){
        hash[s[r]-'A']++;
        maxF=max(maxF,hash[s[r]-'A']);
        int changes=r-l+1-maxF;
        while(changes>k){
            hash[s[l]-'A']--;
            l++;
            for(int i=0;i<26;i++){
                maxF=max(maxF,hash[i]);
            }
            // maxF=max(maxF,hash[s[l]-'A']);
            changes=r-l+1-maxF;
        }
        if(changes<=k){
            maxLen=max(maxLen,r-l+1);
        }
        r++;
    }
    return maxLen;
    //T.C.-O(2N)*O(26)
    //S.C.-O(26)
}

int LongestRepeatingCharacterReplacementApproach3(string s,int k){
    //OPTIMAL APPORACH
    int maxLen=0;
    int maxF=0;
    int n=s.length();
    int l=0,r=0;
    vector<int>hash(26,0);
    while(r<n){
        hash[s[r]-'A']++;
        maxF=max(maxF,hash[s[r]-'A']);
        int changes=r-l+1-maxF;
        if(changes>k){
            hash[s[l]-'A']--;
            l++;
        }
        if(changes<=k){
            maxLen=max(maxLen,r-l+1);
        }
        r++;
    }
    return maxLen;
    //T.C.-O(2N)*O(26)
    //S.C.-O(26)
}

int main(){
    // Longest Repeating Character Replacement
    string s="AAABBCCD";
    int k=2;
    cout<<LongestRepeatingCharacterReplacementApproach2(s,k);
    return 0;
}