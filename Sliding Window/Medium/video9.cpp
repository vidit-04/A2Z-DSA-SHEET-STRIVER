#include<bits/stdc++.h>
using namespace std;

int BinarySubarrayWithSum(vector<int>a,int goal){
    if(goal<0) return 0;
    int n=a.size();
    int sum=0,count=0;
    int l=0,r=0;
    while(r<n){
        sum+=a[r];
        while(sum>goal){
            sum=sum-a[l];
            l++;
        }
        count=count+(r-l+1);
        r++;
    }
    return count;
    //T.C.-O(2N)
    //S.C.-O(1)
}
 
int main(){
    //Binary Subarrays With Sum / Count Subarray with sum equal to k
    vector<int>a={1,0,1,0,1};
    int goal=2;
    cout<<BinarySubarrayWithSum(a,goal)-BinarySubarrayWithSum(a,goal-1)<<endl;
    return 0;
}