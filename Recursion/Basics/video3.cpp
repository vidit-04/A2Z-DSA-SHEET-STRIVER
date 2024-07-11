#include<bits/stdc++.h>
using namespace std;

void sumofn(int n,int sum){
    if(n<1){
        cout<<sum;
        return;
    }
    sumofn(n-1,sum+n);
}

int sumofnbackTrack(int n,int sum){
    if(n<1) return sum;
    sum=sumofnbackTrack(n-1,sum);
    sum+=n;
    return sum;
}

void factorial(int n, int pro){
    if(n<1){
        cout<<pro;
        return;
    }
    pro*=n;
    factorial(n-1,pro);
}

int factorialofn(int n){
    if(n==0) return 1;
    return n*factorialofn(n-1);
}

int main(){
    int n;
    cin>>n;
    // sumofn(n,0);
    // cout<<factorialofn(n);
    // factorial(n,1);
    return 0;
}