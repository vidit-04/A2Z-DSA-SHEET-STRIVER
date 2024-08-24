#include<bits/stdc++.h>
using namespace std;

string RemoveKDigits(string num,int k){
    stack<char>s;
    for(int i=0;i<num.size();i++){
        while(!s.empty() && k>0 && (s.top()-'0')>(num[i]-'0')){
            s.pop();
            k--;
        }
        s.push(num[i]);
    }
    while(k>0){
        s.pop();
        k--;
    }
    if(s.empty()) return "0";
    string ans="";

    while(!s.empty()){
        ans=ans+s.top();
        s.pop();
    }
    while(ans.size()!=0 && ans.back()=='0'){
        ans.pop_back();
    }
    reverse(ans.begin(),ans.end());
    if(ans.empty()) return "0";
    return ans;
    // T.C.-O(3N)+O(k)
    // S.C.-O(N)+O(N)
}

int main(){
    //REMOVE K DIGITS
    string num="1432219";
    int k=3;
    cout<<RemoveKDigits(num,k);
    return 0;
}