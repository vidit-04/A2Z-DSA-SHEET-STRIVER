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

Node* removeDuplicatesFromSortedDLL(Node* head){
    //My Approach
    Node* temp=head;
    while(temp!=NULL){
        if(temp==head) temp=temp->next;
        else if(temp->data==temp->prev->data){
            Node* back=temp->prev;
            Node* front=temp->next;
            back->next=temp->next;
            if(front) front->prev=back;
            delete temp;
            temp= front;
        }
        else temp=temp->next;
    }
    return head;
}

Node* removeDuplicatesFromSortedDLLApproach2(Node* head){
    //Optimal Approach same as mine but with a shortcut
    Node* temp=head;
    while(temp!=NULL && temp->next!=NULL){
        Node* nextNode=temp->next;
        while(nextNode!=NULL && nextNode->data==temp->data){
            nextNode=nextNode->next;
        }
        temp->next=nextNode;
        if(nextNode) nextNode->prev=temp;
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int>a={1,1,1,2,3,3,4};
    Node* head=createDLL(a);
    printingLL(head);
    cout<<endl;
    head=removeDuplicatesFromSortedDLLApproach2(head);
    printingLL(head);
    return 0;
}