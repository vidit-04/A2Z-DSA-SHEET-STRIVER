#include<bits/stdc++.h>
using namespace std;

string PostToPrefix(string s){
    stack<string>st;
    for(int i=0;i<s.length();i++){
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            st.push(string(1,s[i]));
        }
        else{
            string str1=st.top();
            st.pop();
            string str2=st.top();
            st.pop();
            string str=s[i]+str2+str1;
            st.push(str);
        }
    }
    return st.top();
    //T.C.-O(N)
    //S.C.-O(N)
}

string PrefixToPostfix(string s){
    stack<string>st;
    for (int i=s.length()-1;i>=0;i--){
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            st.push(string(1,s[i]));
        }
        else{
            string str1=st.top();
            st.pop();
            string str2=st.top();
            st.pop();
            string str=str1+str2+s[i];
            st.push(str);
        }
    }
    return st.top();
    //T.C.-O(N)
    //S.C.-O(N)
}

int main(){
    //POSTFIX TO PREFIX
    string s="AB-DE+F*/";
    string ans=PostToPrefix(s);
    cout<<ans<<endl;
    cout<<PrefixToPostfix(ans)<<endl;
    return 0;
}