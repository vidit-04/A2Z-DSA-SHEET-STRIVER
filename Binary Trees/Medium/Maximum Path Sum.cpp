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

int maxPathSum(Node* root,int& maxi){
    if(root==NULL) return 0;
    int leftSum=max(0,maxPathSum(root->left,maxi));
    int rightSum=max(0,maxPathSum(root->right,maxi));
    maxi=max(maxi,root->data+leftSum+rightSum);
    return root->data+max(leftSum,rightSum);
}

int main(){
    Node* root=new Node(-10);
    root->left=new Node(9);
    root->right=new Node(20);
    root->right->left=new Node(15);
    root->right->right=new Node(7);

    int maxi=INT_MIN;
    maxPathSum(root,maxi);
    cout<<maxi<<endl;
    return 0;
}