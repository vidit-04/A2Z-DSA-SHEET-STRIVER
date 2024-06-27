#include<bits/stdc++.h>
using namespace std;

    string trim(string s){
        int i=0;
        int j=s.length()-1;
        while(s[i]==' '&& i<j) i++;
        while(s[j]==' '&& i<j) j--;
        return s.substr(i,j-i+1);
    }
    string reverseWord(string str){
        int x=0;
        int y=0;
        string s=str;
        for(int i=0;i<=s.length();i++){
            if(s[i]==' ' || i==s.length()){
                y=i;
                reverse(s.begin()+x,s.begin()+y);
                x=i+1;
            }
        }
        return s;
    }

    string reverseWords(string s) {
        s=trim(s);
        s=reverseWord(s);
        reverse(s.begin(),s.end());
        return s;
    }

int main(){
    string s="    the sky is blue    ";
    cout<<reverseWords(s);
    return 0;
}