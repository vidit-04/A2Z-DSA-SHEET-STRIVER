#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    int cnt=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cnt++;
            if(n/i!=i) cnt++;
        }
        if(cnt>2) break;
    }
    if(cnt==2) return true;
    return false;
    //T.C.-O(n**1/2)
    //S.C.-O(1)
}

int main(){
    int n=100;
    cout<<isPrime(n);
    return 0;
}