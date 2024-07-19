#include<bits/stdc++.h>
using namespace std;

void revString(string &s,int start,int end){
    if(start>=end) return;
    char c=s[start];
    s[start]=s[end];
    s[end]=c;
    revString(s,start+1,end-1);
}

int main(){
    string s="vidit";
    revString(s,0,s.length()-1);
    cout<<s;
    return 0;
}