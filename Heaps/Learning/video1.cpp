#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    vector<int> arr;
    int size;  //currently no. of items in heap
    int total_size; //total size

    public: 
    MaxHeap(int size){
        arr.reserve(size);
        this->size=0;
        this->total_size=size;
    }
    void insert(int data){
        //Step up process
        if(size==total_size) return;
        arr[size]=data;
        int index=size;
        size++;

        while(index>0 && arr[index]>arr[(index-1)/2]){
            swap(arr[(index-1)/2],arr[index]);
            index=(index-1)/2;
        }
        return;
        //T.C.-O(logn)
    }
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }
    void Heapify(int index){
        //Step down process
        int largest=index;
        int left=2*index+1;
        int right=2*index+2;

        //Largest will contain that element which is largest among parent, left child, right child.
        if(left<size && arr[left]>arr[largest]){
            largest=left;
        }
        if(right<size && arr[right]>arr[largest]){
            largest=right;
        }
        if(largest!=index){
            swap(arr[largest],arr[index]);
            Heapify(largest);
        }

        
        //T.C.-O(logn)
    }
    void deleteNode(){
        //Step down process
        if(size==0) return;
        arr[0]=arr[size-1];
        arr.pop_back();
        size--;
        Heapify(0);
        //T.C.-O(logn)
    }
};

int main(){
    //INDEX for Parent index is given and you need to get index of its child node. Then formula is:
    //Left Child=2*Parent+1
    //Right Child=2*Parent+2
    //INdex of child is given and we need to find parent in array then its index is found as:
    //Parent=(Left Child-1)/2 or (Right Child-1)/2

    MaxHeap H1(6);
    H1.insert(10);
    H1.insert(20);
    H1.insert(30);
    H1.insert(40);
    H1.insert(50);
    H1.insert(60);
    H1.print();
    cout<<endl;
    // H1.deleteNode();
    // H1.print();
    // cout<<endl;
    // H1.insert(5);
    // H1.print();
    // cout<<endl;
    return 0;
}

// YOUTUBE- CODER ARMY