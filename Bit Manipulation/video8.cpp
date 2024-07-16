#include<bits/stdc++.h>
using namespace std;

int XorInGivenRange(int n){
    //BRUTE FORCE
    int xorr=0;
    for(int i=1;i<=n;i++){
        xorr^=i;
    }
    return xorr;
    //T.C.-O(n)
    //S.C.-O(1)
}

int XorInGivenRangeApproach2(int n){
    //OPTIMAL: JUST A GAME OF OBSERVATION NEED TO KNOW BEFORE INTERVIEW CAN"T DEFINE IT THERE
    if(n%4==0) return n;
    if(n%4==1) return 1;
    if(n%4==2) return n+1;
    return 0;
    //T.C.-O(1)
    //S.C.-O(1)
}

int XorBetweenLandR(int l,int r){
    //BRUTE FORCE
    int xorr=0;
    for(int i=l;i<=r;i++){
        xorr^=i;
    }
    return xorr;
    //T.C.-O(r-l+1)
    //S.C.-O(1)
}

int XorBetweenLandRApproach2(int l,int r){
    //OPTIMAL
   return XorInGivenRangeApproach2(l-1)^XorInGivenRangeApproach2(r);
   //Ex- ans=(3^4^5^6^7). xorof l-1 ^ xorof r= (1^2) ^ (1^2^3^4^5^6^7)===>1^2 will be czncelled automatically
    //T.C.-O(n)
    //S.C.-O(1)
}


int main(){
    // int n=87;
    // cout<<XorInGivenRange(n);

    //If the question is to find the xor in between l and 4 then what is xor?
    int l=3;
    int r=7;
    cout<<XorBetweenLandRApproach2(l,r);
    return 0;
}