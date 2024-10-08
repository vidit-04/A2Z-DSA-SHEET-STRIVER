#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end());
    vector<vector<int>>ans;
    for(int i=0;i<intervals.size();i++){
        if(ans.empty() || ans.back()[1]<intervals[i][0]){
            ans.push_back(intervals[i]);
        }
        else{
            ans.back()[1]=max(ans.back()[1],intervals[i][1]);
        }
    }
    return ans;
}

int main(){
    vector<vector<int>>intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>>ans=merge(intervals);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }    
    return 0;
}