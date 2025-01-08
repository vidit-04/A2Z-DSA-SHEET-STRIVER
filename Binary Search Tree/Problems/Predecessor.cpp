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

Node* Successor(Node* root,int key){
    if(root==NULL) return NULL;
    Node* ans=NULL;
    Node* curr=root;
    while(curr){
        if(curr->data>key){
            ans=curr;
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
    }
    return ans;
    //T.C.=O(h) where h is the height of the tree
}

Node* Predecessor(Node* root,int key){
    if(root==NULL) return NULL;
    Node* ans=NULL;
    Node* curr=root;
    while(curr){
        if(curr->data<key){
            ans=curr;
            curr=curr->right;
        }
        else{
            curr=curr->left;
        }
    }
    return ans;
    //T.C.=O(h) where h is the height of the tree
}

int main(){
    //Successor of a number means a number that is just greater than the given number
    //Predecessor of a number means a number that is just smaller than the given number
    Node* root=new Node(5);  
    root->left=new Node(3);
    root->right=new Node(7);
    root->left->left=new Node(2);
    root->left->right=new Node(4);
    root->right->left=new Node(6);
    root->right->right=new Node(9);
    root->right->right->left=new Node(8);
    root->right->right->right=new Node(10);
    root->left->left->left=new Node(1);
    int key=8;


    cout<<Successor(root,key)->data<<endl;
    cout<<Predecessor(root,key)->data<<endl;
    return 0;
}