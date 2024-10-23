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

vector<int> BottomView(Node* root){
    vector<int>ans;
    queue<pair<Node*,int>> q;  //Stores the node and the vertical on which it exists
    map<int,int> mp;  //Stores the vertical and the value of the node
    q.push({root,0});
    while(!q.empty()){
        auto temp=q.front();
        q.pop();
        Node* curr=temp.first;
        int x=temp.second;
        mp[x]=curr->data;
        if(curr->left) q.push({curr->left,x-1});
        if(curr->right) q.push({curr->right,x+1});
    }
    for(auto i : mp){
        ans.push_back(i.second);
    }
    return ans;
    //T.C.- O(N)
    //S.C.- O(N)
}

vector<int> LeftView(Node* root){
    vector<int>ans;
    queue<Node*> q;  //Stores the node and the vertical on which it exists
    // map<int,int> mp;  //Stores the vertical and the value of the node
    q.push(root);
    while(!q.empty()){
        auto temp=q.front();
        q.pop();
        int flag=false;
           
    }
    return ans;

}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    //BOTTOM VIEW-  4 8 6 9 7
    vector<int> ans=LeftView(root);
    for(auto x:ans){
        cout<<x<<" ";
    }

    return 0;
}