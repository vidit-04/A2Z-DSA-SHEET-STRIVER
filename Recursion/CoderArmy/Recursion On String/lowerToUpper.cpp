#include<bits/stdc++.h>
using namespace std;

void lowerToUpper(string &s,int n){
    if(n==-1) return;
    s[n]=s[n]-'a'+'A';
    lowerToUpper(s,n-1);
}

int main(){
    string s="vidit";
    lowerToUpper(s,4);
    cout<<s;
    return 0;
}