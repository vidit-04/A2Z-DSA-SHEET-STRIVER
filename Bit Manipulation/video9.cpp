#include<bits/stdc++.h>
using namespace std;

int DivideIntegerWithoutDividingAndMultiplying(int n,int m){
    //BRUTE FORCE
    int sum=0;
    int cnt=0;
    while(sum<=n){
        sum+=m;
        cnt++;
    }
    return cnt-1;
    //T.C.-O(n/m)
    //S.C.-O(1)
}

int DivideIntegerWithoutDividingAndMultiplyingApproach2(int dividend,int divisor){
    //OPTIMAL
    if(dividend==divisor) return 1;
    if(dividend==0) return 0;
    if(divisor==1) return dividend;
    if (dividend == INT_MIN && divisor == -1) return INT_MAX; 
    
    bool sign=true;
    if(dividend<=0 && divisor>0) sign=false;
    else if(dividend>=0 && divisor<0) sign=false;
    long n=abs(dividend);
    long d=abs(divisor);
    long quotient=0;

    while(n>=d){
        int count=0;
        while(n>=(d<<(count+1))) count++;
        quotient+=(1<<count);
        n-=(d<<count);
    }

    if(quotient>INT_MAX && sign==true) return INT_MAX;
    if(quotient>INT_MAX && sign==false) return INT_MIN;
    return sign?quotient:(-1*quotient);
    //T.C.-O(logn)
    //S.C.-O(1)
}

int main(){
    int n=-2147483648;
    int m=-1;
    cout<<DivideIntegerWithoutDividingAndMultiplyingApproach2(n,m);
    return 0;
}