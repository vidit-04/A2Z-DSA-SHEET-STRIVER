#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  int i;
  int j;
  Node(int data,int row,int col){
      this->data=data;
      this->i=row;
      this->j=col;
  }
};

class compare{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

vector<int> mergeKArrays(vector<vector<int>> arr, int k){
    priority_queue<Node*,vector<Node*>,compare> minHeap;
    for(int i=0;i<k;i++){
        Node* temp=new Node(arr[i][0],i,0);
        minHeap.push(temp);
    }
    vector<int>ans;
    while(minHeap.size()>0){
        Node* temp=minHeap.top();
        minHeap.pop();
        int i=temp->i;
        int j=temp->j;
        ans.push_back(temp->data);
        if(j+1<arr[i].size()){
            Node* temp2=new Node(arr[i][j+1],i,j+1);
            minHeap.push(temp2);
        }
    }
    return ans;
}

int main(){
    
    return 0;
}