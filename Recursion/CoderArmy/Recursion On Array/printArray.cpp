#include<bits/stdc++.h>
using namespace std;

void printArr(vector<int>a,int n,int index){
    if(index==n) return;
    cout<<a[index]<<" ";
    printArr(a,n,index+1);
}

void printArrReverse(vector<int>a,int n,int index){
    if(index==n) return;
    printArr(a,n,index+1);
    cout<<a[index]<<" ";
}

int main(){
    vector<int>a={1,2,3,4,5};
    printArr(a,a.size(),0);
    cout<<endl;
    printArrReverse(a,a.size(),0);
    return 0;
}