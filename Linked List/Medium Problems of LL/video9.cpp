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

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp; 
        mover = temp;  // mover=mover->next
    }
    return head;
}

void printingLL(Node* head){
    Node*temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


Node* removeNthNodeFromEnd(Node* head, int n){
    //Brute Force
    if(head==NULL) return head;
    Node* temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    // We need not to go to node which is to be deleted but we need to go to node before it
    if(len==n){
        Node* newHead=head->next;
        free(head);
        return newHead;
    }
    int rem=len-n;
    temp=head;
    while(temp!=NULL){
        rem--;
        if(rem==0){
            break;
        } 
        temp=temp->next;
    }
    Node* ddNode=temp->next;
    temp->next=temp->next->next;
    delete ddNode;
    return head;
    //T.C.-O(2n)
    //S.C.-O(1)
}

Node* removeNthNodeFromEndApproach2(Node* head, int n){
    //Optimal Approach
    if(head==NULL) return head;
    Node* fast=head;
    for(int i=0;i<n;i++){
        fast=fast->next;
    }
    if(fast==NULL){
        Node* newHead=head->next;
        delete head;
        return newHead;
    }
    Node* slow=head;
    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    Node* ddNode=slow->next;
    slow->next=slow->next->next;
    delete ddNode;
    return head;
    //T.C.-O(n)
    //S.C.-O(1)

}


int main(){
    vector<int>a={1,2,3,4,5};
    Node* head=convertArr2LL(a);
    head=removeNthNodeFromEndApproach2(head,1);
    printingLL(head);
    return 0;
}