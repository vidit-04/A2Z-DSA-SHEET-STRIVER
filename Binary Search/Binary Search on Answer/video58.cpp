#include<bits/stdc++.h>
using namespace std;

int smallestDivisorForThreshold(vector<int>a,int threshold){
    //BRUTE FORCE
    int maxi=*max_element(a.begin(),a.end());
    for(int i=1;i<=maxi;i++){
        int sum=0;
        for(int j=0;j<a.size();j++){
            sum+=ceil((double)a[j]/i);
        }
        if(sum<=threshold) return i;
    }
    return -1;
    //T.C.-O(max_element*n)
}

bool IsDivisor(vector<int>a,int threshold,int mid){
    int sum=0;
    for(int i=0;i<a.size();i++){
        sum+=ceil((double)a[i]/(double)mid);
    }
    return sum<=threshold;
}

int smallestDivisorForThresholdApproach2(vector<int>a,int threshold){
    //Optimal COde- Binary Search
    int maxi=*max_element(a.begin(),a.end());
    int low=1;
    int high=maxi;
    while(low<=high){
        int mid=(low+high)/2;
        if(IsDivisor(a,threshold,mid)){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}

int main(){
    vector<int>a={1,2,5,9};
    int threshold=6;
    cout<<smallestDivisorForThreshold(a,threshold);
    return 0;
}