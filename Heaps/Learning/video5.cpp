#include<bits/stdc++.h>
using namespace std;

void Heapify(vector<int> &ans,int index,int n){
    int largest=index;
    int left=2*index+1;
    int right=2*index+2;

    if(left<n && ans[left]>ans[largest]){
        largest=left;
    }
    if(right<n && ans[right]>ans[largest]){
        largest=right;
    }
    if(largest!=index){
        swap(ans[largest],ans[index]);
        Heapify(ans,largest,n);
    }

}

vector<int> MergeTwoBinaryMaxHeaps(vector<int>a, vector<int>b){
    int n1=a.size();
    int n2=b.size();
    int n=n1+n2;
    vector<int>ans(n);

    for(int i=0;i<n1;i++){
        ans.push_back(a[i]);
    }
    for(int i=0;i<n2;i++){
        ans.push_back(b[i]);
    }
    for(int i=n/2-1;i>=0;i++){
        Heapify(ans,i,n);
    }
    return ans;
}

int main(){
    //Merge two binary max heaps
    vector<int> a={10,5,6,2};
    vector<int> b={12,7,9};
    vector<int>ans=MergeTwoBinaryMaxHeaps(a,b);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}