#include<bits/stdc++.h>
using namespace std;

bool checkPalindorme(string s,int start,int end){
    if(start>=end) return 1;
    if(s[start]!=s[end]) return 0;
    return checkPalindorme(s,start+1,end-1);
}

int main(){
    string s="namon";
    cout<<checkPalindorme(s,0,s.size()-1);
    return 0;
}