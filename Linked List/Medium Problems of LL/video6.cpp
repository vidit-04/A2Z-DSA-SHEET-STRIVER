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

Node* Add2Numbers(Node* nums1,Node* nums2){
    Node* DummyNode=new Node(-1);  //It's better to create a dummy node because otherwise we need to write some conditions to make head in ans LL.
    Node* curr=DummyNode;
    int carry=0;
    Node* temp1=nums1;
    Node* temp2=nums2;
    //Just add the adjascent nodes of both LL then insert in new LL then just maintain carry.
    while(temp1!=NULL || temp2!=NULL){
        int sum=carry;
        if(temp1) sum+=temp1->data;
        if(temp2) sum+=temp2->data;
        carry = sum / 10;
        
        Node* newNode=new Node(sum%10);
        curr->next=newNode;
        curr=curr->next;

        if(temp1) temp1=temp1->next;
        if(temp2) temp2=temp2->next;
    }
    //After last there may be carry there so to manage that we need this condition
    if(carry){
        Node* newNode=new Node(carry);
        curr->next=newNode;
    }
    return DummyNode->next;
    //T.C.-O(max(nums1,nums2))
    //S.C.-O(max(nums1,nums2))
}

int main(){
    //9954+53=10007

    vector<int>a={3,5};
    vector<int>b={4,5,9,9};

    Node* nums1=convertArr2LL(a);
    Node* nums2=convertArr2LL(b);
    Node* ans=Add2Numbers(nums1,nums2);
    printingLL(ans);
    return 0;
}