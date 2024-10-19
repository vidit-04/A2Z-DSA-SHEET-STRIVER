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

vector<int> TopView(Node* root){
    vector<int>ans;
    if(root==NULL) return ans;
    queue<pair<Node*,int>>q;
    map<int,int>mp;
    q.push({root,0});
    while(!q.empty()){
        auto curr=q.front();
        q.pop();
        if(mp.find(curr.second)==mp.end()){
            mp[curr.second]=curr.first->data;
        }
        if(curr.first->left) q.push({curr.first->left,curr.second-1});
        if(curr.first->right) q.push({curr.first->right,curr.second+1});
    }
    for(auto x:mp){
        ans.push_back(x.second);
    }
    return ans;
    //T.C.-O(n)
    //S.C.-O(n)
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->right = new Node(7);
    
    vector<int>ans=TopView(root);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}