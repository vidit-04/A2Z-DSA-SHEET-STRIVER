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

int MinimumCostOfRope(vector<int>arr,int n){
    //GREEDY APPROACH
    //We will always pick two smallest ropes and join them
    //We will use min heap to get smallest ropes
    //We will keep adding the cost of joining two ropes and keep adding the new rope to heap
    //We will keep doing this until we have only one rope left
    //We will return the cost of joining all ropes
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

int MagicianAndChoclates(vector<int>a,int k){
    //Sorting Method
    //BRUTE FORCE
    sort(a.begin(),a.end());
    int n=a.size();
    int ans=0;
    while(k--){
        ans+=a[n-1];
        int target=a[n-1];
        int low=0;
        int high=n-2;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(a[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

    }
    return ans;
    //T.C.-O(k*n+nlogn)
    //S.C.-O(1)
}

int MagicianAndChoclatesApproach2(vector<int>a,int k){
    //BETTER SOLUTION
    int ans=0;
    int n=a.size();
    while(k--){
        int maxEl=INT_MIN;
        int maxInd=-1;
        for(int i=0;i<n;i++){
            if(a[i]>maxEl){
                maxEl=a[i];
                maxInd=i;
            }
        }
        ans+=maxEl;
        a[maxInd]=maxEl/2;
    }
    return ans;
    //T.C.-O(k*n)
    //S.C.-O(1)
}

int MagicianAndChoclatesApproach3(vector<int>a,int k){
    //Greedy Approach
    //We will always pick the chocolate with maximum sweetness
    //We will keep adding the sweetness to the result
    //We will keep dividing the sweetness by 2 and keep adding the new sweetness to heap
    //We will keep doing this until we have k-time left
    //We will return the result
    priority_queue<int>p;
    int ans=0;
    for(int i=0;i<a.size();i++){
        p.push(a[i]);
    }
    while(k-- && !p.empty()){
        int maxEl=p.top(); p.pop();
        if(maxEl/2) p.push(maxEl/2);
        ans+=maxEl;
    }
    return ans;
    //T.C.-O(nlogn+klogn)
    //S.C.-O(n)
}

int LastStoneWeight(vector<int>a){
    //GREEDY APPROACH
    //We will keep subtracting the two largest stones to the heap
    //We will keep adding the new stone to the heap of the difference oof choices done before
    //We will keep doing this until we have only one stone left
    //We will return the last stone
    priority_queue<int>p;
    for(int i=0;i<a.size();i++){
        p.push(a[i]);
    }
    while(p.size()>1){
        int a=p.top();p.pop();
        int b=p.top();p.pop();
        if(a!=b){
            p.push(abs(a-b));
        }
    }
    return p.empty()?0:p.top();
    //T.C.-O((n-1)*3logn)
    //S.C.-O(n)
}

int ProfitMaximization(vector<int>a,int k){
    //GREEDY APPROACH
    //We will keep subtracting the largest element from the heap
    //We will keep adding the new element to the heap 
    //We will keep doing this until we have k-time left
    //We will return the result
    priority_queue<int>p;
    for(int i=0;i<a.size();i++){
        p.push(a[i]);
    }
    int ans=0;
    while(k-- && !p.empty()){
        int maxEl=p.top(); p.pop();
        ans+=maxEl;

        if(maxEl-1) p.push(maxEl-1);
    }
    return ans;
    //T.C.-O(nlogn+klogn)
    //S.C.-O(n)
}

int main(){
    // vector<int>a={4,2,7,6,9};
    // // BuildMaxHeap(a,a.size());
    // sort(a.begin(),a.end(),greater<int>());
    // // cout<<heightOfHeap(a,a.size());
    // cout<<MinimumCostOfRope(a,a.size());


    // Magician And Choclates
    // vector<int>a={2,4,8,6,10};
    // int time=5;
    // cout<<MagicianAndChoclatesApproach3(a,time)<<endl;

    //STL OF HEAP TAKES- O(nlog n ) time to create heap while normal method take 
    //O(n) time to create heap

    //If the question asks about :
    //Only use array when access the element then delete the element because sorting takes O(nlogn ) time
    //If we have to access the element then insert it back in the sorted order then it takes O(logn)+O(logn) time for both

    //Last Stone Weight
    // vector<int>a={2,7,4,1,8,1};
    // // vector<int>a={2,2};
    // cout<<LastStoneWeight(a);


    //PROFIT MAXIMIZATION
    vector<int>a={6,4,2,3};
    int seats=5;
    cout<<ProfitMaximization(a,seats);
    return 0;
}