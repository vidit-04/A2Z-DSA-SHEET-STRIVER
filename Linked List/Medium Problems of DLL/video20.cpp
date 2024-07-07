#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1, Node* next1, Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node* createDLL(vector<int>a){
    Node* head=new Node(a[0]);
    Node* back=head;
    for(int i=1;i<a.size();i++){
        Node* temp=new Node(a[i],nullptr,back);
        back->next=temp;
        back=temp;
    }
    return head;
}

void printingLL(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

vector<pair<int,int>> FindPairOfGivenSum(Node* head,int k){
    //BRUTE FORCE
    vector<pair<int,int>> ans;
    Node* temp1=head;
    while(temp1!=NULL){
        Node* temp2=temp1->next;
        while(temp2!=NULL){
            int sum=temp1->data+temp2->data;
            if(sum==k){
                ans.push_back({temp1->data,temp2->data});
            }
            else if(sum>k) break;
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return ans;
}

int main(){
    vector<int>a={1,2,3,4,9};
    Node* head=createDLL(a);
    printingLL(head);
    cout<<endl;
    vector<pair<int,int>> ans=FindPairOfGivenSum(head,5);
    for(auto i:ans){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}