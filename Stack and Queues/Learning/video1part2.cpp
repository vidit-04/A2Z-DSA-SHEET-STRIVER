#include<bits/stdc++.h>
using namespace std;

int arr[5];
int front=0;
int rear=0;
int cnt=0; 
int n=5;

void push(int x){
    if(cnt==n) return;
    arr[rear%n]=x;
    rear++;
    cnt++;
}

void pop(){
    if(cnt==0) return;
    arr[front%n]=-1;
    front++;
    cnt--;
}

int frontPrint(){
    if(cnt==0) return -1;
    return arr[front%n];
}

int size(){
    return cnt;
}

int main(){
    //Implement Queue using Arrays
    //Enqueue Operation
    push(5);
    push(6);
    push(7);
    push(8);
    push(9);
    for(int i=front;i<rear;i++){
        cout<<arr[i%n]<<" ";
    }
    cout<<endl;
    //Dequeue Operation
    pop();
    push(10);
    for(int i=front;i<rear;i++){
        cout<<arr[i%n]<<" ";
    }
    cout<<front;    
    cout<<endl;
    //Front Operation
    cout<<frontPrint()<<endl;
    //Size Operation
    cout<<size()<<endl;
    
    return 0;
}