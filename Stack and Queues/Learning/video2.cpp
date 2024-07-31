#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char>st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
        else{
            if(st.empty()) return false;
            char ch=st.top();
            st.pop();
            if(((s[i]==')') && (ch=='(')) || ((s[i]==']') && (ch=='[')) || ((s[i]=='}') && (ch=='{'))) continue;
            return false;
        }
    }  
    return st.empty();
}

int main(){
    string s;
    cin>>s;
    cout<<isValid(s)<<endl;    
    return 0;
}