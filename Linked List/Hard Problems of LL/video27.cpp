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
    temp=head;
    int i=0;
    while(temp!=NULL){
        temp->data=arr[i];
        i++;
        temp=temp->next;
    }
    return head;
    //T.C.-O(nlogn)+O(n)+O(n)
    //S.C.-O(n)
}


// Function to find the middle of the linked list
Node* findMiddle(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* slow = head;
    Node* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to merge two sorted linked lists
Node* merge(Node* list1, Node* list2) {
    Node* dummyNode = new Node(-1);
    Node* current = dummyNode;
    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            current->next = list1;
            current = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            current = list2;
            list2 = list2->next;
        }
    }
    // Append remaining nodes of list1 or list2
    if (list1) {
        current->next = list1;
    } else {
        current->next = list2;
    }
    Node* sortedList = dummyNode->next;
    delete dummyNode;
    return sortedList;
}

// Function to perform merge sort on a linked list
Node* sortLL(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* middle = findMiddle(head);
    Node* leftHead = head;
    Node* rightHead = middle->next;
    middle->next = NULL; // Break the list into two halves
    leftHead = sortLL(leftHead);
    rightHead = sortLL(rightHead);
    return merge(leftHead, rightHead);
    // T.C.-O(logn*(n+n/2))
    // S.C.-O(1)
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