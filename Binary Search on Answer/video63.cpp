#include<bits/stdc++.h>
using namespace std;

// Painter Partition and Split Array Largest Sum problems are same.
// Code for them will be same as Book Allocation Problem

int func(vector<int>a,int no_of_pages){
    int cntStudent=1;
    int pages=0;
    for(int i=0;i<a.size();i++){
        if(pages+a[i]<=no_of_pages){
            pages+=a[i];
        }
        else{
            cntStudent++;
            pages=a[i];
        }
    }
    return cntStudent;
}

int painterPartitionAndSplitArrayLargestSum(vector<int>a,int k){
        //OPTIMAL SOLUTION
    int n=a.size();  // No. of books
    if(k>n) return -1;

    int low=*max_element(a.begin(),a.end());
    int high=accumulate(a.begin(),a.end(),0);

    while(low<=high){
        int mid=(low+high)/2;
        int cntStudent=func(a,mid);
        if(cntStudent<=k){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
    //T.C.-O(nlog(sum-max))
    //S.C.-O(1)
}

int main(){
    // Painter Partition and Split Array Largest Sum problems are same.
    // Code for them will be same as Book Allocation Problem
    vector<int>a={10,20,30,40};
    int k=2;
    cout<<painterPartitionAndSplitArrayLargestSum(a,k);
    return 0;
}