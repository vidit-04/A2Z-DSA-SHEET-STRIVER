#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
    vector<vector<int>>ans;
    int i=0;
    int n=intervals.size();
    while(i<n && intervals[i][1]<newInterval[0]){
        ans.push_back(intervals[i]);
        i++;
    }
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(intervals[i][0], newInterval[0]);
        newInterval[1] = max(intervals[i][1], newInterval[1]);
        i++;
    }
    ans.push_back(newInterval);
    while(i<n){
        ans.push_back(intervals[i]);
        i++;
    }
    return ans;
}

int main(){
    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int> newInterval = {2,5};
    vector<vector<int>> ans=insert(intervals,newInterval);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}