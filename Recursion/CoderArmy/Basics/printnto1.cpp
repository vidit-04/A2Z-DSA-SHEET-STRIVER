#include<bits/stdc++.h>
using namespace std;

void printnto1(int n){
    if(n<1) return;
    cout<<n<<endl;
    printnto1(n-1);
}

int main(){
    printnto1(11);
    return 0;
}