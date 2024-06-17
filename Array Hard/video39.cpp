#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> MergeOverlappingIntervals(vector<vector<int>> a){
    //BRUTE FORCE
    int n=a.size();
    vector<vector<int>>ans;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        int start=a[i][0];
        int end=a[i][1];
        if(!ans.empty() && end<=ans.back()[1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(a[j][0]<=end){
                end=max(end,a[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
    //T.C. - O(NlogN)+O(2n)
    //S.C. - O(N)
}

vector<vector<int>> MergeOverlappingIntervals(vector<vector<int>> a){
    //Optimal SOlution
    //We are reducing that 2n T.C. here
    int n=a.size();
    vector<vector<int>>ans;
    sort(a.begin(),a.end());

    for(int i=0;i<n;i++){
        if(ans.empty() || ans[i][0]>ans.back()[1]){
            ans.push_back(a[i]);
        }
        else{
            ans.back()[1]=max(ans[i][1],ans.back()[1]);
        }
    }
    return ans;
    //T.C. - O(NlogN)
    //S.C. - O(N)
}
int main(){
    vector<vector<int>> a={{1,3},{2,6},{8,9},{9,11},{8,10},{2,4},{15,18},{16,17}};
    vector<vector<int>> ans=MergeOverlappingIntervals(a);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}