#include<bits/stdc++.h>
using namespace std;

int findLongestSubarrayWithSumK(vector<int>a,int k){
    //LONGEST SUBARRAY WITH SUM K - BRUTE FORCE
    //GENERATE ALL SUBARRRAY AND FIND THE ONE WITH SUM AND LONGEST SIZE
    int len=0;
    for (int i = 0; i < a.size(); i++)
    {
        int sum=0;
        for(int j=i;j<a.size();j++){
            sum+=a[j];
            // for (int k = i; k < j; k++){
            //     sum+=a[k];
            // }
            if(sum==k) len=max(len,j-i+1);
        }
    }
    return len;
    //T.C.= O(n^2)
    //S.C.= O(1)
}

int findLongestSubarrayWithSumKApproach2(vector<int>a,int k){
    //LONGEST SUBARRAY WITH SUM K - Approach 2 - Better Approach
    //HASHING
    map<int,int>mp;
    int sum=0;
    int len=0;
    //FO
    for(int i=0;i<a.size();i++){
        sum+=a[i];
        if(sum==k){
            len=i+1;
        }
        //If you don't want to have above if statement then do the following.
        // mp[0]=-1;  //Before loop statement

        if(mp.find(sum)==mp.end()){     
            //We write this if condition only for cases where we have 0 and -ve in array bcs if we don't write if we won't be getting longest array
            mp[sum]=i;
        }
        if(mp.find(sum-k)!=mp.end()){
            len=max(len,i-mp[sum-k]);
        }
    }
    return len;
    //T.C.= O(n)
    //S.C.= O(n)
}

int findLongestSubarrayWithSumKApproach3(vector<int>a,int k){
    //LONGEST SUBARRAY WITH SUM K - Approach 3 - Best Approach
    //TWO POINTER APPROACH
    //ONLY FOR ARRAY WITH POSITIVE NUMBERS. BECAUSE IN NEGATIVE WHEN THE SUM>K THEN IT WILL DO i++. BUT THE SUM MAY THEN ALSO INCREASE. TO MAINTIAN THIS WE CAN"T USE THIS APPROACB FOR THOSE ARRAYS.
    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
        // if sum > k, reduce the subarray from left until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward thw right pointer:
        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
}

int main(){
    vector<int>arr1={1,2,3,1,1,1,1,4,2,3};
    cout<<findLongestSubarrayWithSumKApproach2(arr1,3);
    return 0;
}