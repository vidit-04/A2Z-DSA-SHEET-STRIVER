#include<bits/stdc++.h>
using namespace std;

class LRUCache{
    public:
        class Node{
            public:
            int key;
            int value;
            Node* next;
            Node* prev;
            Node(int key,int value){
                this->key = key;
                this->value = value;
                next = NULL;
                prev = NULL;
            }
        };
        public:
        Node* head=new Node(-1,-1);
        Node* tail=new Node(-1,-1);
        int capacity;
        unordered_map<int,Node*> m;

        LRUCache(int capacity){
          this->capacity=capacity;
          head->next=tail;
          tail->prev=head;
        }
    void deletionNode(Node* node){
        Node* prevNode=node->prev;
        Node* nextNode=node->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
    void insertionNodeAfterHead(Node* newNode){
        Node* temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
    }
    int get(int key_){
      if(m.find(key_)!=m.end()){
        Node* resNode=m[key_];
        int res=resNode->value;
        m.erase(key_);
        deletionNode(resNode);
        insertionNodeAfterHead(resNode);
        m[key_]=head->next;
        return res;
      }
      return -1;
    }
    void put(int key_, int value) {
    if (m.find(key_) != m.end()) {
      Node * existingnode = m[key_];
      m.erase(key_);
      deletionNode(existingnode);
    }
    if (m.size() == capacity) {
      m.erase(tail -> prev -> key);
      deletionNode(tail -> prev);
    }

    insertionNodeAfterHead(new Node(key_, value));
    m[key_] = head -> next;
  }

};

int main(){
    //LRU CACHE

    return 0;
}