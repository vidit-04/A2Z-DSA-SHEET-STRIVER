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

Node* BuildFullTree(vector<int>& inorder,int inStart,int inEnd,vector<int>& postorder,int postStart,int postEnd,map<int,int>& inMap){
    if (postStart > postEnd || inStart > inEnd) return NULL;
    Node* root=new Node(postorder[postEnd]);
    int inRoot=inMap[root->data];
    int numsLeft=inRoot-inStart;
    root->left=BuildFullTree(inorder,inStart,inRoot-1,postorder,postStart,postStart+numsLeft-1,inMap);
    root->right=BuildFullTree(inorder,inRoot+1,inEnd,postorder,postStart+numsLeft,postEnd-1,inMap);
    return root;
}

Node* buildTree(vector<int>& inorder,vector<int>& postorder){
    map<int,int>inMap;
    for(int i=0;i<inorder.size();i++){
        inMap[inorder[i]]=i;
    }
    Node* root=BuildFullTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,inMap);
    return root;
    //Time Complexity: O(N)
    //Space Complexity: O(N)
}

void postOrder(Node* root){
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main(){
    vector<int>inorder={40,20,50,10,60,30};
    vector<int>postorder={40,50,20,60,30,10};
    Node* root=buildTree(inorder,postorder);
    postOrder(root);
    return 0;
}