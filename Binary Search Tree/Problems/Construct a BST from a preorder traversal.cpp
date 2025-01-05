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

Node* CreateBST(vector<int> pre,int& i,int max){
    if(pre.size()==i || pre[i]>max) return NULL;
    Node* root=new Node(pre[i++]);
    root->left=CreateBST(pre,i,root->data);
    root->right=CreateBST(pre,i,max);
    return root;
}

void preorder(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    vector<int> pre={8,5,1,7,10,12};  
    //Method 1 : just go on to the left side of the tree and insert the element if it is less than the current node and vice versa. T.C.-O(n^2)
    //Method 2  : Sort the preorder array , you will get inorder because in BST inorder is sorted. Now construct the tree using inorder and preorder. T.C.-O(nlogn)+O(n) S.C.-O(n)
    //Method 3 : Using method as we did in check of BST we just need upper bound . T.C.-O(n) S.C.-O(1)
    int i=0;
    Node* root=CreateBST(pre,i,INT_MAX);
    preorder(root);

    return 0;
}