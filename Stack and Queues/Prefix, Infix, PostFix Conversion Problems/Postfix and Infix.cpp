#include<bits/stdc++.h>
using namespace std;

int priority(char ch){
    if(ch=='^') return 3;
    else if(ch=='*' || ch=='/') return 2;
    else if(ch=='+' || ch=='-') return 1;
    else return -1;
}

string InfixToPostfix(string s){
    stack<char> st;
    string ans = "";
    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
            ans = ans+s[i];
        }
        else if(s[i]=='(') st.push(s[i]);
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans = ans+st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();
        }
        else{
            while(!st.empty() && priority(s[i])<=priority(st.top())){
                ans = ans+st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        ans = ans+st.top();
        st.pop();
    } 
    return ans;
    //T.C.-O(N)+O(N)
    //S.C.-O(N)+O(N)
}

string PostFixToInfix(string s){
    stack<string>st;
    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
            st.push(string(1,s[i]));
        }
        else{
            string str1=st.top();
            st.pop();
            string str2=st.top();
            st.pop();
            string str='('+str2+s[i]+str1+')';
            st.push(str);
        }
    }
    return st.top();
    //T.C.-O(N)
    //S.C.-O(N)
}

int main(){
    string s="a+b*(c^d-e)";
    string ans=InfixToPostfix(s);
    cout<<ans<<endl;
    cout<<PostFixToInfix(ans)<<endl;
    return 0;
}