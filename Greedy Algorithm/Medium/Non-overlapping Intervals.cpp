#include<bits/stdc++.h>
using namespace std;

int NonoverlappingIntervals(vector<vector<int>>a){
    sort(a.begin(),a.end(),[](vector<int>a,vector<int>b){
        return a[1]<b[1];
    });
    vector<vector<int>> ans;
    ans.push_back(a[0]);
    int cnt=1;
    int lastEndTime=ans[0][1];
    for(int i=1;i<a.size();i++){
        if(lastEndTime<=a[i][0]){
            lastEndTime=a[i][1];
            cnt++;
            ans.push_back(a[i]);
        }
    }
    return a.size()-cnt;
    //T.C.-O(nlogn+n)
    //S.C.-O(2*n)
}

int main(){
    vector<vector<int>> a={{0,5},{3,4},{1,2},{5,9},{5,7},{7,9}};
    cout<<NonoverlappingIntervals(a);
    return 0;
}