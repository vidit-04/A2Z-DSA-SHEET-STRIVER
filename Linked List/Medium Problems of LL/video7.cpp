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

Node* oddEvenLL(Node*head){
    //BRUTE FORCE
    if(head==NULL || head->next==NULL) return head;
    vector<int>arr; //TO STORE ALL ODDS TOGETHER,THEN ALL EVEN TOGETHER
    Node* temp=head;
    while (temp!=NULL){
        arr.push_back(temp->data);
        if(temp->next==NULL) break;
        temp=temp->next->next;
    }
    temp=head->next;
    while (temp!=NULL){
        arr.push_back(temp->data);
        if(temp->next==NULL) break;
        temp=temp->next->next;
    }

    temp=head;
    int i=0;
    while(temp!=NULL){
        temp->data=arr[i];
        i++;
        temp=temp->next;
    }
    return head;
    //T.C.- O(2n)
    //S.C.- O(n)    
}

Node* oddEvenLLApproach2(Node*head){
    //Optimal Approach
    if(head==NULL || head->next==NULL) return head;
    Node* odd=head;
    Node* even=head->next;
    Node* evenHead=even;

    while(even!=NULL && even->next!=NULL){
        odd->next=odd->next->next;
        even->next=even->next->next;

        odd=odd->next;
        even=even->next;
    }
    odd->next=evenHead;
    return head;
}

int main(){
    vector<int>a={2,3,1,4,5,6};
    Node* head=convertArr2LL(a);
    Node* ans=oddEvenLLApproach2(head);
    printingLL(ans);
    return 0;
}