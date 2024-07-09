#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* random;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
        random = nullptr;
    }

};

Node* CloneALLWithNextAndRandomPointers(Node* head){
    //BRUTE FORCE
    Node* temp=head;
    map<Node*,Node*>mpp;
    while(temp!=NULL){
        Node* newNode=new Node(temp->data);
        mpp[temp]=newNode;
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        Node* copyNode=mpp[temp];
        copyNode->next=mpp[temp->next];
        copyNode->random=mpp[temp->random];
        temp=temp->next;
    }
    return mpp[head];
    //T.C.-O(2N)
    //S.C.-O(N)
}

void InsertCopyNodesInBetween(Node* head){
    Node* temp=head;
    //INSERTING COPY NODES IN BEETWEEN 
    while(temp!=NULL){
        Node* nextNode=temp->next;
        Node* copyNode=new Node(temp->data);
        copyNode->next=nextNode;
        temp->next=copyNode;
        temp=nextNode;
    }
}

void ConnectRandomPointers(Node* head){
    Node* temp=head;
    //CONNECT RANDOM POINTERS
    while(temp!=nullptr){
        Node* copyNode=temp->next;
        if(temp->random!=nullptr){
            copyNode->random=temp->random->next;
        }
        else{
            copyNode->random=nullptr;
        }
        temp=temp->next->next;
    }
}

Node* getDeepCopyList(Node* head){
    Node* temp=head;
    Node* DummyNode=new Node(-1);
    Node* res=DummyNode;
    while(temp!=NULL){
        //Creating New List
        res->next=temp->next;
        res=res->next;

        //Disconnecting and going back to
        //initial state of LL
        temp->next=temp->next->next;
        temp=temp->next;
    }
    return DummyNode->next;
}

Node* CloneALLWithNextAndRandomPointers(Node* head){
    //OPTIMAL SOLUTION
    if(head==nullptr) return head;
    InsertCopyNodesInBetween(head);
    ConnectRandomPointers(head);
    return getDeepCopyList(head);
}

int main(){
    
    return 0;
}