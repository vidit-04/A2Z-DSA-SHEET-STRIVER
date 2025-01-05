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

void InsertNode(Node* root, int val){
    if(root==NULL){
        root=new Node(val);
        return;
    }
    Node* curr=root;
    while (true) {
        if (curr->data > val) {
            if (curr->left == NULL) {
                curr->left = new Node(val);
                break;
            } else {
                curr = curr->left;
            }
        } else {
            if (curr->right == NULL) {
                curr->right = new Node(val);
                break;
            } else {
                curr = curr->right;
            }
        }
    }

    if(curr->data > val) curr->left=new Node(val);
    else curr->right=new Node(val);
}

void LevelOrderTraversal(Node* root){
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}

int main(){
    Node* root=new Node(4);    
    root->left=new Node(2);
    root->right=new Node(7);
    root->left->left=new Node(1);
    root->left->right=new Node(3);

    InsertNode(root,0);
    LevelOrderTraversal(root);
    return 0;
}