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

Node* reverseLLApproach2(Node* head){
    //OPTIMAL SOLUTION
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
    //T.C.-O(n)
    //S.C.-O(1)
}

Node* Add1toLL(Node* head){
    //BRUTE FORCE
    int carry=1;
    head=reverseLLApproach2(head);
    Node* temp=head;
    temp->data=temp->data+carry;
    while(carry!=0 && temp!=NULL){
        if(temp->data<10){
            carry=0;
            break;
        }
        else{
            temp->data=0;
            carry=1;
        }
        temp=temp->next;
    }
    if(carry==1){
        Node* newNode=new Node(1);
        head=reverseLLApproach2(head);
        newNode->next=head;
        return newNode; 
    }
    head=reverseLLApproach2(head);
    return head;
    //T.C.-O(3N)
    //S.C.-O(1)
}

int addhelper(Node* temp){
    if(temp==NULL) return 1;
    int carry=addhelper(temp->next);
    temp->data=temp->data+carry;

    if(temp->data<10) return 0;
    temp->data=0;
    return 1;
}

Node* Add1toLLApproach2(Node* head){
    int carry=1;
    carry=addhelper(head);
    if(carry==1){
        Node* newNode=new Node(1);
        newNode->next=head;
        return newNode;
    }
    return head;
}

int main(){
    vector<int>a={9,9,9};
    Node* head=convertArr2LL(a);
    head=Add1toLLApproach2(head);
    printingLL(head);
    return 0;
}