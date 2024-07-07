#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* child;

    public:
    Node(int data1, Node* next1,Node* child1){
        data = data1;
        next = next1;
        child = child1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
        child = nullptr;
    }

};

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->child = temp; 
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

Node* FlatteningLL(Node* head){
    Node* temp1=head;
    vector<int>arr;
    while(temp1!=NULL){
        arr.push_back(temp1->data);
        Node* temp2=temp1->child;
        while(temp2!=NULL){
            arr.push_back(temp2->data);
            temp2=temp2->child;
        }
        temp1=temp1->next;
    }
    sort(arr.begin(),arr.end());
    
    return convertArr2LL(arr);
    //T.C.-O(n*m*2)
    //S.C.-O(n*m*2)
}

Node* MergingTwoLists(Node* list1,Node* list2){
    Node* dummyNode=new Node(-1);
    Node* temp=dummyNode;

    while(list1!=NULL && list2!=NULL){
        if(list1->data<=list2->data){
            temp->child=list1;
            temp=list1;
            list1=list1->next;
        }
        else{
            temp->next=list2;
            temp=list2;  
            list2=list2->next;
        }
        temp->next=NULL;
    }
    if(list1) temp->child=list1;
    else temp->child=list2;
    return dummyNode->child;
}

Node* FlatteningLL(Node* head){
    //OPTIMAL SOLUTION
}

int main(){
    
    return 0;
}