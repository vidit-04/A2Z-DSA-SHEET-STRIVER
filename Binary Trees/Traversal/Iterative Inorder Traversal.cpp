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

vector<int> IterativeInorderTraversal(Node* root){
    vector<int>ans;
    if(root==NULL) return ans;
    stack<Node*>s;
    Node* curr=root;
    while(true){
        if(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }
        else{
            if(s.empty()) break;
            curr=s.top();
            s.pop();
            ans.push_back(curr->data);
            curr=curr->right;
        }
    }
    return ans;
    //T.C.-O(n)
    //S.C.-O(n)
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    vector<int>ans=IterativeInorderTraversal(root);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}