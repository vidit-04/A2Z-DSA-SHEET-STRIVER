#include<bits/stdc++.h>
using namespace std;

int subsequence(vector<int>a,int n,int target,int index){
    if(index==n || target<0) return 0;
    if(target==0) return 1;
    return subsequence(a,n,target,index+1)+subsequence(a,n,target-a[index],index);
}

int main(){
    vector<int>a={2,3,4};
    int target=6;
    int n=a.size();
    cout<<subsequence(a,n,target,0);
    return 0;
}