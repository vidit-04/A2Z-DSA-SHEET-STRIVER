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

int ceilInBST(Node* root,int key){
    if(root==NULL) return -1;
    int ceil=-1;
    while(root){
        if(root->data==key) {
            ceil=root->data;
            return ceil;
        }
        else if(root->data > key) {
            ceil=root->data;
            root=root->left;
        }
        else root=root->right;
    }
    return ceil;
    //T.C.-O(h) S.C.-O(1)
}

int main(){
    Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(13);  
    root->right->left=new Node(11);
    root->right->right=new Node(14);
    root->left->left=new Node(3);
    root->left->right=new Node(6);
    root->left->right->right=new Node(9);
    root->left->left->left=new Node(2);
    root->left->left->right=new Node(4);

    //Ceil in BST
    int key=8;
    cout<<ceilInBST(root,key);

    return 0;
}