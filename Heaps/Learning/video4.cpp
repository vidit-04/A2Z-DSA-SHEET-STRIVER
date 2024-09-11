#include<bits/stdc++.h>
using namespace std;

int KthSmallestElement(vector<int>a,int k){
    //BRUTE FORCE- SOrting
    sort(a.begin(),a.end());
    return a[k-1];

    //T.C.-O(nlog n)
    //S.C.-O(1)
}

int KthSmallestElementApproach2(vector<int>a,int k){
    //Using Min Heap
    priority_queue<int,vector<int>,greater<int>> p;
    for(int i=0;i<a.size();i++){
        p.push(a[i]);
    }
    int ans;
    while(k--){
        ans=p.top();
        p.pop();
    }
    return ans;
    //T.C.-O(nlog k)
    //S.C.-O(k)
}

int KthSmallestElementApproach3(vector<int>a,int k){
    //Using Max Heap
    //Optimal Approach
    //We will keep maintaining the heap of size k=4(let) then always keep the smallest 4 element in it.
    //Then among those 4 element its p.top() is always ans because p.top() is the greatest element among those 4 element which are smalles in whole vector.
    //Because all we need to find is the kth smallest number
    priority_queue<int> p;
    for(int i=0;i<k;i++){
        p.push(a[i]);
    }
    for(int i=k
    ;i<a.size();i++){
        if(p.size()<k || p.top()> a[i]){
            p.pop();
            p.push(a[i]);
        }
    }
    return p.top();

}

int KthLargestElementApproach2(vector<int>a,int k){
    //USING MAX HEAP
    priority_queue<int> p;
    for(int i=0;i<a.size();i++){
        p.push(a[i]);
    }
    k--;
    while(k--){
        p.pop();
    }
    return p.top();
    //T.C.-O(n+klog n)
    //S.C.-O(n)
}

int KthLargestElementApproach3(vector<int>a,int k){
    //USING MIN HEAP
    priority_queue<int,vector<int>,greater<int>> p;
    for(int i=0;i<k;i++){
        p.push(a[i]);
    }
    for(int i=k;i<a.size();i++){
        if(p.top()<a[i]){
            p.pop();
            p.push(a[i]);
        }
    }
    return p.top();
    //T.C.-O(nlog k)
    //S.C.-O(k)
}

int main(){
    //Kth Smallest Element
    vector<int>a={10,3,7,4,8,9,2,6};
    int k=4;
    cout<<KthSmallestElementApproach3(a,k)<<endl;
    cout<<KthLargestElementApproach3(a,k)<<endl;
    return 0;
}