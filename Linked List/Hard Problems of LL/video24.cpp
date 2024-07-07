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

Node* MergeTwoSortedLL(Node* head1, Node* head2){
    //BRUTE FORCE
    vector<int>arr;
    Node* temp1=head1;
    Node* temp2=head2;
    while(temp1!=NULL){
        arr.push_back(temp1->data);
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        arr.push_back(temp2->data);
        temp2=temp2->next;
    }
    sort(arr.begin(),arr.end());
    Node* head=convertArr2LL(arr);
    return head;
    //T.C.-O(NlogN)+O(n1)+O(n2)+O(N)
    //S.C.-O(n)
}

Node* MergeTwoSortedLLApproach2(Node* head1, Node* head2){
    Node* temp1=head1;
    Node* temp2=head2;
    Node* dummyNode=new Node(-1);
    Node* temp=dummyNode;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data<=temp2->data){
            temp->next=temp1;
            temp1=temp1->next;
            temp=temp->next;
        }
        else{
            temp->next=temp2;
            temp2=temp2->next;
            temp=temp->next;
        }
    }
    if(temp1!=NULL) temp->next=temp1;
    if(temp2!=NULL) temp->next=temp2;
    return dummyNode->next;
    //T.C.-O(n1+n2)
    //S.C.-O(1)
}

int main(){
    vector<int>a={2,4,8,10};
    vector<int>b={1,3,3,6,11,14};
    Node* head1=convertArr2LL(a);
    Node* head2=convertArr2LL(b);
    printingLL(head1);
    cout<<endl;
    printingLL(head2);
    cout<<endl;
    Node* head=MergeTwoSortedLLApproach2(head1,head2);
    printingLL(head);
    return 0;
}