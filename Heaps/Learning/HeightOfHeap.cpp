#include<bits/stdc++.h>
using namespace std;

void Heapify(vector<int>&a,int index,int n){
    //Step down process
    int largest=index;
    int left=2*index+1;
    int right=2*index+2;

    //Largest will contain that element which is largest among parent, left child, right child.
    if(left<n && a[left]>a[largest]){
        largest=left;
    }
    if(right<n && a[right]>a[largest]){
        largest=right;
    }
    if(largest!=index){
        swap(a[largest],a[index]);
        Heapify(a,largest,n);
    }
}

void BuildMaxHeap(vector<int>&a, int n){
    //Step down
    //Elements after index n/2-1 will not be having any child node for sure
    for(int i=n/2-1;i>=0;i--){
        Heapify(a,i,n);
    }
}

int heightOfHeap(vector<int>a,int n){
    //COUNTS HEIGHT BY COUNTING NUMBER OF EDGES TO LEAF NODE
    if(n==1) return 1;
    int height=0;
    while(n!=1){
        n=n/2;
        height++;
    }
    return height;
}

int MinimumCostOfRupee(vector<int>arr,int n){
    //GREEDY APPROACH
    priority_queue<long long,vector<long long>,greater<long long>>p;                            
        for(long long i=0;i<arr.size();i++){
            p.push(arr[i]);
        }
        
        long long cost=0;
        while(p.size()>1){
            long long a=p.top(); p.pop();
            a+=p.top(); p.pop();
            cost+=a;
            p.push(a);
        }
        return cost;
}

int main(){
    vector<int>a={4,2,7,6,9};
    // BuildMaxHeap(a,a.size());
    sort(a.begin(),a.end(),greater<int>());
    // cout<<heightOfHeap(a,a.size());
    cout<<MinimumCostOfRupee(a,a.size());

    return 0;
}