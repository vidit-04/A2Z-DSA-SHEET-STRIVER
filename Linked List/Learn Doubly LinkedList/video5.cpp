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

Node* ReverseDLL(Node* head){
    //BRUTE FORCE
    if(head==NULL || head->next==NULL) return head;
    Node* temp=head;
    stack<int>st;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
    //T.C.- O(2n)
    //S.C.- O(n)
}

Node* ReverseDLLApproach2(Node* head){
    //OPTIMIZED
    if(head==NULL || head->next==NULL) return head;
    Node* current=head;
    Node* last=NULL;
    while(current!=NULL){
        last=current->back;
        current->back=current->next;
        current->next=last;
        current=current->back;
    }
    return last->back;
    //T.C.- O(n)
    //S.C.- O(1)

}

int main(){
    vector<int> a={1,2,3,4,5};
    Node* head=createDLL(a);
    printingLL(head);
    cout<<endl;
    head=ReverseDLLApproach2(head);
    printingLL(head);
    return 0;
}