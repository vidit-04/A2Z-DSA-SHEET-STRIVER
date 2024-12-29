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

Node* findParent(Node* root,int target,map<Node*,Node*>& mpp){
    if(root==NULL) return NULL;
    queue<Node*> q;
    q.push(root);
    Node* targetNode;
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp->data==target) targetNode=temp;
        if(temp->left){
            mpp[temp->left]=temp;
            q.push(temp->left);
        }
        if(temp->right){
            mpp[temp->right]=temp;
            q.push(temp->right);
        }
    }
    return targetNode;
}

int findMaxDistance(Node* start,map<Node*,Node*>mpp){
    queue<Node*> q;
    q.push(start);
    map<Node*,bool> visited;
    visited[start]=1;
    int maxi=0;
    while(!q.empty()){
        int size=q.size();
        int flag=0;
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();
            if(temp->left && !visited[temp->left]){
                flag=1;
                visited[temp->left]=1;
                q.push(temp->left);
            }
            if(temp->right && !visited[temp->right]){
                flag=1;
                visited[temp->right]=1;
                q.push(temp->right);
            }
            if(mpp[temp] && !visited[mpp[temp]]){
                flag=1;
                visited[mpp[temp]]=1;
                q.push(mpp[temp]);
            }
        }
        if(flag) maxi++;
    }

    return maxi;
}

int minTime(Node* root, int target){
    map<Node*,Node*> mpp; //parents mapping
    Node* targetNode=findParent(root,target,mpp);
    int maxi=findMaxDistance(targetNode,mpp);
    return maxi;
    //T.C.-O(N)
    //S.C. - O(N)
}

int main(){
    
    return 0;
}