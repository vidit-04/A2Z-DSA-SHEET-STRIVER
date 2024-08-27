#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1, Node* next1, Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node* createDLL(vector<int>a){
    Node* head=new Node(a[0]);
    Node* back=head;
    for(int i=1;i<a.size();i++){
        Node* temp=new Node(a[i],nullptr,back);
        back->next=temp;
        back=temp;
    }
    return head;
}

void printingLL(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node* DeleteOccurencesOfKeyInLL(Node* head, int key){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            if(temp==head){
                head=head->next;
                
            }
            Node* back=temp->prev;
            Node* front=temp->next;

            if(front) front->prev=back;
            if(back) back->next=front;
            Node* deleteNode=temp;
            delete temp;
            temp=front;
        }
        else temp=temp->next;
    }
    return head;
}

int main(){
    vector<int>a={10,4,10,6,10};
    Node* head=createDLL(a);
    head=DeleteOccurencesOfKeyInLL(head,10);
    printingLL(head);

    return 0;
}