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
    Node* top;
    int size;
    public:
    void push(int x){
        Node* temp= new Node(x);
        temp->next=top;
        top=temp;
        size++;
    }
    void pop(){
        if(top==nullptr){
            cout<<"Stack is empty"<<endl;
            return;
        }
        Node* temp=top;
        top=top->next;
        delete temp;
        size--;
    }
    int peek(){
        if(top==nullptr){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return top->data;
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    return 0;
}