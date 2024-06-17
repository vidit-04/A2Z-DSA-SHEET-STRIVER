#include<bits/stdc++.h>
using namespace std;

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
void mS(vector<int> &arr, int low, int high) {
    if(low>=high) return;
    int mid=(low+high)/2;

    mS(arr, low, mid);
    mS(arr, mid+1,high);
    merge(arr,low,mid,high);
}
void mergeSort(vector < int > & arr, int n) {
    // Write your code here.
    mS(arr,0,n-1);
}

int main(){
    vector<int>arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){   
        int x;
        cin>>x;
        arr.push_back(x);
    }
    mergeSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    // INPUT:
    // 7
    // 45 73 24 9 1 95 7
    return 0;
}