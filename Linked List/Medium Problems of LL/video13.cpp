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

int LengthOfLL(Node* head){
    int len=0;
    Node* temp=head;
    while(temp){
        len++;
        temp=temp->next;
    }
    return len;
}

Node* IntersectionNodeApproach2(Node* head1,Node* head2){
    //Better Approach
    int len1=LengthOfLL(head1);
    int len2=LengthOfLL(head2);
    Node* temp1=head1;
    Node* temp2=head2;
    if(len1>len2){
        int diff=len1-len2;
        while(diff--){
            temp1=temp1->next;
        }
    }
    else{
        int diff=len2-len1;
        while(diff--){
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL && temp2!=NULL){
        if(temp1==temp2) return temp1;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return NULL;
    //T.C.-O(N1+N2)
    //S.C.-O(1)
}

Node* IntersectionNodeApproach3(Node* head1,Node* head2){
    Node* t1=head1;
    Node* t2=head2;
    while(t1!=t2){
        t1=t1->next;
        t2=t2->next;
        if(t1==t2) return t1;
        if(t1==NULL) t1=head2;
        if(t2==NULL) t2=head1;
    }
    return t1;
    //T.C.-O(N1+N2)
    //S.C.-O(1)
}

int main(){
    
    return 0;
}