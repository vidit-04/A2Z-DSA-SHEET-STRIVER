#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* createDLL(vector<int>a){
    Node* head=new Node(a[0]);
    Node* prev=head;
    for(int i=1;i<a.size();i++){
        Node* temp=new Node(a[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
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

Node* RemoveHead(Node* head){
    if(head==NULL || head->next==NULL) return head;

    Node* prev=head;
    head=head->next;

    head->back=nullptr;
    prev->next=nullptr;

    delete prev;
    return head;
}

Node* RemoveTail(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node* prev=tail->back;
    prev->next=nullptr;
    tail->back=nullptr;
    delete tail;
    return head;
}

Node* RemoveKth(Node* head,int k){    
    if(head==NULL) return head;
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* front=temp->next;

    if(prev==NULL && front==NULL){
        delete temp;
        return NULL;
    }
    else if(prev==NULL){
        return RemoveHead(head);
    }
    else if(front==NULL){
        return RemoveTail(head);
    }
    prev->next=front;
    front->back=prev;
    temp->next=nullptr;
    temp->back=nullptr;
    delete temp;
    return head;  
}

void deleteEle(Node* temp){
    //You will never be asked to delete head if given then we just need to add conditions.
    // in input it is given the node which is to be deleted
    Node* prev=temp->back;
    Node* front=temp->next;

    if(front==NULL){
        prev->next=nullptr;
        temp->back=nullptr;
        delete temp;
        return;
    }
    prev->next=front;
    front->back=prev;
    temp->next=temp->back=nullptr;
    delete temp;
}

Node* InsertionBeforeHead(Node* head,int val){
    Node* newNode= new Node(val,head,nullptr);
    head->back=newNode;
    return newNode; 
}

Node* InsertBeforeTail(Node* head,int val){
    // If we have only one element then it is only head as well as tail
    if(head->next==NULL) return InsertionBeforeHead(head,val);
    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node* prev=tail->back;
    Node* newNode=new Node(val,tail,prev);
    prev->next=newNode;
    tail->back=newNode;
    return head;
}

Node* InsertBeforeKthPosition(Node* head,int val,int k){
    if(head==NULL) return new Node(val,nullptr,nullptr);
    if(k==1) return InsertionBeforeHead(head,val);

    Node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* newNode=new Node(val,temp,prev);
    prev->next=newNode;
    temp->back=newNode;
    return head;
}

void InsertBeforeEle(Node* temp, int val, int k){
    //Never Insert at head is given
    //Here The node before which we insert is also given
    Node* prev=temp->back;
    Node* newNode=new Node(val,temp,prev);
    temp->back=newNode;
    prev->next=newNode;
}

int main(){
    vector<int>a={1,3,2,4};
    Node* head = createDLL(a);
    printingLL(head);
    cout<<endl;

    //Delete head of DLL
    // head=RemoveHead(head);
    // printingLL(head);

    //Delete tail of DLL
    // head=RemoveTail(head);
    // printingLL(head);

    //Delete Kth element of DLL
    // head=RemoveKth(head,5);
    // printingLL(head);

    //Delete given element of DLL
    // deleteEle(head->next->next->next);
    // printingLL(head);

    //Insertion before head
    // int val=25;
    // head=InsertionBeforeHead(head,val);
    // printingLL(head);

    //Insertion before tail
    // int val=25;
    // head=InsertBeforeTail(head,val);
    // printingLL(head);

    //Insertion at Kth position
    // int val=25;
    // int k=3;
    // head=InsertBeforeKthPosition(head,val,4);
    // printingLL(head);

    //Insertion before given element
    int val=25;
    InsertBeforeEle(head->next->next,val,3);
    printingLL(head);
    return 0;
}