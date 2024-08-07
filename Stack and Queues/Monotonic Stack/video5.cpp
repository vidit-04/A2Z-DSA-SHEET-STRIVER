#include<bits/stdc++.h>
using namespace std;

vector<int> NextGreaterElement(vector<int>arr,int n){
    //BRUTE FORCE
    vector<int>ans(n,-1);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                ans[i]=arr[j];
                break;
            }
        }
    } 
    return ans;
    //T.C.- O(N^2)
    //S.C.- O(N)
}

vector<int> NextGreaterElementApproach2(vector<int>arr,int n){
    //OPTIMAL APPROACH
    stack<int>s;
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && s.top()<=arr[i]){
            s.pop();
        }
        if(s.empty()) ans[i]=-1;
        else ans[i]=s.top();
        s.push(arr[i]);
    }
    return ans;
    //T.C.- O(N)+O(N)
    //S.C.- O(N)+O(N)
}

vector<int> NextSmallerElementApproach2(vector<int>arr,int n){
    //OPTIMAL APPROACH
    stack<int>s;
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && s.top()>=arr[i]){
            s.pop();
        }
        if(s.empty()) ans[i]=-1;
        else ans[i]=s.top();
        s.push(arr[i]);
    }
    return ans;
    //T.C.- O(N)+O(N)
    //S.C.- O(N)+O(N)
}

int main(){
    // vector<int>arr={6,0,8,1,3};
    vector<int>arr={4,12,5,3,1,2,5,3,1,2,4,6};
    int n=arr.size();
    // vector<int>ans=NextGreaterElement(arr,n);
    vector<int>ans=NextGreaterElementApproach2(arr,n);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}