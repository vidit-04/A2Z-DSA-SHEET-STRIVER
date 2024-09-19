#include<bits/stdc++.h>
using namespace std;

// struct ListNode {
//     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };
class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int x){
        val=x;
        next=NULL;
    }
};


class compare{
    public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*,vector<ListNode*>,compare> minHeap;
    int k=lists.size();
    for(int i=0;i<k;i++){
        if(lists[i]) minHeap.push(lists[i]);
    }
    ListNode* head=NULL;
    ListNode* tail=NULL;
    while(!minHeap.empty()){
        ListNode* temp= minHeap.top();
        minHeap.pop();
        if(head==NULL){
            head=temp;
            tail=temp;
            if(head->next!=NULL){
                minHeap.push(head->next);
            }
        }
        else{
            tail->next=temp;
            tail=tail->next;
            if(tail->next){
                minHeap.push(tail->next);
            }
        }
    }
    return head;
}

int main(){
    
    return 0;
}