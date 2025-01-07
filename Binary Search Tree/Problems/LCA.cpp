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

Node* LCA(Node* root, int n1,int n2){
    if(root==NULL) return NULL;
    
    Node* curr=root;
    while(curr){
        int val=curr->data;
        if(val>n1 && val>n2){
            curr=curr->left;
        }
        else if(val<n1 && val<n2){
            curr=curr->right;
        }
        else{
            break;
        }
    }
    return curr;
}

Node* LCARecursive(Node* root,int n1,int n2){
    if(root==NULL) return NULL;
    int val=root->data;
    if(val>n1 && val>n2) return LCARecursive(root->left,n1,n2);
    else if(val<n1 && val<n2) return LCARecursive(root->right,n1,n2);
    else return root;
}

int main(){
    Node* root=new Node(10);  
    root->left=new Node(4);
    root->right=new Node(13);
    root->left->left=new Node(3);
    root->left->right=new Node(8);
    root->right->left=new Node(11);
    root->right->right=new Node(15);
    root->left->left->left=new Node(1);
    root->left->left->left->right=new Node(2);
    root->left->right->left=new Node(6);
    root->left->right->right=new Node(7);
    root->left->right->left=new Node(5);
    root->left->right->right=new Node(9);

    int n1=5,n2=9;
    Node* lca=LCARecursive(root,n1,n2);
    cout<<lca->data;
    return 0;
}