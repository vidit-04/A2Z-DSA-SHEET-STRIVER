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

void getCorrected(Node* root,int& index, vector<int>& arr){
    if(root==NULL) return;
    getCorrected(root->left,index,arr);
    if(root->data!=arr[index]){
        root->data=arr[index];
    }
    index++;
    getCorrected(root->right,index,arr);
}

void inorder(Node* root,vector<int>&arr){
    if(root==NULL) return;
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

void RecoverBSTApproach1(Node* root){
    //BRUTE FORCE APPROACH
    //1. Do inorder traversal of the tree and store the elements in a vector
    //2. Sort the vector
    //3. Do inorder traversal of the tree and replace the elements with the sorted vector elements
    vector<int>arr;
    inorder(root,arr);
    sort(arr.begin(),arr.end());
    int index=0;
    getCorrected(root,index,arr);
    //T.C. = O(nlogn)+O(n)+O(n) S.C. = O(n)
}

void inorderIt(Node* root,Node*& first,Node*& last,Node*& prev){
    if(root==NULL) return;
    inorderIt(root->left,first,last,prev);
    if(prev!=NULL && prev->data>root->data){
        if(first==NULL){
            first=prev;
        }
        last=root;
    }
    prev=root;
    inorderIt(root->right,first,last,prev);
}

void RecoverBSTApproach2(Node* root){
    Node* first=NULL;
    Node* last=NULL;
    Node* prev=new Node(INT_MIN);
    inorderIt(root,first,last,prev);
    if(first!=NULL && last!=NULL){
        swap(first->data,last->data);
    }
    //T.C. = O(n) S.C. = O(1)
}

int main(){
    Node* root=new Node(3);  
    root->left=new Node(1);
    root->right=new Node(4);
    root->right->left=new Node(2);

    RecoverBSTApproach2(root);
    vector<int>ans;
    inorder(root,ans);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}