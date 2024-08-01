#include <bits/stdc++.h>
using namespace std;

int priority(char ch) {
    if (ch == '^') return 3;
    else if (ch == '*' || ch == '/') return 2;
    else if (ch == '+' || ch == '-') return 1;
    else return -1; // For unrecognized characters
}

void reversefunc(string &s) {
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }
}

string InfixToPrefix(string s) {
    reversefunc(s);
    string ans = "";
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            ans += s[i];
        }
        else if (s[i] == '(') {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // Pop the '('
        }
        else{
            // For the '^' operator, which is right-associative
            if(s[i]=='^'){
                while(!st.empty() && priority(s[i])<priority(st.top())){
                    ans = ans+st.top();
                    st.pop();
                }
            }
            // For all other operators, which are left-associative
            else{
                while(!st.empty() && priority(s[i])<=priority(st.top())){
                    ans = ans+st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
    }
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
    // T.C.-O(3N)
    // S.C.-O(N)
}

string PrefixToInfix(string s){
    stack<string> st;
    for (int i=s.length()-1;i>=0;i--){
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            st.push(string(1,s[i]));
        }
        else{
            string str1=st.top();
            st.pop();
            string str2=st.top();
            st.pop();
            string str='('+str1+s[i]+str2+')';
            st.push(str);
        }
    }
    return st.top();
    // T.C.-O(N)
    // S.C.-O(N)
}

int main() {
    string str = "a+b*(c^d-e)^(f+g*h)-i";
    string ans = InfixToPrefix(str);
    cout << ans << endl;
    cout << PrefixToInfix(ans) << endl;

    return 0;
}
