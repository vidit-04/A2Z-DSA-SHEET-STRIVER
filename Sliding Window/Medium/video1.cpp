#include<bits/stdc++.h>
using namespace std;

int SlidingWindowMaxSum(vector<int> a,int k){
    //CONSTANT SIZE WINDOW
    int l=0;
    int r=k-1;
    int n=a.size();
    int sum=0;
    int maxSum=0;
    for(int i=0;i<k;i++){
        sum+=a[i];
    }
    maxSum=max(maxSum,sum);
    while(r<n-1){
        sum-=a[l];
        l++;
        r++;
        sum+=a[r];
        maxSum=max(maxSum,sum);
    }
    return maxSum;
    //T.C.-O(N)
    //S.C.-O(1) 
}

int LongestSubarrayWithSumLessThanK(vector<int> a,int k){
    //LONGEST SUBARRAY TYPE OF ARRAY
    //BRUTE FORCE
    int n=a.size();
    int maxLength=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=a[j];
            if(sum<=k){
                int len=j-i+1;
                maxLength=max(maxLength,len);
            }
        }
    }
    return maxLength;
    //T.C.-O(N^2)
    //S.C.-O(1)
}

int LongestSubarrayWithSumLessThanKApproach2(vector<int> a,int k){
    //LONGEST SUBARRAY TYPE OF ARRAY
    //BETTER APPROACH- SLIDING WINDOW
    int n=a.size();
    int maxLength=0;
    int sum=0;
    int l=0,r=0;
    while(r<n){
        sum+=a[r];
        while(sum>k){
            sum-=a[l];
            l++;
        }
        if(sum<=k){
            maxLength=max(maxLength,r-l+1);
        }
        r++;
    }
    return maxLength;
    //T.C.-O(2N)
    //S.C.-O(1)
}

int LongestSubarrayWithSumLessThanKApproach3(vector<int> a,int k){
    //LONGEST SUBARRAY TYPE OF ARRAY
    //OPTIMAL APPROACH- SLIDING WINDOW
    int n=a.size();
    int maxLength=0;
    int sum=0;
    int l=0,r=0;
    while(r<n){
        sum+=a[r];
        if(sum>k){
            sum-=a[l];
            l++;
        }
        if(sum<=k){
            maxLength=max(maxLength,r-l+1);
        }
        r++;
    }
    return maxLength;
    //T.C.-O(2N)
    //S.C.-O(1)
}


int main(){
    //CONSTANT SIZE WINDOW
    // vector<int> a={-1,2,3,3,4,5,-1};
    // int k=3;
    // cout<<SlidingWindowMaxSum(a,k);

    //LONGEST SUBARRAY TYPE OF ARRAY
    vector<int> a={2,5,1,7,10};
    int k=14;
    cout<<LongestSubarrayWithSumLessThanKApproach3(a,k);
    return 0;
}