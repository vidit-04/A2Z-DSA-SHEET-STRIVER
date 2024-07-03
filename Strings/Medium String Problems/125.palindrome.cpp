#include<bits/stdc++.h>
using namespace std;

string toLowercase(string str){
    string s="";
    for (char& c : str) {
        c = tolower(c);
        s+=c;
    }
    return s;
}
bool isPalindrome(string str) {
    string s=toLowercase(str);
    // cout<<s;
    int i=0;
    int j=s.length()-1;
    while(i<j){
        while(!isalpha(s[i]) && i<j) i++;
        while(!isalpha(s[j]) && i<j) j--;
        // cout<<s[j]<<" h"<<endl;
        // if( && ){
            cout<<s[i]<<"-"<<s[j];
            cout<<endl;
            if(s[i]!=s[j]) return false;
        // }
        i++; j--;
    }
    return true;
}

int main(){
    string str="A man, a plan, a canal: Panama";
    cout<<isPalindrome(str);

    return 0;
}