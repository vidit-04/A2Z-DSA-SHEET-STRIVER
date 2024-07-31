#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }

};

class Stack{
    Node* start;
    Node* end;
    int size=0;
    public:
    void push(int x){
        Node* temp=new Node(x);
        if(start==NULL){
            start=end=temp;
        }
        else{
            end->next=temp;
            end=temp;
        }
        size++;
    }
    void pop(){
        if(start==NULL){
            cout<<"Stack is empty"<<endl;
            return;
        }
        Node* temp=start;
        start=start->next;
        delete temp;
        size--;
    }
    int top(){
        if(start==NULL){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return start->data;
    }
};

int main(){
    
    return 0;
}