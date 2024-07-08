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

Node* SortLL(Node* head){
    //BRUTE FORCE
    vector<int>arr;
    Node* temp=head;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    sort(arr.begin(),arr.end());
    head=convertArr2LL(arr);
    return head;
}

int main(){
    vector<int>a={3,4,2,1,5};
    Node* head=convertArr2LL(a);
    printingLL(head);
    cout<<endl;
    head=SortLL(head);
    printingLL(head);
    return 0;
}