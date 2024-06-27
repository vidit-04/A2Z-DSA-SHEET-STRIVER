#include<bits/stdc++.h>
using namespace std;

    string trim(string s){
        int i=0;
        int j=s.length()-1;
        while(s[i]==' '&& i<j) i++;
        while(s[j]==' '&& i<j) j--;
        return s.substr(i,j-i+1);
    }
    // string reverseWordOfString(string str){
    //     int x=0;
    //     int y=0;
    //     string s=str;
    //     for(int i=0;i<=s.length();i++){
    //         if(s[i]==' ' || i==s.length()){
    //             y=i;
    //             reverse(s.begin()+x,s.begin()+y);
    //             x=i+1;
    //         }
    //     }
    //     return s;
    // }

    vector<string> split(string s){
        stringstream st(s); // Used to create input stream so that you can input string
        vector<string>str;
        string token;
        char delimeter=' ';
        // while(getline(st,token,delimeter)){
        while(st>>token){
            if(!token.empty()) str.push_back(token);
        }
        return str;
    }
    string join(vector<string>s){
        string str="";
        for(int i=0;i<s.size();i++){
            str+=s[i];
            if(i!=s.size()-1) str+=" ";
        }
        return str;
    }

    string reverseWords(string s) {
        vector<string>str=split(s);
        reverse(str.begin(),str.end());
        s=join(str);
        return s;
    }

int main(){
    string s="the sky       is blue";
    cout<<reverseWords(s);
    return 0;
}