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

Node* findKthNode(Node* temp,int k){
    k-=1;
    while(temp!=NULL && k>0){
        k--;
        temp=temp->next;
    }
    return temp;
}

Node* ReverseNodeInKGroups(Node* head, int k){
    Node* temp=head;
    Node* prevNode=NULL;
    while(temp!=NULL){
        Node* KthNode=findKthNode(temp,k);
        if(KthNode==NULL){
            if(prevNode) prevNode->next=temp;
            break;
        }
        Node* nextNode=KthNode->next;
        KthNode->next=NULL;
        reverseLLApproach2(temp);
        if(temp==head){
            head=KthNode;
        }
        else{
            prevNode->next=KthNode;
        }
        prevNode=temp;
        temp=nextNode;
    }
    return head;
    //T.C.-O(n)
    //S.C.-O(1)
}

int main(){
    vector<int>a={1,2,3,4,5,6,7,8,9,10};
    Node* head=convertArr2LL(a);
    printingLL(head);
    cout<<endl;
    head=ReverseNodeInKGroups(head,3);
    printingLL(head);
    return 0;
}