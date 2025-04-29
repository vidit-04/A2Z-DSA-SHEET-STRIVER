#include<bits/stdc++.h>
using namespace std;

int MedianOf2DMatrix(vector<vector<int>>a){
    //BRUTE FORCE
    int n=a.size();
    int m=a[0].size();
    vector<int>ls;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ls.push_back(a[i][j]);
        }
    }
    sort(ls.begin(),ls.end());
    int mid=(n*m)/2;
    if((n*m)%2==0){
        return (ls[mid]+ls[mid-1])/2;
    }
    return ls[mid];
    //T.C.- O(n*mlog(n*m))
    //S.C.- O(n*m)
}

int upperBound(vector<int>a,int mid){
    int low=0;
    int high=a.size()-1;
    int ans;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]<=mid){
            low=mid+1;
        }
        else{
            high=mid-1;
            ans=mid;
        }
    }
    return low;
}

int countSmallEqual(vector<vector<int>>a,int mid){
    int n=a.size();
    int m=a[0].size();
    int count=0;
    for(int i=0;i<n;i++){
        count+=upperBound(a[i],mid);
    }
    return count;
    //T.C.=O(nlogm)
    //S.C.=O(1)
}

int MedianOf2DMatrixApproach2(vector<vector<int>>a){
    //BINARY SEARCH
    int n=a.size();
    int m=a[0].size();
    int low=INT_MAX;
    int high=INT_MIN;
    for(int i=0;i<n;i++){
        low=min(low,a[i][0]);
        high=max(high,a[i][m-1]);
    }

    int req=(n*m)/2;
    while(low<=high){
        int mid=(low+high)/2;
        int smallerEquals=countSmallEqual(a,mid);
        if(smallerEquals<=req){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
    //T.C.=O(nlogm)*(nlogm)
    //S.C.=O(1)
}

int main(){
    vector<vector<int>>a={{1,5,7,9,11},{2,3,4,5,10},{9,10,12,14,16}};
    cout<<MedianOf2DMatrix(a);   
    return 0;
} 