#include<bits/stdc++.h>
using namespace std;

void PrimeFactorizationusingSieve(int n){
    vector<int>spf(100000);
    for(int i=0;i<100000;i++){
        spf[i]=i;
    }
    for(int i=2;i*i<=100000;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=100000;j+=i){
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
    // for(int i=0;i<queries.size();i++){
        // int n=queries[i];
        while(n!=1){
            cout<<spf[n]<<" ";
            n/=spf[n];
        }
        // cout<<endl;
    // }
    //T.C.-O(n*log(log(n)))+O(Q*logn)
    //S.C.-O(n)
}

int main(){
    int n=12246;
    PrimeFactorizationusingSieve(n);
    return 0;
}