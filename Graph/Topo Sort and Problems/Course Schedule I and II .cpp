#include<bits/stdc++.h>
using namespace std;

vector<int> CourseSchedule2(int n, int m, vector<vector<int>> prerequisites) {
    vector<vector<int>> adj(n);
    for(auto it : prerequisites){
        adj[it[1]].push_back(it[0]);
    }
    
    vector<int>indegree(n,0);
    for(int i=0;i<n;i++){
        for(auto j : adj[i]){
            indegree[j]++;
        }
    }
    
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0) q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        
        for(auto i:adj[node]){
            indegree[i]--;
            if(indegree[i]==0) q.push(i);
        }
    }
    return ans.size() == n ? ans : vector<int>();
    //T.C.-O(V+E)
    //S.C.-O(V)
}

bool CourseSchedule1(int N, int P, vector<pair<int, int> >& prerequisites) {
    //number of tasks N and a list of P prerequisite pairs
    vector<vector<int>>adj(N);
    for(auto it: prerequisites){
        adj[it.second].push_back(it.first);
    }
    vector<int> indegree(N,0);
    for(int i=0;i<N;i++){
        for(auto j : adj[i]){
            indegree[j]++;
        }
    }
    queue<int>q;
    for(int i=0;i<N;i++){
        if(indegree[i]==0) q.push(i);
    }
    int cnt=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cnt++;
        
        for(auto i : adj[node]){
            indegree[i]--;
            if(indegree[i]==0) q.push(i);
        }
    }
    return cnt==adj.size();
}

int main(){
    // If question is all about something before somethig else then it is a topological sort problem
    // Course Schedule I
    vector<pair<int, int> > prerequisites={{1,0},{2,1},{3,2}};
    cout<<CourseSchedule1(4,3,prerequisites);
    // Course Schedule II
    vector<vector<int>> prerequisites2={{1,0},{2,1},{3,2}};
    vector<int> ans=CourseSchedule2(4,3,prerequisites2);
    for(auto i : ans) cout<<i<<" ";
    return 0;
}