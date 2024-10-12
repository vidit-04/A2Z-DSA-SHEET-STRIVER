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

int maxDepth(Node* root){
    if(root==NULL) return 0;
    int lh=maxDepth(root->left);
    int rh=maxDepth(root->right);
    return 1+max(lh,rh);
    //T.C.-O(n)
    //S.C.-O(n)
}

bool Check(Node* root){
    //Not good because of O(N^2) T.C.
    if(root==NULL) return true;
    int lh=maxDepth(root->left);
    int rh=maxDepth(root->right);
    if(abs(lh-rh)>1) return false;
    return Check(root->left) && Check(root->right);
    //T.C.-O(n^2)
    //S.C.-O(n)
}

int maxDepth2(Node* root){
    if(root==NULL) return 0;

    int leftHeight=maxDepth(root->left);
    if(leftHeight==-1) return -1;

    int rightHeight=maxDepth(root->right);
    if(rightHeight==-1) return -1;

    if(abs(leftHeight-rightHeight)>1) return -1;
    return 1+max(leftHeight,rightHeight);
    //T.C.-O(n)
    //S.C.-O(n)
}

bool Check2(Node* root){
    return maxDepth2(root)!= -1;
    //T.C.-O(n)
    //S.C.-O(n)
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    //Check for Balanced Binary Tree
    //A binary tree is balanced if the height of the left and right subtree of every node differs by at most 1
    if(Check2(root)){
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"Not Balanced"<<endl;
    }
    return 0;
}