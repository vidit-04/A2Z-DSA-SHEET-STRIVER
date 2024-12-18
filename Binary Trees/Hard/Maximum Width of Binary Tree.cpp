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

int MaxWidth(Node* root){
    if(!root) return 0;
    queue<pair<Node*,int>>q; // queue of pair of Node* and int where int is the horizontal distance
    q.push({root,0 });
    int maxWidth=0;
    while(!q.empty()){
        int size=q.size();
        int minDist=q.front().second;
        int first,last;
        for(int i=0;i<size;i++){
            Node* temp=q.front().first;
            int dist=q.front().second;
            int currDist=dist-minDist;
            q.pop();
            if(i==0) first=currDist;
            if(i==size-1) last=currDist;
            if(temp->left) q.push({temp->left,currDist*2+1});
            if(temp->right) q.push({temp->right,currDist*2+2});
        }
        maxWidth=max(maxWidth,last-first+1);
    }
    return maxWidth;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    cout<<MaxWidth(root)<<endl;
    return 0;
}