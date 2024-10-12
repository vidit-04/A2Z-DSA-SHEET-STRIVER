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

vector<vector<int>> AllTraversal(Node* root){
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    stack<pair<Node*,int>>s;
    s.push({root,1});
    vector<int>preorder;
    vector<int>inorder;
    vector<int>postorder;
    while(!s.empty()){
        Node* curr=s.top().first;
        int num=s.top().second;
        s.pop();
        if(num==1){
            preorder.push_back(curr->data);
            s.push({curr,2});
            if(curr->left!=NULL) s.push({curr->left,1});
        }
        else if(num==2){
            inorder.push_back(curr->data);
            s.push({curr,3});
            if(curr->right!=NULL) s.push({curr->right,1});
        }
        else{
            postorder.push_back(curr->data);
        }
    }
    ans.push_back(preorder);
    ans.push_back(inorder);
    ans.push_back(postorder);
    return ans;
    //T.C.-O(3n)
    //S.C.-O(4n)
}

int main(){
    //Preorder, Inorder and Postorder Traversals in One Traversal
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(5);
    root->left->left=new Node(3);  
    root->left->right=new Node(4);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    //There are few rules to get all in one traveersal
    //Step 1: Make a Stack of Type <Node*,num(int)>
    //RULES:
    //if(num==1) push to preorder,increment num by 1, if it's left exist then push that to stack
    //if(num==2) push to inorder,increment num by 1, if it's right exist then push that to stack
    //if(num==3) push to postorder
    vector<vector<int>> ans=AllTraversal(root);
    cout<< "Preorder: ";
    for(auto x:ans[0]){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<< "Inorder: ";
    for(auto x:ans[1]){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<< "Postorder: ";
    for(auto x:ans[2]){
        cout<<x<<" ";
    }
    return 0;
}