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

vector<int> PreorderIterative(Node* root){
    vector<int>ans;
    if(root==NULL) return;

    stack<Node*>s;
    s.push(root);
    while(!s.empty()){
        Node* curr=s.top();
        s.pop();
        ans.push_back(curr->data);
        if(curr->right!=NULL) s.push(curr->right);
        if(curr->left!=NULL) s.push(curr->left);
    }
    return ans;
    //T.C.-O(n)
    //S.C.-O(n)
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    
    return 0;
}