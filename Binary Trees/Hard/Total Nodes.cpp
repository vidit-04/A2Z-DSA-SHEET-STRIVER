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

void inorder(Node* root, int& count){
    if(root==NULL) return;
    count++;
    inorder(root->left,count);
    inorder(root->right,count);
    //T.C.-O(n)
    //S.C.-O(h)
}

int LeftHeight(Node* root){
    int count=0;
    while(root!=NULL){
        count++;
        root=root->left;
    }
    return count;
}
int RightHeight(Node* root){
    int count=0;
    while(root!=NULL){
        count++;
        root=root->right;
    }
    return count;
}

int countNodes(Node* root){
    if(root==NULL) return 0;
    int lh=LeftHeight(root);
    int rh=RightHeight(root);
    if(lh==rh) return (1<<lh)-1;
    return 1+countNodes(root->left)+countNodes(root->right);
    //T.C.-O(logn*logn)
    //S.C.-O(h)
}   


int main(){
    //WE NEED TO SOLVE IT IN LESS THAN O(N) TIME FOR COMPLETE BINARY TREE
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);  
    // int count=0;
    // inorder(root,count);
    // cout<<count;

    cout<<countNodes(root);
    return 0;
}