#include<bits/stdc++.h>
using namespace std;

int countInversion(vector<int>a){
    //We need to count no. of pairs where (i,j) a[i]>a[j]
    //Brute Force
    int n=a.size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                // cout<<a[i]<<" "<<a[j]<<endl;
                count++;
            }
        }
    }
    return count;
    //T.C. - O(n^2)
    //S.C. - O(1)
}

int merge(vector<int> &arr, int low, int mid, int high) {
    int left=low;
    int right=mid+1;
    vector<int>temp;
    int count=0;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            count+=mid-left+1;
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
    return count;
}
int mS(vector<int> &arr, int low, int high) {
    int count=0;
    if(low>=high) return count;
    int mid=(low+high)/2;

    count+=mS(arr, low, mid);
    count+=mS(arr, mid+1,high);
    count+=merge(arr,low,mid,high);
    return count;
}

int countInversionApproach2(vector<int>arr){
    //We need to count no. of pairs where (i,j) a[i]>a[j]
    //optimal Approach  - Merge SOrt
    int n=arr.size();
    return mS(arr,0,n-1);
}

int main(){
    vector<int>a={5,3,2,4,1};
    cout<<countInversionApproach2(a)<<endl;
    return 0;
}