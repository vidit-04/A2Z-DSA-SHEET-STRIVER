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

vector<vector<int>> VerticalOrderTraversal(Node* root){
    queue<pair<Node*,pair<int,int>>> todo;
    todo.push({root,{0,0}});
    map<int,map<int,multiset<int>>> nodes;// Map stores int - vertical order second map- int - level and multiset holds all the values at that level
    while(!todo.empty()){
        auto temp=todo.front();
        todo.pop();
        Node* curr=temp.first;
        int x=temp.second.first;
        int y=temp.second.second;
        nodes[x][y].insert(curr->data);
        if(curr->left) todo.push({curr->left,{x-1,y+1}});
        if(curr->right) todo.push({curr->right,{x+1,y+1}});
    }
    vector<vector<int>> ans;
    for(auto p:nodes){
        vector<int>col;
        for(auto q:p.second){
            col.insert(col.end(),q.second.begin(),q.second.end());
        }
        sort(col.begin(),col.end());
        ans.push_back(col);
    }
    return ans;
    //T.C.-O(nlogn)
    //S.C.-O(n)
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right->left=new Node(9);
    root->right->right=new Node(10);

    vector<vector<int>> ans=VerticalOrderTraversal(root);
    for(auto x:ans){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}