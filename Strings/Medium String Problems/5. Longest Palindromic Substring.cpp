#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    int n=s.length();
    if(n<=1) return s;
    string res;
    for(int i=0;i<n;i++){
        int low=i;
        int high=i;

        while (low >= 0 && high < n && s[low] == s[high]) {
            low--;
            high++;
        }

        string palindrome=s.substr(low+1,high-low-1);

        if(palindrome.length()>res.length()) res=palindrome;

        low=i-1;
        high=i;

        while (low >= 0 && high < n && s[low] == s[high]) {
            low--;
            high++;
        }
        
        palindrome=s.substr(low+1,high-low-1);
        if(palindrome.length()>res.length()) res=palindrome;
    }
    return res;
}

int main(){
    
    return 0;
}