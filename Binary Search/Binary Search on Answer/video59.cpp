#include<bits/stdc++.h>
using namespace std;

int func(vector<int>a,int days,int capacity){
    int day=1;
    int load=0;
    for(int i=0;i<a.size();i++){
        if(load+a[i]>capacity){
            day+=1;
            load=a[i];
        }
        else{
            load+=a[i];
        }
    }
    return day;
}

int CapacityToShipPackagesWithinDdays(vector<int>a,int days){
    //Brute Force
    int min_capacity=*max_element(a.begin(),a.end()); 
    int max_capacity=accumulate(a.begin(),a.end(),0);//addition of all elemenr]ts of array
    for(int i=min_capacity;i<=max_capacity;i++){
        int daysReq=func(a,days,i);
        if(daysReq<=days) return i;
    }
    return -1;
    //T.C.-O(sum-max+1)*(n)
    //S.C.-O(1)
}

int CapacityToShipPackagesWithinDdaysApproach2(vector<int>a,int days){
    //Optimised - Binary Search
    int low=*max_element(a.begin(),a.end()); 
    int high=accumulate(a.begin(),a.end(),0);//addition of all elemenr]ts of array
    while(low<=high){
        int mid=(low+high)/2;
        int daysReq=func(a,days,mid);
        if(daysReq<=days){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
    //T.C.-O(nlog(sum-max+1))
    //S.C.-O(1)
}

int main(){
    vector<int>a={1,2,3,4,5,6,7,8,9,10};
    int days=5;
    cout<<CapacityToShipPackagesWithinDdaysApproach2(a,days);
    return 0;
}