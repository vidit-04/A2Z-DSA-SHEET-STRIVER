#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>a, int target){
    // a[mid]>=n  -smallest index
    int low=0;
    int high=a.size()-1;
    int ans=a.size();
    while(low<high){
        int mid=low+(high-low)/2;
        if(a[mid]>=target){
            high=mid-1;
            ans=mid;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int upperBound(vector<int>c,int target){
    //a[mid]>n   -smallest index
    int low=0;
    int high=c.size()-1;
    int ans=c.size();
    while(low<high){
        int mid=low+(high-low)/2;
        if(c[mid]>target){
            high=mid-1;
            ans=mid;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int ceil(vector<int> arr, int n, int x) {
	// Write your code here
	int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>=x){
            high=mid-1;
            ans=arr[mid];
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int floor(vector<int> arr, int n, int x) {
	// Write your code here
	int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]<=x){
            low=mid+1;
            ans=arr[mid];
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}

pair<int,int> FloorAndCeilInSortedArray(vector<int>a,int target){
    //Floor- largest no. in array<=target
    //Ceil- smallest no. in array>=target
    int c=ceil(a, a.size(), target);
	int b=floor(a,a.size(),target);
	return {b,c};
}

int main(){
    vector<int>a={1,2,3,3,5,8,8,10,10,11};
    int target=3;
    cout<<lowerBound(a,target)<<endl;
    auto b=lower_bound(a.begin(),a.end(),2);
    cout<<(b-a.begin())<<" ye h"<<endl;
    
    vector<int>c={2,3,6,7,8,8,11,11,11,12};
    int target2=8;
    cout<<upperBound(c,target2)<<endl;
    return 0;
}