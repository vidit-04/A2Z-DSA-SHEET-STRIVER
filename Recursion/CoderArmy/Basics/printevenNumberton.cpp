#include<bits/stdc++.h>
using namespace std;

void printeventon(int n){
    if(n<2) return;
    printeventon(n-2);
    cout<<n<<endl;
}

int main(){
    int n=15;
    if(n%2!=0) n--;
    printeventon(n);
    return 0;
}