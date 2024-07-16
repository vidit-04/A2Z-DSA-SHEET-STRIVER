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

int DivideIntegerWithoutDividingAndMultiplyingApproach2(int n,int d){
    //OPTIMAL
    if(n==d) return 1;
    if(d==1) return n;
    bool sign=true; //+ve

    if(n<=0 && d>0) sign=false; // -ve
    if(n>=0 && d<0) sign=false; //-ve

    n=abs(n);
    d=abs(d);
    long ans=0;
    while(n>=d){
        int count=0;
        while(n>=(d<<(count+1))) count++;
        ans+=(1<<count);
        n=n-(d<<count);
    }

    if(ans>INT_MAX && sign==true) return INT_MAX;
    if(ans>INT_MAX && sign==false) return INT_MIN;

    return sign?ans:(-1*ans);
    //T.C.-O(logn)
    //S.C.-O(1)
}

int main(){
    int n=22;
    int m=3;
    cout<<DivideIntegerWithoutDividingAndMultiplyingApproach2(n,m);
    return 0;
}