#include<bits/stdc++.h>
using namespace std;

vector<int> KahnAlgorithm(vector<vector<int>>& adj){
    int V = adj.size();
    vector<int> indegree(V,0);
    for(auto i : adj){
        for(auto j : i){
            indegree[j]++;
        }
    }

    queue<int> q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0) q.push(i);
    }

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto i : adj[node]){
            indegree[i]--;
            if(indegree[i]==0) q.push(i);
        }
    }
    return topo;
    //T.C.-O(V+E)
    //S.C.-O(V)
}

string findOrder(vector<string>& words,int k){
    int n=words.size();
    vector<vector<int>> adj(k,vector<int>());

    for(int i=0;i<n-1;i++){
        string word1=words[i];
        string word2=words[i+1];
        int len=min(word1.size(),word2.size());
        for(int j=0;j<len;j++){
            if(word1[j]!=word2[j]){
                adj[word1[j]-'a'].push_back(word2[j]-'a');
                break;
            }
        }
    }

    vector<int> topo=KahnAlgorithm(adj);
    string ans="";
    for(auto i: topo){
        ans=ans+char(i+'a');
    }
    return ans;
}

int main(){
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};;
    //Find Alien Dictionary Order
    string ans=findOrder(words,4);
    cout<<ans;

    //IT would fail on two type of inputs such as:
    //1. If there is a cycle in the graph as we know topological sort is only possible if there is no cycle in the graph
    // so if string1= "abc", string2="bca", string3="abcd"
    //2. if two string are like abcd, abc then there would be no difference of character in them so we can't say which one is greater
    return 0;
}