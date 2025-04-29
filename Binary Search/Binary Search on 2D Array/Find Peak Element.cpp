#include<bits/stdc++.h>
using namespace std;

int maxElement(vector<vector<int>>a,int n,int m,int mid){
    int maxi=-1;
    int maxIndex=-1;
    for(int i=0;i<n;i++){
        if(a[i][mid]>maxi){
            maxi=a[i][mid];
            maxIndex=i;
        }
    }
    return maxIndex;
}

pair<int,int> PeakElementIn2DArray(vector<vector<int>>a){
    int n=a.size();
    int m=a[0].size();
    int low=0;
    int high=m-1;
    while(low<=high){
        int mid=(low+high)/2;
        int row=maxElement(a,n,m,mid); //row which has max element
        int left=mid-1>=0?a[row][mid-1]:-1;
        int right=mid+1<m?a[row][mid+1]:-1;

        if(a[row][mid]>left && a[row][mid]>right){
            return {row,mid};
        }
        else if(a[row][mid]<left){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return {-1,-1};
    //T.C.- O(nlogm)
    //S.C.- O(1)
}

int main(){
    vector<vector<int>>a={{4,2,5,1,4,5},{2,9,3,2,3,2},{1,7,6,0,1,3},{3,6,2,3,7,2}};
    pair<int,int>p=PeakElementIn2DArray(a);
    cout<<p.first<<" "<<p.second;
    return 0;
}