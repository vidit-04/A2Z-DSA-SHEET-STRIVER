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

bool isLLPalindrome(Node* head){
    //BRUTE FORCE
    stack<int>st;
    Node* temp=head;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(temp->data!=st.top()) return false;
        temp=temp->next;
        st.pop();
    }
    return true;
    //T.C.-O(2N)
    //S.C.-O(N)
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

bool isLLPalindromeApproach2(Node* head){
    //OPTIMAL SOLUTION
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* newHead=reverseLLApproach2(slow->next);
    Node* first=head;
    Node* second=newHead;
    while(second->next!=NULL){
        if(first->data!=second->data){
            reverseLLApproach2(newHead);
            return false;
        }
        first=first->next;
        second=second->next;
    }
    reverseLLApproach2(newHead);
    return true;
    //T.C.-O(2N)
    //S.C.-O(1)
}

int main(){
    vector<int>a={1,2,3,1};
    Node* head=convertArr2LL(a);
    bool ans=isLLPalindrome(head);
    cout<<ans<<endl;
    printingLL(head);

    return 0;
}