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

Node* MergeKSortedLists(vector<Node*> arr){
    //BRUTE FORCE
    vector<int>a;
    for (auto it:arr) {
        Node* head = it;
        while (head != nullptr) {
            a.push_back(head->data);
            head = head->next;
        }
    }
    sort(a.begin(),a.end());
    Node* head = convertArr2LL(a);
    return head;
    //T.C.-O(N*KlogN*K)+O(N*K)+O(n2)+O(N)
    //S.C.-O(n)
}

Node* MergingTwoLists(Node* list1,Node* list2){
    Node* dummyNode=new Node(-1);
    Node* temp=dummyNode;

    while(list1!=NULL && list2!=NULL){
        if(list1->data<list2->data){
            temp->next=list1;
            temp=list1;
            list1=list1->next;
        }
        else{
            temp->next=list2;
            temp=list2;  
            list2=list2->next;
        }
    }
    if(list1) temp->next=list1;
    else temp->next=list2;

    return dummyNode->next;
    //T.C.-O(n+m)
    //S.C.-O(1)
}

Node* MergeKSortedListsApproach2(vector<Node*> arr){
    //BETTER SOLUTION
    Node* head=arr[0];
    for(int i=1;i<arr.size();i++){
        head=MergingTwoLists(head,arr[i]);
    }
    return head;
    //T.C.-O(N*K)+O(N*K)+O(n2)+O(N)
    //S.C.-O(n)
}

Node* MergeKSortedListsApproach2(vector<Node*> arr){
    //OPTIMAL SOLUTION
    if(arr.size()==0) return nullptr;
    if(arr.size()==1) return arr[0];
    priority_queue<int,Node*>pq;
    for(int i=0;i<arr.size();i++){
        pq.emplace(arr[i]->data,arr[i]);
    }
    Node* DummyNode=new Node(-1);
    Node* temp=DummyNode;
    while(!pq.empty()){
        pair<int,Node*>p=pq.top();
        temp->next=p.second;
        pq.pop();
        if(p.second->next) pq.emplace(p.second->next->data,p.second->next);
        temp=temp->next;
    }
    return DummyNode->next;
    //T.C.-O(KlogK)+O(N*Klogk)+O(n2)+O(N)
    //S.C.-O(n)
}

int main(){
    
    return 0;
}