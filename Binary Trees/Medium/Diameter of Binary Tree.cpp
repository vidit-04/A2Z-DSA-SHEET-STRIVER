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

// int maxDepth(Node* root,int maxi){
//     if(root==NULL) return 0;
//     int lh=maxDepth(root->left);
//     int rh=maxDepth(root->right);
//     return 1+max(lh,rh);
// }

// int findDiameter(Node* root,int& maxi){
//     //BRUTE FORCE
//     if(root==NULL) return 0;
//     int lh=maxDepth(root->left);
//     int rh=maxDepth(root->right);
//     maxi=max(maxi,1+lh+rh);
//     findDiameter(root->left,maxi);
//     findDiameter(root->right,maxi);
//     return maxi;
//     //T.C.-O(n^2)
//     //S.C.-O(n)
// }

int maxDepth2(Node* root,int&    maxi){
    //OPTIMISED CODE IN MAX DEPTH ONLY
    if(root==NULL) return 0;
    int lh=maxDepth2(root->left,maxi);
    int rh=maxDepth2(root->right,maxi);
    maxi=max(maxi,lh+rh);
    return 1+max(lh,rh);
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->right->left=new Node(4);    
    root->right->left->left=new Node(5);    
    root->right->left->left->left=new Node(9);    
    root->right->right=new Node(6);
    root->right->right->right=new Node(7);
    root->right->right->right->right=new Node(8);
    int maxi=INT_MIN;

    maxDepth2(root,maxi);
    cout<<maxi;
    return 0;
}