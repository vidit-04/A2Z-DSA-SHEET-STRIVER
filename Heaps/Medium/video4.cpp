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

int SumOfElementBtwnK1SmallestAndK2SmallestElement(vector<int>b,int k1,int k2){
    // Using Sorting Method
    sort(b.begin(),b.end());
    int sum=0;
    for(int i=k1;i<k2-1;i++){
        sum+=b[i];
    }
    return sum;
    //T.C.-O(nlog n+(k2-k1))
    //S.C.-O(1)
}

int SumOfElementBtwnK1SmallestAndK2SmallestElementApproach2(vector<int>b,int k1,int k2){
    //USING MAX HEAP
    priority_queue<int> p1;
    for(int i=0;i<k1;i++){
        p1.push(b[i]);
    }
    for(int i=k1;i<b.size();i++){
        if(b[i]<p1.top()){
            p1.pop();
            p1.push(b[i]);
        }
    }

    priority_queue<int> p2;
    k2--;
    for(int i=0;i<k2;i++){
        p2.push(b[i]);
    }
    for(int i=k2;i<b.size();i++){
        if(b[i]<p2.top()){
            p2.pop();
            p2.push(b[i]);
        }
    }
    int sum1=0;
    while(!p1.empty()){
        cout<<p1.top()<<" ";
        sum1+=p1.top();
        p1.pop();
    }
    cout<<endl;
    int sum2=0;
    while(!p2.empty()){
        cout<<p2.top()<<" ";
        sum2+=p2.top();
        p2.pop();
    }
    cout<<endl;
    return sum2-sum1;
    //T.C.-O(nlog k1+nlog k2)
    //S.C.-O(k1+k2)
}

int main(){
    // Kth Smallest Element
    vector<int>a={10,3,7,4,8,9,2,6};
    int k=4;
    cout<<KthSmallestElementApproach3(a,k)<<endl;
    cout<<KthLargestElementApproach3(a,k)<<endl;


    // Sum Of Element Btwn K1 Smallest And K2 Smallest Element
    vector<int>b={20,8,22,4,12,10,14};
    int k1=3;
    int k2=6;
    cout<<SumOfElementBtwnK1SmallestAndK2SmallestElementApproach2(b,k1,k2)<<endl;

    

    return 0;
}