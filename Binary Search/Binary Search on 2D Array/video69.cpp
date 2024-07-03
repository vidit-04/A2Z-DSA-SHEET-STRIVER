#include<bits/stdc++.h>
using namespace std;

pair<int,int> SearchIn2DMatrix(vector<vector<int>>a,int target){
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

pair<int,int> SearchIn2DMatrixApproach2(vector<vector<int>>a,int n,int m,int target){
    //BEtter FORCE
    // n-rows
    // m-cols
    for(int i=0;i<n;i++){
        if(a[i][0]<=target && target<=a[i][m-1]){
            //BINARY SEARCH
            int low=0;
            int high=m-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(a[i][mid]==target){
                    return {i,mid};
                }
                else if(a[i][mid]<target){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
    }
    return{-1,-1};
}

pair<int,int> SearchIn2DMatrixApproach3(vector<vector<int>>a,int n,int m,int target){
    //FLATTENING ARRAY
    int low=0;
    int high=(n*m)-1;
    while(low<=high){
        int mid=(low+high)/2;
        int row=mid/m;
        int col=mid%m;
        if(a[row][col]==target){
            return {row,col};
        }
        else if(a[row][col]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return {-1,-1};
}
int main(){
    vector<vector<int>>a={{3,4,7,9},{12,13,16,18},{20,21,23,29}};
    int target=21;
    int n=a.size();
    int m=a[0].size();
    
    pair<int,int>p=SearchIn2DMatrixApproach3(a,n,m,target);
    cout<<p.first<<" "<<p.second;
    return 0;
}