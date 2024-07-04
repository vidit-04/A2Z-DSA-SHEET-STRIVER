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

Node* reverseLL(Node* head){
    //BRUTE FORCE
    stack<int>st;
    Node* temp=head;

    while (temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }   
    temp=head;
    while (temp!=NULL){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
    //T.C.-O(2n)    
    //S.C.-O(n)
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

Node* reverseLLApproach3(Node* head){
    //OPTIMAL SOLUTION-- Recursive
    if(head==NULL || head->next==NULL) return head;

    Node* newHead=reverseLLApproach3(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
    //T.C.-O(n)
    //S.C.-O(1)
}

int main(){
    vector<int>a={1,3,2,5};
    Node* head=convertArr2LL(a);
    printingLL(head);
    cout<<endl;
    head=reverseLLApproach3(head);
    printingLL(head);

    return 0;
}