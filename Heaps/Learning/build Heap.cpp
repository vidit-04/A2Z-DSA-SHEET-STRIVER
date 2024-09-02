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

void print(vector<int>a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int>a={10,3,8,9,5,13,18,14,11,70};
    BuildMaxHeap(a,a.size());
    print(a);    
    return 0;
}