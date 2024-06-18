#include<bits/stdc++.h>
using namespace std;

void firstAndLastOccurence(vector<int> a,int target){
    //BRUTE FORCE
    int first=-1;
    int last=-1;
    for(int i=0;i<a.size();i++){
        if(a[i]==target){
            if(first==-1) first=i;
            last=i;
        }
    }
}    


int firstOccurence(vector<int> nums,int target){
    int low=0;
    int n=nums.size();
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            high=mid-1;
            ans=mid;
        }
        else if(nums[mid]>target) high=mid-1;
        else low=mid+1;
    }
    return ans;
}
int lastOccurence(vector<int> nums,int target){
    int low=0;
    int n=nums.size();
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            low=mid+1;
            ans=mid;
        }
        else if(nums[mid]>target) high=mid-1;
        else low=mid+1;
    }
    return ans;
}

void firstAndLastOccurenceApproach2(vector<int> a,int target){
    //BINARY SEARCH
    int first=firstOccurence(a,target);
    int last=lastOccurence(a,target);
    cout<<first<<"-"<<last;
}

int main(){
    vector<int> a={2,4,6,8,8,8,11,13};
    int target=8;
    firstAndLastOccurence(a,target);

    return 0;
}