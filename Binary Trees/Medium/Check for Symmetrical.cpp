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

bool Symmetry(Node* root1,Node* root2){
    if(root1==NULL || root2==NULL) return root1==root2;
    return  (root1->data==root2->data) && Symmetry(root1->left,root2->right) && Symmetry(root1->right,root2->left);
}
    
int main(){
    // Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(2);
    // root->left->left = new Node(3);
    // root->left->right = new Node(4);
    // root->right->left = new Node(4);
    // root->right->right = new Node(3);


    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->right = new Node(3);
    root->right->right = new Node(3);
    cout<<Symmetry(root->left,root->right);
    return 0;
}