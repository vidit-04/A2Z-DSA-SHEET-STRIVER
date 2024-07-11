#include<bits/stdc++.h>
using namespace std;

void print(int i,int n){
    if(i>=n) return;
    cout<<"Striver"<<endl;
    print(i+1,n);
}

void printLinearly1ton(int n, int i){
    if(i>n) return;
    cout<<i<<endl;
    printLinearly1ton(n,i+1);
}

void printnto1(int n){
    if(n<1) return;
    cout<<n<<endl;
    printnto1(n-1);
}

void print1ton(int n,int i){
    if(i<1) return;
    print1ton(n,i-1);
    // print1ton(n-1);
    cout<<i<<endl;
}

void printnto1BackTrack(int n){

}

int main(){
    int n;
    cin>>n;
    // print(0,n);
    // printLinearly1ton(n,1);
    // printnto1(n);
    // print1ton(n,n);
    // printnto1BackTrack(n);
    return 0;
}