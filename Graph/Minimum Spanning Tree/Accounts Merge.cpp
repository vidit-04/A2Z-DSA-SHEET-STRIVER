#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int> rank,parent,size;
    DisjointSet(int n){ 
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findParent(int node){
        if(node==parent[node]) return node;
        parent[node]=findParent(parent[node]);
        return parent[node];// path compression
    }
    void unionByRank(int u,int v){
        //ramk is nothing but the height of the tree
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_u]=ulp_v;
            rank[ulp_u]++;
        }   
    }
    void unionBySize(int u,int v){
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }   
    }
};

vector<vector<string>> accountMerge(vector<vector<string>>& accounts){
    int n=accounts.size();
    DisjointSet ds(n);
    unordered_map<string,int> mapMailToIndex;
    for(int i=0;i<n;i++){
        for(int j=1;j<accounts[i].size();j++){
            string mail=accounts[i][j];
            if(mapMailToIndex.find(mail)!=mapMailToIndex.end()){
                ds.unionBySize(i,mapMailToIndex[mail]);
            }
            else{
                mapMailToIndex[mail]=i;
            }
        }
    }
    vector<vector<string>> mergeMail;
    for(auto it: mapMailToIndex){
        string mail=it.first;
        int node=ds.findParent(it.second);
        mergeMail[node].push_back(mail);
    }
    vector<vector<string>> ans;
    for(int i=0;i<n;i++){
        if(mergeMail[i].size()==0) continue;
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        sort(mergeMail[i].begin(),mergeMail[i].end());
        for(auto j: mergeMail[i]){
            temp.push_back(j);
        }
        ans.push_back(temp);
    }
    return ans;
    //Time Complexity: O(n*mlogm) where n is the number of accounts and m is the number of emails in each account
    //Space Complexity: O(n*m)  
}

int main(){
    vector<vector<string>> accounts={{"John","johnsmith@mail.com","john_newyork@mail.com"},
                                    {"John","johnsmith@mail.com","john00@mail.com"},
                                    {"Mary","mary@mail.com"},    
                                    {"John","johnnybravo@mail.com"}};
    vector<vector<string>> ans=accountMerge(accounts);
    for(auto i: ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}