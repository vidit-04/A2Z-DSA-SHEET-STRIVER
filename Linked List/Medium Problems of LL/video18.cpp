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

Node* LoopStartingNodeinLL(Node* head){
    //HASHING    
    map<Node*,int>mpp;
    Node* temp=head;
    while(temp!=NULL){
        if(mpp.find(temp)==mpp.end()){
            mpp[temp]=1;
        }
        else return temp;
        temp=temp->next;
    }
    return NULL;
    //T.C.-O(n*2*logn)
    //S.C.-O(n)
}

Node* LoopStartingNodeinLLApproach2(Node* head){
    //OPTIMAL SOLUTION
    //Tortoise and Hare Algorithm
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!= NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow; //Starting Point
        }
    }
    return NULL;
}


int main(){
    
    return 0;
}