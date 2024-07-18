#include<bits/stdc++.h>
using namespace std;

int SumOfSquaresTillN(int n){
    if(n==0) return 0;
    return n*n+SumOfSquaresTillN(n-1);
}

int main(){
    int n=5;
    cout<<SumOfSquaresTillN(n);
    return 0;
}