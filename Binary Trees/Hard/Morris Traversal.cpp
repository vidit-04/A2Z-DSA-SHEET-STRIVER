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

vector<int> MorrisInorderTraversal(Node* root){
    vector<int>ans;
    Node* cur=root;
    while(cur!=NULL){
        if(cur->left==NULL){
            ans.push_back(cur->data);
            cur=cur->right;
        }
        else{
            Node* prev=cur->left;
            while(prev->right && prev->right!=cur){
                prev=prev->right;
            }
            if(prev->right==NULL){
                prev->right=cur;
                cur=cur->left;
            }
            else{
                prev->right=NULL;
                ans.push_back(cur->data);
                cur=cur->right;
            }
        }
    }
    return ans;
    //T.c O(n) S.c O(1)
}

vector<int> MorrisPreorderTraversal(Node* root){
    vector<int>ans;
    Node* cur=root;
    while(cur!=NULL){
        if(cur->left==NULL){
            ans.push_back(cur->data);
            cur=cur->right;
        }
        else{
            Node* prev=cur->left;
            while(prev->right && prev->right!=cur){
                prev=prev->right;
            }
            if(prev->right==NULL){
                ans.push_back(cur->data);
                prev->right=cur;
                cur=cur->left;
            }
            else{
                prev->right=NULL;
                cur=cur->right;
            }
        }
    }
    return ans;
    //T.c O(n) S.c O(1)
}

int main(){
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->left->right->right=new Node(60);
    root->right->left=new Node(70);
    root->right->right=new Node(80);

    vector<int>inorder=MorrisInorderTraversal(root);
    for(auto x:inorder) cout<<x<<" ";
    cout<<endl;

    vector<int>preorder=MorrisPreorderTraversal(root);
    for(auto x:preorder) cout<<x<<" ";
    cout<<endl;
    return 0;
}