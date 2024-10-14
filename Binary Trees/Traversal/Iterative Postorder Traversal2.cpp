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

vector<int> IterativePostorderTraversal(Node* root){
    vector<int>ans;
    if(root==NULL) return ans;
    stack<Node*>s;
    Node* curr=root;
    s.push(root);
    while(curr!=NULL || !s.empty()){
        if(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }
        else{
            Node* temp=s.top()->right;
            if(temp==NULL){
                temp=s.top();
                s.pop();
                ans.push_back(temp->data);
                while(!s.empty() && temp==s.top()->right){
                    temp=s.top();
                    s.pop();
                    ans.push_back(temp->data);
                }
            }
            else{
                curr=temp;
            }
        }
    }
    return ans;
    //T.C.-O(n)
    //S.C.-O(n)
}

int main(){
    //Iterative Postorder Traversal using 1 Stack
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(7);
    root->right->left=new Node(8);
    root->left->left=new Node(3);
    root->left->left->right=new Node(4);
    root->left->left->right->right=new Node(5);
    root->left->left->right->right->right=new Node(6);

    vector<int>ans=IterativePostorderTraversal(root);
    for(auto x:ans){
        cout<<x<<" ";
    }

    return 0;
}