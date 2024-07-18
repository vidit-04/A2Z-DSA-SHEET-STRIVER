#include<bits/stdc++.h>
using namespace std;

void print1ton(int n){
    if(n<1) return;
    print1ton(n-1);
    cout<<n<<endl;
}

int main(){
    int n=10;
    print1ton(n);
    return 0;
}