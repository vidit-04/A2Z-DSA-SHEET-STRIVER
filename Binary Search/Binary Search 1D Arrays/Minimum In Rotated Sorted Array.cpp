#include<bits/stdc++.h>
using namespace std;

int minimumInRotatedSortedArray(vector<int>a){
    //Smallest Element in Array
    //Step1 : Find the sorted half of array
    //Step2 : If left half is sorted then compare a[low] with mini otherwise compare a[mid] with mini.
    //Step 3: Remove the sorted half now bcs it's smallest half is already in your mini.
    //Step 4 : Update low and high accordingly

    int low=0;
    int high=a.size()-1;
    int mini=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;

        if(a[low]<a[high]){
             mini=min(a[low],mini);
             break;
             //This is the last case in cases where we get this condition.
        }
        else if(a[mid]<a[high]){
            mini=min(a[mid],mini);
            high=mid-1;
        }
        else{
            mini=min(a[low],mini);
            low=mid+1;
        }
    }
    return mini;
}

int main(){
    vector<int>a={7,8,1,2,3,3,3,4,5,6};
    cout<<minimumInRotatedSortedArray(a);
    return 0;
}