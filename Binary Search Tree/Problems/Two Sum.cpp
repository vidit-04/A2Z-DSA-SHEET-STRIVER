#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};

class BSTIterator{
    stack<Node*>st;
    bool reverse=true;
    //reverse= true means we are doing inorder traversal in reverse order (before)
    //reverse= false means we are doing inorder traversal in normal order (next)
public:
    BSTIterator(Node* root,bool isReverse){
        reverse=isReverse;
        pushAll(root);
    }
    void pushAll(Node* root){
        while(root){
           st.push(root);
           if(reverse) root=root->right;
           else root=root->left;
        }
    }
    bool hasNext(){
        return !st.empty();
    }
    int next(){
        Node* top=st.top();
        st.pop();
        pushAll(reverse?top->left:top->right);
        return top->data;
    }

};

bool findTarget(Node* root, int target){
    if(!root) return false;

    BSTIterator l(root,false);
    BSTIterator r(root,true);
    int i=l.next();
    int j=r.next();

    while(i<j){
        if(i+j==target) return true;
        else if(i+j<target) i=l.next();
        else j=r.next();
    }
    return false;
    //T.C.-O(n) S.C.-O(n)
}

int main(){
    Node* root=new Node(7);
    root->left=new Node(3);
    root->right=new Node(10);
    root->left->left=new Node(2);
    root->left->right=new Node(6);
    root->right->left=new Node(9);
    root->right->right=new Node(11);
    root->left->left->left=new Node(1);
    root->left->right->left=new Node(5);
    root->left->right->right->right=new Node(4);
    root->right->left->left=new Node(8);
    
    int target=11;

    return 0;
}