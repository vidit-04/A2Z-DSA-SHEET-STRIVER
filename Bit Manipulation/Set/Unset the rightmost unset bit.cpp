#include<bits/stdc++.h>
using namespace std;

int SetUnsettherightmostunsetbit(int n){
    return n|(n+1);
}

int main(){
    int n=3;
    cout<<SetUnsettherightmostunsetbit(n);
    return 0;
}