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

bool RootToNode(Node* root,vector<int>& ans,int target){
    if(root==NULL) return false;
    ans.push_back(root->data);
    if(root->data==target) return true;
    if(RootToNode(root->left,ans,target)) return true;
    if(RootToNode(root->right,ans,target)) return true;
    ans.pop_back();
    return false;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    vector<int>ans;
    RootToNode(root,ans,7);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}