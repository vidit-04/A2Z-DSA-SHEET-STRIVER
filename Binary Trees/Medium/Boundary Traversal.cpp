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

bool isLeaf(Node* root){
    return (root->left==NULL && root->right==NULL);
}

void addLeftBoundary(Node* root, vector<int>& ans){
    Node* curr=root->left;
    while(curr){
        if(!isLeaf(curr)) ans.push_back(curr->data);
        if(curr->left) curr=curr->left;
        else curr=curr->right;
    }
}

void addLeafNodes(Node* root,vector<int>& ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    if(root->left) addLeafNodes(root->left,ans);
    if(root->right) addLeafNodes(root->right,ans);
}

void addRightBoundary(Node* root,vector<int>& ans){
    vector<int>temp;
    Node* curr=root->right;
    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->right) curr=curr->right;
        else curr=curr->left;
    }
    for(int i=temp.size()-1;i>=0;i--){
        ans.push_back(temp[i]);
    }
}

vector<int> BoundaryTraversal(Node* root){
    vector<int>ans;
    if(root==NULL) return ans;
    if(!isLeaf(root)) ans.push_back(root->data);
    addLeftBoundary(root,ans);
    addLeafNodes(root,ans);
    addRightBoundary(root,ans);
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(3);
    root->left->right=new Node(4);
    root->left->right->left=new Node(5);
    root->left->right->right=new Node(6);
    root->right=new Node(7);
    root->right->right=new Node(8);
    root->right->right->left=new Node(9);
    root->right->right->left->left=new Node(10);
    root->right->right->left->right=new Node(11);

    vector<int>ans=BoundaryTraversal(root);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}