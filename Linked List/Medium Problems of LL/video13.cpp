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
    int mid=(len/1+2)+1;
    while(temp!=NULL){
        mid--;
        if(mid==0) return temp;
    }
    return temp;
}

int main(){
    vector<int>a={1,2,3,4,5,6,7,8,9};
    Node* head=convertArr2LL(a);
    Node* mid=MiddleNode(head);
    cout<<mid->data<<" h";    
   return 0;
}