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

bool check(Node* root,int min,int max){
    if(root==NULL) return true;
    if(root->data<=min || root->data>=max) return false;
    check(root->left,min,root->data);
    check(root->right,root->data,max);
    //T.C=O(n) where n is the number of nodes in the tree
}

int main(){
    Node* root=new Node(5);
    root->left=new Node(1);
    root->right=new Node(6);    
    root->right->left=new Node(7);
    root->right->right=new Node(8);

    if(check(root,INT_MIN,INT_MAX)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}