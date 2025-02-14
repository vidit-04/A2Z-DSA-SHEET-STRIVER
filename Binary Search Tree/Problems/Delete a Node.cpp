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

Node* findLastRight(Node* root){
    if(root->right==NULL) return root;
    return findLastRight(root->right);
}

Node* helper(Node* root){
    if(root->left==NULL) return root->right;
    if(root->right==NULL) return root->left;

    Node* rightChild=root->right;
    Node* lastRight=findLastRight(root->left);
    lastRight->right=rightChild;
    return root->left;
}

void DeleteNode(Node* root, int key){
    if(root==NULL) return;
    if(root->data==key){
        helper(root);
        return;
    }
    while(root!=NULL){
        if(root->data>key){
            if(root->left!=NULL && root->left->data==key){
                root->left=helper(root->left);
                return;
            }
            else root=root->left;
        }
        else{
            if(root->right!=NULL && root->right->data==key){
                root->right=helper(root->right);
                return;
            }
            else root=root->right;
        }
    }
    return;
    //T.C=O(h) where h is the height of the tree
}

void LevelOrderTraversal(Node* root){
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}

int main(){
    Node* root=new Node(9);    
    root->left=new Node(8);
    root->right=new Node(12);
    root->left->left=new Node(5);
    root->right->left=new Node(10);
    root->right->right=new Node(13);
    root->right->left->right=new Node(11);
    root->left->left->left=new Node(3);
    root->left->left->right=new Node(7);
    root->left->left->right->right=new Node(8);
    root->left->left->right->left=new Node(6);
    root->left->left->left->left=new Node(2);
    root->left->left->left->right=new Node(4);
    root->left->left->left->left->left=new Node(1);


    //Delete a Node
    int key=5 ;
    DeleteNode(root,key);
    LevelOrderTraversal(root);
    return 0;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
//     public:
//         bool isLeaf(TreeNode* root){
//             return (root->left==NULL && root->right==NULL);
//         }
//         bool isOneChildNode(TreeNode* root){
//             return (root->left==NULL && root->right!=NULL) || (root->left!=NULL && root->right==NULL);
//         }
//         pair<TreeNode*,TreeNode*> getChildandParent(TreeNode* root,int key){
//             TreeNode* curr=root;
//             TreeNode* par=NULL;
//             while(curr!=NULL){
//                 if(curr->val==key) break;
//                 par=curr;
//                 if(curr->val>key) curr=curr->left;
//                 else curr=curr->right;
//             }
//             return {curr,par};
//         }
//         TreeNode* deleteLeaf(TreeNode* node, TreeNode* par){
//             if(par->left==node) par->left=NULL;
//             else par->right=NULL;
//             return node;
//         }
//         TreeNode* deleteOneChildNode(TreeNode* node, TreeNode* par){
//             if(par->left==node){
//                 if(node->left==NULL){
//                     par->left=node->right;
//                     node->right=NULL;
//                 }
//                 else{
//                     par->left=node->left;
//                     node->left=NULL;
//                 }
//             }
//             else{
//                 if(node->left==NULL){
//                     par->right=node->right;
//                     node->right=NULL;
//                 }
//                 else{
//                     par->right=node->left;
//                     node->left=NULL;
//                 }
//             }
//             return node;
//         }
//         TreeNode* findLargest(TreeNode* root){
//             TreeNode* curr=root;
//             while(curr->right!=NULL){
//                 curr=curr->right;
//             }
//             return curr;
//         }
//         TreeNode* deleteDoubleChild(TreeNode* root,TreeNode* par){
//             TreeNode* parent=root;
//             TreeNode* pred=root->left;
//             while(pred->right){
//                 parent=pred;
//                 pred=pred->right;
//             }
//             TreeNode* n1;
//             if(isLeaf(pred)) n1=deleteLeaf(pred,parent);
//             else n1=deleteOneChildNode(pred,parent);
//             if(par && par->left==root) par->left=n1;
//             else if(par) par->right=n1;
//             n1->left=root->left;
//             n1->right=root->right;
//             return root;
//         }
//         TreeNode* deleteRoot(TreeNode* root){
//             if(!root){
//                 delete (root);
//                 return NULL;
//             }
//             if(isLeaf(root)){
//                 delete(root);
//                 return NULL;
//             }
//             if(isOneChildNode(root)){
//                 TreeNode* ans=root->left ? root->left : root->right;
//                 delete(root);
//                 return ans;
//             }
//             TreeNode* ans=root->left;
//             while(ans->right!=NULL){
//                 ans=ans->right;
//             }
//             TreeNode* node=deleteDoubleChild(root,NULL);
//             delete(node);
//             return ans;
//         }
//         TreeNode* deleteNode(TreeNode* root, int key) {
//             pair<TreeNode*,TreeNode*> p=getChildandParent(root,key);
//             if(!p.first) return root;
//             if(p.first==root) return deleteRoot(p.first);
    
//             TreeNode* node;
//             if(isLeaf(p.first)) node=deleteLeaf(p.first,p.second);
//             else if(isOneChildNode(p.first)) node=deleteOneChildNode(p.first,p.second);
//             else node=deleteDoubleChild(p.first,p.second);
//             delete(node);
//             return root;
//         }
//     };
    
    