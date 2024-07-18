#include<bits/stdc++.h>
using namespace std;

int minInArr(vector<int>a,int n,int index){
    if(index==n-1) return a[index];
    return min(a[index],minInArr(a,n,index+1));
}

int main(){
    vector<int>a={6,3,6,2,6,3,1};
    cout<<minInArr(a,a.size(),0);
    return 0;
}