#include<bits/stdc++.h>
using namespace std;

bool subsequence(vector<int>a,int n,int k,int index){
    if(k==0) return 1;
    if (index==n || k<0) return 0;
    return subsequence(a,n,k,index+1) || subsequence(a,n,k-a[index],index+1);
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here
    return subsequence(a,n,k,0);
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    cout<<isSubsetPresent(n,k,a);
    return 0;
}