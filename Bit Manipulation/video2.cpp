#include<bits/stdc++.h>
using namespace std;

void swap(int &a,int &b){
    a=a+b;
    b=a-b;
    a=a-b;
}

void swapApproach2(int &a,int &b){
    a=a^b;
    b=a^b;
    a=a^b;
}



bool checkIfIthBitIsSet(int n,int i){
    //BRute force: Convert to binary then check if ith bit is set from right
}
bool checkIfIthBitIsSetApproach2(int n,int i){
    //OPTIMAL SOLUTION: Convert to binary then check if ith bit is set from right
    //USING LEFT SHIFT OPERATOR
    // return (n & (1<<i))!=0;

    //USING RIGHT SHIFT OPERATOR
    return ((n>>i)&1)==1;
}

int setIthBit(int n,int i){
    //USING LEFT SHIFT OPERATOR

    return (n | 1<<i);

}

int main(){
    // int a=3;
    // int b=2;
    // swapApproach2(a,b);
    // cout<<a<<" "<<b;

    int n;
    cin>>n;
    int i;
    cin>>i;
    cout<<checkIfIthBitIsSetApproach2(n,i)<<endl;
    cout<<setIthBit(n,i)<<endl;
    return 0;
}