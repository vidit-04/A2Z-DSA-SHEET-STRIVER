#include<bits/stdc++.h>
using namespace std;

int peakElement(vector<int>a){
    //BRUTE FORCE
    int n=a.size();
    for(int i=0;i<n;i++){
        if((i==0 || a[i-1]<a[i]) && (i==n-1|| a[i+1]<a[i])){
            return a[i];
        }
    }
    return -1;
    //T.C. - O(n)
    //S.C. - O(1)
}

int peakElementApproach2(vector<int>a){
    //element at left and right should be smaller than mid element
    int n=a.size();
    if(n==1) return 0;

    int low=1;
    int high=n-2;
    while(low<=high){
        int mid=(low+high)/2;
        if(mid==0) {
            if(a[0]>a[1]) return 0;
        }
        if(mid==n-1) {
            if(a[n-1]>a[n-2]) return n-1;
        }
        
        if(a[mid]>a[mid-1] && a[mid]>a[mid+1]){
            return mid; 
        }
        //we are on left side of peak
        else if(a[mid]>a[mid-1]){
            low=mid+1;
        }
        //we are on right side of peak
        else{
            high=mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int>a={1,2,3,4,5,6,7,8,5,1};
    vector<int>b={1,10,13,7,6,5,4,2,1,0};
    cout<<peakElementApproach2(b);
    return 0;
}