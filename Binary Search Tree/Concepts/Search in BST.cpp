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

Node* SearchRecursive(Node* root, int val){
    if(root==NULL) return NULL;
    if(root->data==val) return root;
    if(root->data>val) return SearchRecursive(root->left,val);
    else return SearchRecursive(root->right,val);
    //T.C.-O(logn) S.C.-O(log n)
}

Node* Searchiterative(Node* root, int val){
    while(root!=NULL && root->data!=val){
        root=root->data>val?root->left:root->right;    
    }
    return root;
    //T.C.-O(logn) S.C.-O(1)
}

int main(){
    Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(15);
    root->right->left=new Node(12);
    root->right->right=new Node(18);
    root->left->left=new Node(3);
    root->left->right=new Node(7);

    //Search in BST
    // Node* ans=SearchRecursive(root,1);
    Node* ans=Searchiterative(root,15);
    if(ans==NULL) cout<<"Not Found";
    else cout<<"Found : "<<ans->data;
    return 0;
}