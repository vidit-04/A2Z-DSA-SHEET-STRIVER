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

int FloorInBST(Node* root,int key){
    if(root==NULL) return -1;
    int ceil=-1;
    while(root){
        if(root->data==key){
            ceil=root->data;
            return ceil;
        }
        else if(root->data> key){
            root=root->left;
        }
        else{
            ceil=root->data;
            root=root->right;
        }
    }
    return ceil;
    //T.C.-O(h) S.C.-O(1)
}

int main(){
    Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(15);
    root->left->left=new Node(2);
    root->left->right=new Node(6);

    int key=14;
    cout<<FloorInBST(root,key);
    return 0;
}