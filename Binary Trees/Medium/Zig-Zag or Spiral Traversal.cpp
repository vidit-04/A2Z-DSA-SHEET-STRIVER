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

vector<vector<int>> ZigZag(Node* root){
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    queue<Node*>q;
    q.push(root);
    bool flag=false;
    while(!q.empty()){
        vector<int>temp;
        int n=q.size();
        while(n--){
            Node* curr=q.front();
            q.pop();
            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right);
            temp.push_back(curr->data);
        }
        if(flag) reverse(temp.begin(),temp.end());
        flag=!flag;
        ans.push_back(temp);
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
    root->right->right=new Node(6);

    vector<vector<int>> ans=ZigZag(root);
    for(auto it:ans){
        for(auto ptr:it){
            cout<<ptr<<" ";
        }
        cout<<endl;
    }
    return 0;
}