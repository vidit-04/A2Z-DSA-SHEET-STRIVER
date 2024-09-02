#include<bits/stdc++.h>
using namespace std;

int MaxConsecutiveOnes(vector<int>a,int k){
    //BRUTE FORCE
    int n=a.size();
    int maxLength=0;
    int len=0;
    for(int i=0;i<n;i++){
        int zeroes=0;
        for(int j=i;j<n;j++){
            if(a[j]==0) zeroes++;
            if(zeroes<=k){
                len=j-i+1;
                maxLength=max(maxLength,len);  
            }
            else{
                break;
            }
        }
    }
    return maxLength;
    //T.C.-O(N^2)
    //S.C.-O(1)
}

int MaxConsecutiveOnesApproach2(vector<int>a,int k){
    //BETTER APPROACH
    int n=a.size();
    int maxLength=0;
    int len=0;
    int zeroes=0;
    int l=0,r=0;
    while(r<n){
        if(a[r]==0) zeroes++;
        while(zeroes>k){
            if(a[l]==0) zeroes--;
            l++;
        }
        if(zeroes<=k){
            len=r-l+1;
            maxLength=max(maxLength,len);
            r++;
        }
    }
    return maxLength;
    //T.C.-O(2N)
    //S.C.-O(1)
}

int MaxConsecutiveOnesApproach3(vector<int>a,int k){
    //OPTIMAL APPROACH
    int n=a.size();
    int maxLength=0;
    int len=0;
    int zeroes=0;
    int l=0,r=0;
    while(r<n){
        if(a[r]==0) zeroes++;
        if(zeroes>k){
            if(a[l]==0) zeroes--;
            l++;
        }
        if(zeroes<=k){
            len=r-l+1;
            maxLength=max(maxLength,len);
        }
        r++;
    }
    return maxLength;
    //T.C.-O(2N)
    //S.C.-O(1)
}

int main(){
    //MAX CONSECUTIVE ONES III
    vector<int>nums={1,1,1,0,0,0,1,1,1,1,0};
    int k=2;
    cout<<MaxConsecutiveOnesApproach3(nums,k);
    return 0;
}