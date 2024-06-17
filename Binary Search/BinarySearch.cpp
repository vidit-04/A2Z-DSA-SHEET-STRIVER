#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>a,int target){
    //Iterative Approach
    int left=0;
        int right=a.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(a[mid]==target){
                return mid;
            }
            else if(a[mid]<target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return -1;
}

int binarySearchApproach2(vector<int>a,int target,int low,int high){
    //Recursive Approach
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(a[mid]==target) return mid;
    else if(a[mid]>target) return binarySearchApproach2(a,target,low,mid-1);
    else return binarySearchApproach2(a,target,mid+1,high);
    // return mid;
}


int main(){
    vector<int>a={1, 3, 7, 9, 11, 12, 45};
    int target=11;
    // cout<<binarySearch(a,target)<<endl;    
    cout<<binarySearchApproach2(a,target,0,a.size()-1)<<endl;    
    return 0;
}