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

void FlattenRecursiveApproach1(Node* root,Node*& prev){
    //This is done with reverse postorder traversal i.e. right->left->root
    if(root==NULL) return;
    FlattenRecursiveApproach1(root->right,prev);
    FlattenRecursiveApproach1(root->left,prev);
    root->right=prev;
    root->left=NULL;
    prev=root;
    //T.C.-O(n) S.C.-O(N)
}

void FlattenIterativeApproach2(Node* root){
    stack<Node*>st;
    st.push(root);
    while(!st.empty()){
        Node* curr=st.top();
        st.pop();
        if(curr->right) st.push(curr->right);
        if(curr->left) st.push(curr->left);
        if(!st.empty())curr->right=st.top();
        curr->left=NULL;
    }
    //T.C.-O(n) S.C.-O(n)
}

void FlattenMorrisTraversalApproach3(Node* root){
    Node* curr=root;    
    while(curr!=NULL){
        if(curr->left==NULL){
            curr=curr->right;
        }
        else{
            Node* prev=curr->left;
            while(prev->right!=NULL){
                prev=prev->right;
            }
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
                curr=curr->right;
        }
    }
}

void showFlatten(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    showFlatten(root->right);
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(5);  
    root->left->left=new Node(3);
    root->left->right=new Node(4);
    root->right->right=new Node(6);
    root->right->right->left=new Node(7);


    //Flatten a Binary Tree
    // Node* prev=NULL;
    // FlattenRecursiveApproach1(root,prev);
    // showFlatten(root);

    // FlattenIterativeApproach2(root);
    // showFlatten(root);

    FlattenMorrisTraversalApproach3(root);
    showFlatten(root);

    return 0;
}