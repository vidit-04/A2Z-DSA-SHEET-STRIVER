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

bool RootToNode(Node* root, vector<int>& ans,int element1){
    if(root==NULL) return false;
    ans.push_back(root->data);
    if(root->data==element1) return true;
    if(RootToNode(root->left,ans,element1) || RootToNode(root->right,ans,element1)) return true;
    ans.pop_back();
    return false;    
}

int LowestCommonAncestorApproach1(Node* root,int element1,int element2){
    vector<int> path1;
    vector<int> path2;
    RootToNode(root,path1,element1);
    RootToNode(root,path2,element2);

    int n=path1.size();
    int m=path2.size();
    int i=0;
    while(i<n && i<m){
        if(path1[i]!=path2[i]){
            break;
        }
        i++;  
    }
    return path1[i-1];

    //T.C.-O(N)+O(N)+O(N)
    //S.C.-O(N)+O(N)
}

Node* LowestCommonAncestorApproach2(Node* root,Node* element1,Node* element2){
    if(root==NULL || root==element1 || root==element2) return root;

    Node* left=LowestCommonAncestorApproach2(root->left,element1,element2);
    Node* right=LowestCommonAncestorApproach2(root->right,element1,element2);

    if(left==NULL) return right;
    else if(right==NULL) return left;
    else return root;

    //T.C.- O(N)
    //S.C.- O(N)
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    root->right->left=new Node(8);
    root->right->right=new Node(9);

    int element1=4;
    int element2=7;
    
    int ans1=LowestCommonAncestorApproach1(root,element1,element2);
    Node* ans2=LowestCommonAncestorApproach2(root,root->left->left,root->left->right->right);

    cout<<ans1<<endl;
    cout<<ans2->data<<endl;
    return 0;
}