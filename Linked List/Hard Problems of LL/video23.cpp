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

Node* findNthNode(Node* head,int k){
    Node* temp=head;
    k-=1;
    while(k--){
        temp=temp->next;
    }
    return temp;
}

Node* RotateLLKTimes(Node* head, int k){
    if(head==NULL || head->next==NULL) return head;
    int len=1;
    Node* tail=head;
    while(tail->next!=NULL){
        len++;
        tail=tail->next;
    }
    if(k%len==0) return head;
    k=k%len;
    tail->next=head;
    Node* newLastNode=findNthNode(head,len-k);
    head=newLastNode->next;
    newLastNode->next=NULL;
    return head;
    //T.C.-O(n)
    //S.C.-O(1)
}

int main(){
    vector<int>a={1,2,3,4,5};
    Node* head=convertArr2LL(a);
    printingLL(head);
    cout<<endl;
    head=RotateLLKTimes(head,2);
    printingLL(head);
    return 0;
}