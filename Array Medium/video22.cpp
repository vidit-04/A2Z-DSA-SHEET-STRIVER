#include<bits/stdc++.h>
using namespace std;

void mergeArrays(vector<int> &a,int low,int mid,int high){
    int i=low;
    int j=mid+1;
    vector<int>temp;
    while(i<=mid && j<=high){
        if(a[i]<=a[j]){
            temp.push_back(a[i]);
            i++;
        }
        else{
            temp.push_back(a[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(a[i]);
        i++;
    }
    while(j<=high){
        temp.push_back(a[j]);
        j++;
    }
    for(int i=low;i<=high;i++){
        a[i]=temp[i-low];
    }    
}   

void SortAnArrayOf0s1s2s(vector<int> &a,int low,int high){
    //SORT AN ARRAY OF 0s 1s 2s - BRUTE FORCE
    if(low>=high) return;
        int mid=(low+high)/2;
        SortAnArrayOf0s1s2s(a,low,mid);
        SortAnArrayOf0s1s2s(a,mid+1,high);
        mergeArrays(a,low,mid,high);
}

void SortAnArrayOf0s1s2sApproach2(vector<int> &a){
    //SORT AN ARRAY OF 0s 1s 2s - Approach 2 - Better Approach
    int zeroes=0;
    int ones=0;
    int twos=0;

    for(int i=0;i<a.size();i++){
        if(a[i]==0) zeroes++;
        else if(a[i]==1) ones++;
        else twos++;
    }
    for(int i=0;i<zeroes;i++){
        a[i]=0;
    }
    for(int i=zeroes;i<zeroes+ones;i++){
        a[i]=1;
    }
    for(int i=ones+zeroes;i<a.size();i++){
        a[i]=2;
    }
}

void SortAnArrayOf0s1s2sApproach3(vector<int> &a){
    //SORT AN ARRAY OF 0s 1s 2s - Approach 3 - Best Approach
    //Dutch Flag Approach
    int low=0;
    int mid=0;
    int high=a.size()-1;
    while (mid<=high)
    {
        if(a[mid]==0){
            swap(a[low],a[mid]);
            low++;
            mid++;
        }
        else if(a[mid]==1){
            mid++;
        }
        else{
            swap(a[mid],a[high]);
            high--;
        }
    }
    
}

int main(){
    vector<int>a={0,1,2,0,1,2,1,2,0,0,1,1};
    SortAnArrayOf0s1s2sApproach3(a);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    return 0;
}