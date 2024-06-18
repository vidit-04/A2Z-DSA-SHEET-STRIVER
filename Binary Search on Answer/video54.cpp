#include<bits/stdc++.h>
using namespace std;

int findSqrt(int x){
    //BRUTE FORCE
    if(x==0 || x==1) return x;
    for(int i=1;i<=x/2;i++){
        if(i*i==x) return i;
        if(i*i>x) return i-1;
    }
}

int findSqrtApproach2(int x){
    //OPTIMIZED

    //We have used extra variable below -  ans
    // if(x==0 || x==1) return x;
    // int low=1, high=x, ans;
    // while(low<=high){
    //     int mid=low+(high-low)/2;
    //     if(mid==x/mid) return mid;
    //     if(mid<x/mid){
    //         low=mid+1;
    //         ans=mid;
    //     }else{
    //         high=mid-1;
    //     }
    // }
    // return ans;

    //We have not used extra variable below - ans
    int low=1;
    int high=x;
    while(low<=high){
        long long mid=low+(high-low)/2;
        if(mid*mid<=x){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return high;  // Here high is replaced by ans bcs if you carefully notice then when this loop terminates then high=5 while low=6. You can use above method as well.
    //T.C.-O(logn)
    //S.C.-O(1)
}

int main(){
    int x=28;
    cout<<findSqrtApproach2(x)<<endl;
    return 0;
}