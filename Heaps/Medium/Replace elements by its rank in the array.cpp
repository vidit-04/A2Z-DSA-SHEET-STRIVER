#include<bits/stdc++.h>
using namespace std;

vector<int> replaceWithRank(vector<int> &arr, int n){
    vector<int>a(arr);
    map<int,int>mpp;
    sort(a.begin(),a.end());
    int rnk=0;
    for(int i=0;i<n;i++){
        if(mpp.find(a[i])!=mpp.end()){
            mpp[a[i]]=rnk;
        }
        else{
            rnk++;
            mpp[a[i]]=rnk;
        }
    }
    for(int i=0;i<n;i++){
        arr[i]=mpp[arr[i]];
    }
    return arr;
}

int main(){
    
    return 0;
}