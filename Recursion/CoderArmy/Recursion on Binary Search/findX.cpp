#include<bits/stdc++.h>
using namespace std;

bool findX(vector<int>a,int target,int start, int end){
    if(start>end) return 0;
    int mid=(start+end)/2;
    if(a[mid]==target) return 1;
    if(a[mid]>target) return findX(a,target,start,mid-1);
    return findX(a,target,mid+1,end);
}

int main(){
    vector<int>a={2,3,6,7,8,9};
    cout<<findX(a,7,0,a.size()-1);
    return 0;
}