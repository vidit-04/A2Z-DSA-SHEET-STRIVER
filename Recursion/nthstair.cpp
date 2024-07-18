#include<bits/stdc++.h>
using namespace std;

int NthStair(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return NthStair(n-1)+NthStair(n-2);
}

int main(){
    int n=4;
    cout<<NthStair(n);
    return 0;
}