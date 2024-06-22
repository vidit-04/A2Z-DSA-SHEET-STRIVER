#include<bits/stdc++.h>
using namespace std;

int reversePair(vector<int>a){
    //We need to count no. of pairs where (i,j) a[i]>2a[j]
    //Brute Force
    int n=a.size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>2*a[j]){
                // cout<<a[i]<<" "<<a[j]<<endl;
                count++;
            }
        }
    }
    return count;
    //T.C. - O(n^2)
    //S.C. - O(1)
}

void merge(vector<int> &arr, int low, int mid, int high) {
    int left=low;
    int right=mid+1;
    vector<int>temp;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}

int countPairs(vector<int> &arr,int low,int mid,int high){
    int count=0;
    int right=mid+1;
    for(int i=low;i<=mid;i++){
        while (right<=high && arr[i]>2*arr[right]){
            right++;
        }
        count+=right-(mid+1);
    }
    return count;
    
}
int mS(vector<int> &arr, int low, int high) {
    int count=0;
    if(low>=high) return count;
    int mid=(low+high)/2;

    count+=mS(arr, low, mid);
    count+=mS(arr, mid+1,high);
    count+=countPairs(arr,low,mid,high);
    merge(arr,low,mid,high);

    return count;
}

int reversePairApproaach2(vector<int>arr){
    //We need to count no. of pairs where (i,j) a[i]>a[j]
    //optimal Approach  - Merge SOrt
    int n=arr.size();
    return mS(arr,0,n-1);
}

int main(){
    vector<int>a={40,25,19,12,9,6,2};
    // vector<int>a={4,1,2,3,1};
    cout<<reversePairApproaach2(a)<<endl;
    return 0;
}