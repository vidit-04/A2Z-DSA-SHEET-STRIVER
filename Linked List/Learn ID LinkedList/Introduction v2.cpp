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

int LengthOfLL(Node* head){
    int len=0;
    Node* temp=head;
    while(temp){
        len++;
        temp=temp->next;
    }
    return len;
}

bool SearchElementInLL(Node* head, int target){
    Node* temp=head;
    while(temp!=nullptr){
        if(temp->data==target) return true;
        temp=temp->next;
    }
    return false;
}

int main(){
    vector<int>arr={12,5,7,8};
    // Node* y= new Node(arr[0],nullptr);
    // cout<<y.data;
    // cout<<y->data;

    Node* head= convertArr2LL(arr);
    // cout<<head->data;
    printingLL(head);
    cout<<endl;
    cout<<LengthOfLL(head);
    cout<<endl;
    cout<<SearchElementInLL(head, 7);    
    return 0;
}