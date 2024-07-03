#include<bits/stdc++.h>
using namespace std;

int myAtoi(string str) {
    long result=0;
    int n=str.length();
    bool neg=false;
    int i=0;
    while(str[i]==' ' && i<n) i++;
    if(i>=n) return 0;
    if(str[i]=='-' || str[i]=='+'){
        if (str[i] == '-') neg = true;
        i++;
    }
    while(i<n){
        int digit=str[i]-'0';
        if(digit>=0 && digit<=9){
            result=result*10+digit;
            if(result>INT_MAX) return neg?INT_MIN:INT_MAX;
        }
        else break;
        i++;
    }
    if(neg) return -1*result;
    return result;
}

int main(){
    string s="-91283472332";
    cout<<myAtoi(s);
    return 0;
}