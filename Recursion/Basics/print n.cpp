#include<bits/stdc++.h>
using namespace std;

int cnt=0;
void printon(){
    if(cnt==3) return;
    cout<<cnt<<endl;
    cnt++;
    printon();
}

int main(){
    printon();
    return 0;
}