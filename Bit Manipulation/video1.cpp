#include<bits/stdc++.h>
using namespace std;

string ConvertDecimalToBinary(int n){
    if(n==0) return "0";
    string res="";
    while(n!=1){
        if(n%2==1) res+='1';
        else res+='0';
        n/=2;
    }
    res+='1';
    reverse(res.begin(),res.end());
    return res;
}

int ConvertBinary2Decimal(string s){
    int n=s.length();
    int power_of_2=1;
    int num=0;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='1') num+=power_of_2;
        power_of_2*=2;
    }
    return num;
}

int main(){
    cout<<ConvertDecimalToBinary(ConvertBinary2Decimal("11011011"));
    return 0;
}