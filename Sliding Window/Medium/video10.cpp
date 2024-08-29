#include<bits/stdc++.h>
using namespace std;

int BinarySubarrayWithSum(vector<int>a,int goal){
    if(goal<0) return 0;
    int n=a.size();
    int sum=0,count=0;
    int l=0,r=0;
    while(r<n){
        sum+=(a[r]%2);
        while(sum>goal){
            sum=(sum-a[l]%2);
            l++;
        }
        count=count+(r-l+1);
        r++;
    }
    return count;
    //T.C.-O(2N)
    //S.C.-O(1)
}

int NumberOfNiceSubarrays(vector<int>a,int k){
    //SAME AS 
    return BinarySubarrayWithSum(a,k)-BinarySubarrayWithSum(a,k-1);
}

int main(){
    //COUNT THE NUMBER OF NICE SUBARRAYS
    vector<int>a={1,5,2,1,1};
    int k=3;
    cout<<NumberOfNiceSubarrays(a,k);
    return 0;
}