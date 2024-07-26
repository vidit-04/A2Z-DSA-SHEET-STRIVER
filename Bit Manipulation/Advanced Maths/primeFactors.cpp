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
 

list<int> PrimeFactors(int n){
    //BRUTE FORCE
    list<int> primefactors;
    for(int i=2;i<=n;i++){
        if(n%i==0){
            if(isPrime(i)) primefactors.push_back(i);
        }
    }
    return primefactors;
    //T.C.-O(n*(n**1/2))
    //S.C.-O(1)
}

list<int> PrimeFactorsApproach2(int n){
    //BETTER Approach
    list<int> primefactors;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            if(isPrime(i)) primefactors.push_back(i);
            if(((n/i)!=i)&&(isPrime(n/i))) primefactors.push_back(n/i);
        }
    }
    return primefactors;
    //T.C.-O(n**1/2)
    //S.C.-O(1)
}

list<int> PrimeFactorsApproach3(int n){
    //Better Approach
    list<int> primefactors;
    for(int i=2;i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                n=n/i;
            }
            primefactors.push_back(i);
        }
    }
    return primefactors;
    //T.C.-O(n**1/2)
    //S.C.-O(1)
}

list<int> PrimeFactorsApproach4(int n){
    //Optimal Approach
    list<int> primefactors;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                n=n/i;
            }
            primefactors.push_back(i);
        }
    }
    if(n!=1) primefactors.push_back(n);
    return primefactors;
    //T.C.-O((n**1/2)*logn)
    //S.C.-O(1)
}

int main(){
    int n=780;
    list<int> primefactors=PrimeFactorsApproach4(n);
    for(auto i:primefactors){
        cout<<i<<" ";
    }
    return 0;
}