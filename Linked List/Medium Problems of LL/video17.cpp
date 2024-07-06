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
    //T.C.-O(n)
    //S.C.-O(1)
}

Node* deleteMiddleElementOfLL(Node* head){
    //BRUTE FORCE
    //FIND LENGTH
    Node* temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    int cnt=len/2;
    temp=head;
    while (cnt--){
        temp=temp->next;
    }
    Node* middle=temp->next;
    temp->next=temp->next->next;
    delete middle;
    return head;
    //T.C.-O(n+n/2)
    //S.C.-O(1)
}

Node* deleteMiddleElementOfLLApproach2(Node* head){
    //OPTIMAL APPROACH
    //TORTOISE AND HARE ALGORITHM TO REACH ONE ELEMENT BEFORE MIDDLE ELEMENT TO DELETE IT
    if(head==NULL || head->next==NULL) return NULL;
    Node* slow=head;
    Node* fast=head;
    fast=fast->next->next; //SKIP 1 iteration of slow
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* middle=slow->next;
    slow->next=slow->next->next;
    delete middle;
    return head;
    //T.C.-O(n/2)
    //S.C.-O(1)
}

int main(){
    
    return 0;
}