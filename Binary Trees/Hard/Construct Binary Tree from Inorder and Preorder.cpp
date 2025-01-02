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

Node* BuildFullTree(vector<int>& inorder,int inStart,int inEnd,vector<int>& preorder,int preStart,int preEnd,map<int,int>& inMap){
    if (preStart > preEnd || inStart > inEnd) return NULL;
    Node* root=new Node(preorder[preStart]);
    int inRoot=inMap[root->data];
    root->left=BuildFullTree(inorder,inStart,inRoot-1,preorder,preStart+1,preStart+inRoot-inStart,inMap);
    root->right=BuildFullTree(inorder,inRoot+1,inEnd,preorder,preStart+inRoot-inStart+1,preEnd,inMap);
    return root;
}

Node* buildTree(vector<int>& inorder,vector<int>& preorder){
    map<int,int>inMap;
    for(int i=0;i<inorder.size();i++){
        inMap[inorder[i]]=i;
    }
    Node* root=BuildFullTree(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,inMap);
    return root;
    //Time Complexity: O(N)
    //Space Complexity: O(N)
}

void InorderPrint(Node* root){
    if(root==NULL) return;
    InorderPrint(root->left);
    cout<<root->data<<" ";
    InorderPrint(root->right);
}

int main(){
    vector<int>inorder={40,20,50,10,60,30};    
    vector<int>preorder={10,20,40,50,30,60};
    Node* root=buildTree(inorder,preorder);

    InorderPrint(root);
    return 0;
}