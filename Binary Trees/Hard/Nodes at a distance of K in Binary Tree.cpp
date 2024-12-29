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

void markParents(Node* root,unordered_map<Node*,Node*>&parent_track){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        if(curr->left){
            parent_track[curr->left]=curr;
            q.push(curr->left);
        }
        if(curr->right){
            parent_track[curr->right]=curr;
            q.push(curr->right);
        }
    }
}

vector<int> NodesAtDistanceK(Node* root,Node* target,int k){
    if(!root) return {};
    unordered_map<Node*,Node*>parent_track;
    markParents(root,parent_track);

    unordered_map<Node*,bool>visited;
    queue<Node*>q;
    q.push(target);
    visited[target]=true;
    int level=0;
    while(!q.empty()){
        int size=q.size();  
        if(level++ == k) break;
        for(int i=0;i<size;i++){
            Node* curr=q.front();
            q.pop();
            if(curr->left && !visited[curr->left]){
                q.push(curr->left);
                visited[curr->left]=true;
            }
            if(curr->right && !visited[curr->right]){
                q.push(curr->right);
                visited[curr->right]=true;
            }
            if(parent_track[curr] && !visited[parent_track[curr]]){
                q.push(parent_track[curr]);
                visited[parent_track[curr]]=true;
            }
        }
    }
    vector<int>res;
    while(!q.empty()){
        res.push_back(q.front()->data);
        q.pop();
    }
    return res;
    //T.C.-O(N) and S.C.-O(N)
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(6);
    
    vector<int>res=NodesAtDistanceK(root,root->right,1);
    for(auto x:res) cout<<x<<" ";
    

    return 0;
}