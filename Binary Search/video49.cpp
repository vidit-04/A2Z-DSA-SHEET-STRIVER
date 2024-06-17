#include<bits/stdc++.h>
using namespace std;

bool searchInRotatedSortedArrayWithDuplicatesPartTwo(vector<int>a,int target){
    //Array has duplicates elements---Index for first occurence
    int low=0;
    int high=a.size()-1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==target){
             return  true;
        }
        //Checking which half is sorted
        else if(a[low]==a[mid] && a[mid]==a[high]){
            low++;
            high--;
        }
        //left part is sorted
        
        else if(a[mid]>=a[low]){
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
    return false;
}

int main(){
    vector<int>b={7,8,1,2,3,3,3,4,5,6};
    vector<int>c={3,1,2,3,3,3,3,3,3,3}; //In this type of collection it is difficult to determine which portion is sorted so we need to low++ and high-- for that
    int target=3;
    cout<<searchInRotatedSortedArrayWithDuplicatesPartTwo(b,target);
    return 0;
}