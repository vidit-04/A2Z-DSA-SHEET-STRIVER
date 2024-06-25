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

int MedianOf2DMatrix(vector<vector<int>>a){
    //BRUTE FORCE
    int n=a.size();
    int m=a[0].size();

}

int main(){
    vector<vector<int>>a={{1,5,7,9,11},{2,3,4,5,10},{9,10,12,14,16}};
    cout<<MedianOf2DMatrix(a);
    
    return 0;
}