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

void NumberOfPrimesTillN(int n){
    //BRUTE FORCE
    for(int i=2;i<=n;i++){
        if(isPrime(i)) cout<<i<<" ";
    }
}
void NumberOfPrimesTillNApproach2(int n){
    //OPTIMIZED
    vector<bool> prime(n+1,1);
    prime[0]=prime[1]=0;
    for(int i=2;i<prime.size();i++){
        if(prime[i]){
            for(int j=2*i;j<=prime.size();j+=i){
                prime[j*i]=0;
            }
        }
    }
    for(int i=2;i<prime.size();i++){
        if(prime[i]) cout<<i<<" ";
    }
    //T.C.-O(n*(n/2))
    //S.C.-O(n)
}

void NumberOfPrimesTillNApproach3(int n){
    //MORE OPTIMIZED -- SIEVE ERATOSTHENES ALGORITHM
    vector<bool> prime(n+1,1);
    for(int i=2;i*i<=n;i++){
        if(prime[i]){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=0;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i]) cout<<i<<" ";
    }
    //T.C.-O(n*log(log(n)))
    //S.C.-O(n)
}

int main(){
    int n=30;
    NumberOfPrimesTillNApproach3(n);
    return 0;
}