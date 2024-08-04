#include<bits/stdc++.h>
using namespace std;

vector<int> NextGreaterElement2(vector<int>arr,int n){
    //BRUTE FORCE
    vector<int>ans(n,-1);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<i+n;j++){
            int ind=j%n;
            if(arr[ind]>arr[i]){
                ans[i]=arr[j];
                break;
            }
        }
    } 
    return ans;
    //T.C.- O(N^2)
    //S.C.- O(N)
}

vector<int> NextGreaterElement2Approach2(vector<int>arr,int n){
    //OPTIMAL APPROACH
    vector<int>ans(n,-1);
    stack<int>s;
    for(int i=2*n-1;i>=0;i--){
        while(!s.empty() && s.top()<=arr[i%n]){
            s.pop();
        }
        if(i<n){
            ans[i]=s.empty()?-1:s.top();
        }
        s.push(arr[i%n]);
    }
    return ans;
    //T.C.- O(4N)
    //S.C.- O(3N)
}

int main(){
    vector<int>arr={4,12,5,3,1,2,5,3,1,2,4,6};
    int n=arr.size();
    vector<int>ans=NextGreaterElement2Approach2(arr,n);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}