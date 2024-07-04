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

Node* SortLLOf0s1s2s(Node* head){
    //Brute Force
    //Count 0s 1s and 2s then replace them in original LL
    if(head==NULL || head->next==NULL) return head;
    int count0=0,count1=0,count2=0;
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==0) count0++;
        else if(temp->data==1) count1++;
        else count2++;
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(count0>0){
            temp->data=0;
            count0--;
        }
        else if(count1>0){
            temp->data=1;
            count1--;
        }
        else{
            temp->data=2;
            count2--;
        }
        temp=temp->next;
    }
    return head;
    //T.C.-O(2n)
    //S.C.-O(1)
}

Node* SortLLOf0s1s2sApproach2(Node* head){
    //Optimal Solution
    //Create 3 dummy nodes to store 0s,1s and 2s
    //Then merge them
    if(head==NULL || head->next==NULL) return head;

    Node* zeroHead=new Node(-1);
    Node* zero=zeroHead;
    Node* oneHead=new Node(-1);
    Node* one=oneHead;
    Node* twoHead=new Node(-1);
    Node* two=twoHead;

    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            zero->next=temp;
            zero=temp;
        }
        else if(temp->data==1){
            one->next=temp;
            one=temp;
        }
        else{
            two->next=temp;
            two=temp;
        }
        temp=temp->next;
    }
    zero->next=oneHead->next?oneHead->next:twoHead->next;
    one->next=twoHead->next;
    two->next=NULL;
    return zeroHead->next;
    //T.C.-O(n)
    //S.C.-O(1)
}

int main(){
    vector<int>a={1,0,1,2,0,2,1};
    Node* head=convertArr2LL(a);
    head=SortLLOf0s1s2sApproach2(head);
    printingLL(head);
    return 0;
}