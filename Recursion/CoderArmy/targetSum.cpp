#include<bits/stdc++.h>
using namespace std;

bool subsequence(vector<int>a,int n, int target,int index){
    if(index==n && target==0){
        return 1;
    }
    if(index==n || target<0){
        return 0;
    }
    //Not Included
    return subsequence(a,n,target,index+1) || subsequence(a,n,target-a[index],index+1);
}

int main(){
    vector<int>a={3,6,4,5};
    int target=1;
    cout<<subsequence(a,a.size(),target,0);
    return 0;
}