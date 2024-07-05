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

Node* MiddleNode(Node* head){
    //BRUTE FORCE
    if(head==NULL || head->next==NULL) return head;
    Node* temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    temp=head;
    int mid=(len/2)+1;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(mid==cnt) break;
        temp=temp->next;
    }
    return temp;
}

Node* MiddleNodeApproach2(Node* head){
    //OPTIMAL Approach
    //TORTOISE AND HARE ALGORITHM

    if(head==NULL || head->next==NULL) return head;
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

int main(){
    vector<int>a={1,2,3,4,5,6,7,8,9};
    Node* head=convertArr2LL(a);
    printingLL(head);   
    cout<<endl;
    Node* mid=MiddleNodeApproach2(head);
    cout<<mid->data<<endl;
    return 0;
}