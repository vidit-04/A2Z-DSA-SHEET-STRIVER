#include<bits/stdc++.h>
using namespace std;

int LongestSubstringWithoutRepetition(string s){
    //BRUTE FORCE
    int n=s.length();
    int maxLength=0;
    for(int i=0;i<n;i++){
        vector<int>hash(255,0);
        for(int j=i;j<n;j++){
            if(hash[s[j]]==1) break;
            int len=j-i+1;
            maxLength=max(maxLength,len);
            hash[s[j]]++;
        }
    }
    return maxLength;
    //T.C.-O(N^2)
    //S.C.-O(1)
}
int LongestSubstringWithoutRepetitionApproach2(string s){
    //OPTIMISED- SLIDING WINDOW AND TWO POINTER
    int n=s.length();
    int maxLength=0;
    vector<int>hash(255,-1);
    int l=0,r=0;
    int len=0;
    while(r<n){
        if(hash[s[r]]!=-1){
            if(hash[s[r]]>l){
                l=hash[s[r]]+1;
            }
        }
        len=r-l+1;
        maxLength=max(maxLength,len);
        hash[s[r]]=r;
        r++;
    }
    return maxLength;
    //T.C.-O(N)
    //S.C.-O(256)
}

int main(){
    //LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS
    string s="cadbzabcd";
    cout<<LongestSubstringWithoutRepetitionApproach2(s);
    return 0;
}