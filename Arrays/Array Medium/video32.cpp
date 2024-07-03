#include<bits/stdc++.h>
using namespace std;

void spiralMatrix(vector<vector<int>>a){
    int m=a.size();
    int n=a[0].size();

    int left=0;
    int right=n-1;
    int top=0;
    int bottom=m-1;
    vector<int>ans;

    while (top<=bottom || left<=right){
        for(int i=left;i<=right;i++){
            ans.push_back(a[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(a[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(a[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(a[i][left]);
            }
            left++;
        }
    }
    for(auto it:ans){
        cout<<it<<" ";
    }
}

int main(){
    vector<vector<int>>a={{1,2,3,4,5,6},{20,21,22,23,24,7},{19,32,33,34,25,8},{18,31,36,35,26,9},{17,30,29,28,27,10},{16,15,14,13,12,11}};
    // for (int i = 0; i < a.size(); i++)
    // {
    //     for (int j = 0; j < a.size(); j++)
    //     {
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;        
    // }
    
    spiralMatrix(a);
    return 0;
}