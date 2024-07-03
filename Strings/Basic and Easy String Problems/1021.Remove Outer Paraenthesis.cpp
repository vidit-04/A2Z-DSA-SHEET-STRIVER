#include<bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s) {
    int cnt=0;
    string res="";
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            cnt++;
            if(cnt>1) res+="(";
        }
        else{
            if(cnt>1) res+=")";
            cnt--;
        }
    }
    return res;
}

int main(){
    
    return 0;
}