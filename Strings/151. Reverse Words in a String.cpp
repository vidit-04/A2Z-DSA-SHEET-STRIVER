#include<bits/stdc++.h>
using namespace std;

string trim(string s){
        int i=0;
        int j=s.length()-1;
        while(s[i]==' '&& i<j) i++;
        while(s[j]==' '&& i<j) j--;
        return s.substr(i,j+1);
    }
    string reverseWords(string s) {
        string str=trim(s);
        cout<<str;
    }

int main(){
    string s="the sky is blue";
    reverseWords(s);
    return 0;
}