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

Node* findLastRight(Node* root){
    if(root->right==NULL) return root;
    return findLastRight(root->right);
}

Node* helper(Node* root){
    if(root->left==NULL) return root->right;
    if(root->right==NULL) return root->left;

    Node* rightChild=root->right;
    Node* lastRight=findLastRight(root->left);
    lastRight->right=rightChild;
    return root->left;
}

void DeleteNode(Node* root, int key){
    if(root==NULL) return;
    if(root->data==key){
        helper(root);
        return;
    }
    while(root!=NULL){
        if(root->data>key){
            if(root->left!=NULL && root->left->data==key){
                root->left=helper(root->left);
                return;
            }
            else root=root->left;
        }
        else{
            if(root->right!=NULL && root->right->data==key){
                root->right=helper(root->right);
                return;
            }
            else root=root->right;
        }
    }
    return;
    //T.C=O(h) where h is the height of the tree
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
    Node* root=new Node(9);    
    root->left=new Node(8);
    root->right=new Node(12);
    root->left->left=new Node(5);
    root->right->left=new Node(10);
    root->right->right=new Node(13);
    root->right->left->right=new Node(11);
    root->left->left->left=new Node(3);
    root->left->left->right=new Node(7);
    root->left->left->right->right=new Node(8);
    root->left->left->right->left=new Node(6);
    root->left->left->left->left=new Node(2);
    root->left->left->left->right=new Node(4);
    root->left->left->left->left->left=new Node(1);


    //Delete a Node
    int key=5 ;
    DeleteNode(root,key);
    LevelOrderTraversal(root);
    return 0;
}