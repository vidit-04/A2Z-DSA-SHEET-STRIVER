#include<bits/stdc++.h>
using namespace std;

int findCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> adjList(n,vector<int>(n,INT_MAX));
    for(auto it:edges){
        adjList[it[0]][it[1]]=it[2];
        adjList[it[1]][it[0]]=it[2];
    }
    for(int i=0;i<n;i++){
        adjList[i][i]=0;
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adjList[i][k]==INT_MAX || adjList[k][j]==INT_MAX) continue;
                adjList[i][j]=min(adjList[i][j],adjList[i][k]+adjList[k][j]);
            }
        }
    }
    int cnt=0;
    int cntMin=INT_MAX;
    int city=-1;
    for(int i=0;i<n;i++){
        cnt=0;
        for(int j=0;j<n;j++){
            if(adjList[i][j]<=distanceThreshold){
                cnt++;
            }
        }
        if(cnt<=cntMin){
            cntMin=cnt;
            city=i;
        }
    }
    return city;
}

int main(){
    int n=4,m=4;
    vector<vector<int>> edges={{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    int distanceThreshold=4;
    cout<<findCity(n,edges,distanceThreshold);
    return 0;
}