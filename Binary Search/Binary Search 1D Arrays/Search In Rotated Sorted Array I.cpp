#include<bits/stdc++.h>
using namespace std;

int searchInRotatedSortedArrayPartOne(vector<int>a,int target){
    //Array has only unique elements
    //Step1 : Identify the sorted half. Either left or right by checking if a[low]<a[high]
    //Step2 : Check if target lies in the sorted half. If yes, then do binary search in that half
    //Step3 : If target does not lie in the sorted half, then search in the unsorted half
    int low=0;
    int high=a.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==target) return mid;
        //Checking which half is sorted

        //left part is sorted
        if(a[mid]>=a[low]){
            if(a[low]<=target && target<=a[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        //right part is sorted
        else{
            if(a[mid]<=target && target<=a[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return -1;
}


int main(){
    vector<int>a={7,8,9,1,2,3,4,5,6};
    int target=9;
    cout<<searchInRotatedSortedArrayPartOne(a,target);
    return 0;
}