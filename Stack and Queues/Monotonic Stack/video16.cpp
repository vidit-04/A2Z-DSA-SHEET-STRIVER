#include<bits/stdc++.h>
using namespace std;

vector<int> SlidingWindowMaximum(vector<int> arr,int n,int k){
    vector<int>ans;
    for(int i=0;i<n-k;i++){
        int maxi=arr[i];
        for(int j=i;j<i+k-1;j++){
            maxi=max(maxi,arr[j]);
        }
        ans.push_back(maxi);
    }
    return ans;
    // T.C.-O(N-K*K)
    // S.C.-O(N-K)
}

vector<int> SlidingWindowMaximumApproach2(vector<int> arr,int n,int k){
    vector<int>ans;
    deque<int>q;
    for(int i=0;i<n;i++){
        if(!q.empty() && q.front()==i-k){
            q.pop_front();
        }
        while(!q.empty() && arr[q.back()]<=arr[i]){
            q.pop_back();
        }
        q.push_back(i);
        if(i>=k-1){
            ans.push_back(arr[q.front()]);
        }
    }
    return ans;
    // T.C.-O(2N)
    // S.C.-O(K)+O(N-K)
}

int main(){
    //SLIDING WINDOW MAXIMUM
    vector<int>arr={1,3,-1,-3,5,3,2,1,6};
    int k=3;
    int n=arr.size();
    vector<int>ans=SlidingWindowMaximumApproach2(arr,n,k);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}