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

string Serialize(Node* root){
    if(!root) return "";
    string s="";
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        if(curr==NULL) s+="#,";
        else s+=to_string(curr->data)+",";
        if(curr!=NULL){
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return s;
}

Node* Deserialize(string s){
    if(s.empty()) return NULL;
    stringstream ss(s);
    string str;
    getline(ss,str,',');
    Node* root=new Node(stoi(str));
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();

        getline(ss,str,',');
        if(str=="#") curr->left=NULL;
        else{
            curr->left=new Node(stoi(str));
            q.push(curr->left);
        }

        getline(ss,str,',');
        if(str=="#") curr->right=NULL;
        else{
            curr->right=new Node(stoi(str));
            q.push(curr->right);
        }
    }
    return root;
}

void LOT(Node* root){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}

int main(){
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->right->left=new Node(40);
    root->right->right=new Node(50);
    string s=Serialize(root);
    cout<<s<<endl;

    Node* root2=Deserialize(s);
    LOT(root2);
    return 0;
}