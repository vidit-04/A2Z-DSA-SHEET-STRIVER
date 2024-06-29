#include<bits/stdc++.h>
using namespace std;

bool checkAnagram(string s, string t){
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    return s==t;
}

int main(){
    string s="anagram";
    string t="nagaram";
    cout<<checkAnagram(s,t);
    return 0;
}
