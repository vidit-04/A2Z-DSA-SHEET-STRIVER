#include<bits/stdc++.h>
using namespace std;

long long GenerateAllBinaryStringsWithoutConsecutive1s(int n){
    int zeroend=1;
    int oneend=1;
    int sum=zeroend+oneend;
    if(n==1) return sum;
    int i=2;
    while(i<=n){
        oneend=zeroend;
        zeroend=sum;
        sum=zeroend+oneend;
        i++;
    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    cout<<GenerateAllBinaryStringsWithoutConsecutive1s(n);
    
    return 0;
}