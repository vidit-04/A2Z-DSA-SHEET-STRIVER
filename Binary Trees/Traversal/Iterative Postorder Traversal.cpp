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

vector<int> IterativePostorderTraversal(Node* root){
    vector<int>ans;
    if(root==NULL) return ans;
    stack<Node*>s1;
    stack<Node*>s2;
    s1.push(root);
    while(!s1.empty()){
        Node* curr=s1.top();
        s1.pop();
        s2.push(curr);
        if(curr->left!=NULL) s1.push(curr->left);
        if(curr->right!=NULL) s1.push(curr->right);
    }
    while(!s2.empty()){
        ans.push_back(s2.top()->data);
        s2.pop();
    }
    return ans;
    //T.C.-O(n)
    //S.C.-O(2n) 
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    root->right->right->right=new Node(8);

    vector<int> ans=IterativePostorderTraversal(root);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}