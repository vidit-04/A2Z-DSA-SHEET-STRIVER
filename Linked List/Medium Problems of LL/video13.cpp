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

Node* IntersectionNode(Node* head1,Node* head2){
    //BRUTE FORCE
    map<Node*,int>mpp;
    Node* temp=head1;
    while (temp!=NULL){
        mpp[temp]=1;
        temp=temp->next;
    }
    temp=head2;
    while(temp!=NULL){
        if(mpp.find(temp)!=mpp.end()) return temp;
        temp=temp->next;
    }
    return NULL;
    //T.C.-O(N1*logn)+O(N2logn)
    //S.C.-O(N)
}

int main(){
    
    return 0;
}