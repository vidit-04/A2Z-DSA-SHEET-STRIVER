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

int Kcalc(Node* root){
    if(root==NULL) return 0;
    return 1+Kcalc(root->left)+Kcalc(root->right);
}

void KthSmallestInorder(Node* root,int k,int& cnt,int& ans){
    if(root==NULL) return;
    KthSmallestInorder(root->left,k,cnt,ans);
    if(k== ++cnt){
        ans= root->data;
    }
    KthSmallestInorder(root->right,k,cnt,ans);
    //T.C=O(h) where h is the height of the tree
}

int KthSmallestMorrisTraversal(Node* root,int k){
    if(root==NULL) return -1;
    Node* curr=root;
    int cnt=0;
    int ans=-1;
    while(curr!=NULL){
        if(curr->left==NULL){
            cnt++;
            if(cnt==k){
                ans=curr->data;
            }
            curr=curr->right;
        }
        else{
            Node* prev=curr->left;
            while(prev->right!=NULL && prev->right!=curr){
                prev=prev->right;
            }
            if(prev->right==NULL){
                prev->right=curr;
                curr=curr->left;
            }
            else{
                prev->right=NULL;
                cnt++;
                if(cnt==k){
                ans=curr->data;
                }
                curr=curr->right;
            }
            
        }
    }
    return ans;
}

void KthLargestInorder(Node* root,int k,int& cnt,int& ans){
    if(root==NULL) return;
    KthLargestInorder(root->left,k,cnt,ans);
    if(k== ++cnt){
        ans= root->data;
    }
    KthLargestInorder(root->right,k,cnt,ans);
}

void KthLargestInorder2(Node* root,int k,int& cnt,int& ans){
    if(root==NULL) return;
    KthLargestInorder2(root->right,k,cnt,ans);
    if(k== ++cnt){
        ans= root->data;
        return;
    }
    KthLargestInorder2(root->left,k,cnt,ans);
}

int main(){
    //INORDER TRAVERSAL IN BST GIVES A SEQUENCE OF SORTED ELEMENTS
    Node* root=new Node(5);  
    root->left=new Node(3);
    root->right=new Node(7);    
    root->left->left=new Node(1);
    root->left->right=new Node(4);
    root->right->left=new Node(6);
    root->right->right=new Node(8);
    root->left->left->right=new Node(2);
    int cnt=0;
    int ans=-1;
    KthSmallestInorder(root,3,cnt,ans);
    cout<<KthSmallestMorrisTraversal(root,3)<<endl;
    cout<<ans<<endl;

    int cnt2=0;
    int ans2=-1;
    int k=3;
    int K=Kcalc(root)-k+1;
    KthLargestInorder(root,K,cnt2,ans2);
    cout<<ans2<<endl;
    
    int cnt3=0;
    int ans3=-1;
    KthLargestInorder2(root,k,cnt3,ans3);
    cout<<ans3<<endl;
    return 0;
}