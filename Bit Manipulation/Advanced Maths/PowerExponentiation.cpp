#include<bits/stdc++.h>
using namespace std;

int PowerExponentiation(int x,int n){
    //BRUTE FORCE
    int ans=1;
    for(int i=1;i<=n;i++){
        ans*=x;
    }
    return ans;
    //T.C.-O(n)
    //S.C.-O(1)
}

void PowerExponentiationApproach2(int &x,int &n,int &ans){
    //OPTIMAL
    if(n==0) return;

    if(n%2==1){
        ans*=x;
        n--;
    }
    x*=x;
    n/=2;
    PowerExponentiationApproach2(x,n,ans);
    
}

int PowerExponentiationApproach3(int x,int n){
    //OPTIMAL Solution
    bool flag=false;
    if(n<0) flag=true;
    int ans=1;
    while(n>0){
        if(n%2==1){
            ans*=x;
            n--;
        }
        x*=x;
        n/=2;
    }
    return flag? 1/ans:ans;
    //T.C.-O(log(n))
    //S.C.-O(1)
}

int main(){
    int x=2;
    int n=-10;
    int ans=1;
    // PowerExponentiationApproach3(x,n,ans);
    cout<<PowerExponentiationApproach3(x,n);
    return 0;
}