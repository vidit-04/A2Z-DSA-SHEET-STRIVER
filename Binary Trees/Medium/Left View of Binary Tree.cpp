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

vector<int> RightViewApproach1(Node* root){
    //ITERATIVE WAY HAVE S.C. -O(N) while recursive has O(H).
    vector<int>ans;
    if(!root) return ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node* curr=q.front();
            q.pop();
            if(i==n-1) ans.push_back(curr->data);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    return ans;
    //T.C.- O(N)
    //S.C.- O(N)
}

void RightViewApproach2(Node* root,int level,vector<int>& ans){
    //RECURSIVE- WE HERE PLAY A SMART GAME OF TRAVERSING IN REVERSE OF PREORDER
    //WE TRAVERSE ROOT ,RIGHT THEN LEFT
    if(root==NULL) return;
    if(ans.size()==level) ans.push_back(root->data);
    RightViewApproach2(root->right,level+1,ans);
    RightViewApproach2(root->left,level+1,ans);
    //T.C.- O(N)
    //S.C.- O(H)
}

vector<int> LeftViewApproach1(Node* root){
    //ITERATIVE WAY HAVE S.C. -O(N) while recursive
    vector<int>ans;
    if(!root) return ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node* curr=q.front();
            q.pop();
            if(i==0) ans.push_back(curr->data);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    return ans;
    //T.C.- O(N)
    //S.C.- O(N)
}

void LeftViewApproach2(Node* root,int level,vector<int>& ans){
    //RECURSIVE- WE HERE PLAY A SMART GAME OF TRAVERSING IN REVERSE OF PREORDER
    //WE TRAVERSE ROOT ,RIGHT THEN LEFT
    if(root==NULL) return;
    if(ans.size()==level) ans.push_back(root->data);
    LeftViewApproach2(root->left,level+1,ans);
    LeftViewApproach2(root->right,level+1,ans);
    //T.C.- O(N)
    //S.C.- O(H)
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left= new Node(6);
    root->right->right = new Node(7);  

    vector<int>right=RightViewApproach1(root);
    cout<<"RIGHT VIEW WITH TRAVERSAL"<<endl;
    for(auto i : right){
        cout<<i<<" ";
    }
    cout<<endl;

    vector<int>right2;
    RightViewApproach2(root,0,right2);
    cout<<"RIGHT VIEW WITH RECURSION"<<endl;
    for(auto i : right2){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"LEFT VIEW WITH TRAVERSAL"<<endl;
    vector<int>left=LeftViewApproach1(root);
    for(auto i : left){
        cout<<i<<" ";
    }
    cout<<endl;
    
    vector<int>left2;
    LeftViewApproach2(root,0,left2);
    cout<<"LEFT VIEW WITH RECURSION"<<endl;
    for(auto i : left2){
        cout<<i<<" ";
    }
    return 0;
}