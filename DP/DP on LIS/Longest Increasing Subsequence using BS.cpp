#include<bits/stdc++.h>
using namespace std;

int lis(vector<int>& arr) {
    // code here
    vector<int>dp;
    int len=1;
    dp.push_back(arr[0]);
    for(int i=1;i<arr.size();i++){
        if(dp.back()<arr[i]) {
            dp.push_back(arr[i]); 
            len++;
        }
        else{
            int ind=lower_bound(dp.begin(),dp.end(),arr[i])-dp.begin();
            dp[ind]=arr[i];
        }
    }
    return len;
    
}

int main(){
    int n=7;
    vector<int> arr={1,2,3,4,5,6,7};
    cout<<lis(arr)<<endl; //7   
    return 0;
}