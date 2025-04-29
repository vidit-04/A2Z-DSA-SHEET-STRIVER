#include<bits/stdc++.h>
using namespace std;

class Queue{
public:
    int size = 10;
    int q[10];
    int currSize = 0;
    int start = -1;
    int end = -1;

    void push(int x) {
        if(currSize == size) return;
        if(currSize == 0) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % size;
        }
        q[end] = x;
        currSize++;
    }

    int pop() {
        if(currSize == 0) return -1;  // Returning -1 when queue is empty
        int el = q[start];
        if(currSize == 1) {
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % size;
        }
        currSize--;
        return el;
    }

    int front() {
        if(currSize == 0) return -1;  // Returning -1 when queue is empty
        return q[start];
    }

    int sizeQ() {  // Renamed to avoid conflict with the member variable 'size'
        return currSize;
    }
};


// int arr[5];
// int front=0;
// int rear=0;
// int cnt=0; 
// int n=5;

// void push(int x){
//     if(cnt==n) return;
//     arr[rear%n]=x;
//     rear++;
//     cnt++;
// }

// void pop(){
//     if(cnt==0) return;
//     arr[front%n]=-1;
//     front++;
//     cnt--;
// }

// int frontPrint(){
//     if(cnt==0) return -1;
//     return arr[front%n];
// }

// int size(){
//     return cnt;
// }

int main(){
    //Implement Queue using Arrays
    //Enqueue Operation
    // push(5);
    // push(6);
    // push(7);
    // push(8);
    // push(9);
    // for(int i=front;i<rear;i++){
    //     cout<<arr[i%n]<<" ";
    // }
    // cout<<endl;
    // //Dequeue Operation
    // pop();
    // push(10);
    // for(int i=front;i<rear;i++){
    //     cout<<arr[i%n]<<" ";
    // }
    // cout<<front;    
    // cout<<endl;
    // //Front Operation
    // cout<<frontPrint()<<endl;
    // //Size Operation
    // cout<<size()<<endl;
    

    Queue q;
    q.push(7);
    q.push(8);
    q.push(9);
    q.pop();
    for(int i = q.start; i != q.end; i = (i + 1) % q.size) {
        cout << q.q[i] << " ";
    }
    cout << q.q[q.end] << endl; 
    cout << q.front() << endl;

    // Size Operation
    cout << q.sizeQ() << endl;
    return 0;
}