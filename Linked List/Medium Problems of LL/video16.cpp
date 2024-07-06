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

int LengthOfLoopInLL(Node* head){
    //Better Approach
    //HASHING
    map<Node*,int>mpp;
    Node* temp=head;
    int timer=1;
    while(temp!=NULL){
        if(mpp.find(temp)!=mpp.end()){
            return timer-mpp[temp];
        }

        mpp[temp]=timer;
        timer++;
        temp=temp->next;
    }
    return 0; //NO LOOP
    //T.C.-O(n*2*logn)
    //S.C.-O(n)
}

int LengthOfLoopInLL(Node* head){
    //Optimise Approach
    //TORTOISE AND HARE ALGORITHM
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            int cnt=0;
            fast=fast->next;
            while(slow!=fast){
                cnt++;
                fast=fast->next;
            }
            return cnt;
        }
    }
    return 0;
}

int main(){
    
    return 0;
}