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

void BSIterator(Node* root,stack<Node*>& s){
    while(root){
        s.push(root);
        root=root->left;
    }
}

int next(stack<Node*>& s){
    Node* temp=s.top();
    s.pop();
    if(temp->right){
        BSIterator(temp->right,s);
    }
    return temp->data;
}

bool hasNext(stack<Node*>& s){
    return s.size();
}

int main(){
    Node* root=new Node(7);
    root->left=new Node(3);
    root->right=new Node(10);
    root->left->left=new Node(2);
    root->left->right=new Node(6);
    root->right->left=new Node(9);
    root->right->left->left=new Node(8);
    root->left->left->left=new Node(1);
    root->left->right->left=new Node(5);
    root->left->right->left->left=new Node(4);

    stack<Node*> s;

    return 0;
}