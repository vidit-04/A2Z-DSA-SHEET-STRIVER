#include<bits/stdc++.h>
using namespace std;
pair<int,int> SearchIn2DMatrixPart2(vector<vector<int>>a,int target){
    //BRUTE FORCE
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            if(a[i][j]==target) return {i,j};
        }
    }
    return {-1,-1};
    //T.C.- O(n*m)
    //S.C.- O(1)
}

int binarySearch(vector<int>a,int target){
    int low=0;
    int high=a.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==target){
            return mid;
        }
        else if(a[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

pair<int,int> SearchIn2DMatrixPart2Approach2(vector<vector<int>>a,int n,int m,int target){
    //BEtter FORCE
    // n-rows
    // m-cols
    for(int i=0;i<n;i++){
        if(a[i][0]<=target && target<=a[i][m-1]){
            //BINARY SEARCH
            int ind=binarySearch(a[i],target);
            if(ind!=-1){
                return {i,ind};
            }
        }
    }
    return{-1,-1};
    //T.C.- O(nlogm)
    //S.C.- O(1)
}

pair<int,int> SearchIn2DMatrixPart2Approach3(vector<vector<int>>a,int n,int m,int target){
    int row=0;
    int col=m-1;
    while(row<n && col>=0){
        if(a[row][col]==target) return {row,col};
        else if(a[row][col]<target) row++;
        else col--;;
    }
    return {-1,-1};
    //T.C. -O(n+m)
    //S.C. -O(1)
}
int main(){
    //Matrix only sorted in row wise and col wise.
    vector<vector<int>>a={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target=14;
    int n=a.size();
    int m=a[0].size();
    pair<int,int>res=SearchIn2DMatrixPart2Approach3(a,n,m,target);
    cout<<res.first<<" "<<res.second;
    return 0;
}