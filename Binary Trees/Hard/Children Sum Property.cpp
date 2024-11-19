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

Node* ChildrenSumProperty(Node* root){
    if(root==NULL) return NULL;
    int child=0;
    if(root->left) child+=root->left->data;
    if(root->right) child+=root->right->data;

    if(child>=root->data) root->data=child;
    else{
        if(root->left) root->left->data=root->data;
        else if(root->right) root->right->data=root->data;
    }
    ChildrenSumProperty(root->left);
    ChildrenSumProperty(root->right);
    int tot=0;
    if(root->left) tot+=root->left->data;
    if(root->right) tot+=root->right->data;
    if(root->left || root->right) root->data=tot;
}

int main(){
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(12);
    root->right->left = new Node(3);
    root->right->right = new Node(5);
    root->left->left = new Node(4);
    root->left->right = new Node(4);
    ChildrenSumProperty(root);
    cout<<root->data<<endl;
    return 0;
}