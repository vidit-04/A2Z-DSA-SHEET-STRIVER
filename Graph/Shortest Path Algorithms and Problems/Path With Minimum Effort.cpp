#include<bits/stdc++.h>
using namespace std;

int findPath(vector<vector<int>>& grid){
    int n=grid.size();
    int m=grid[0].size();
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq; // {maxDiff,{row,col}}
    vector<vector<int>> dist(n,vector<int>(m,1e9));
    vector<int> delrow={-1,0,1,0};
    vector<int> delcol={0,1,0,-1};

    dist[0][0]=0;
    pq.push({0,{0,0}});
    while(!pq.empty()){
        auto it=pq.top();
        int diff= it.first;
        int row=it.second.first;
        int col=it.second.second;
        pq.pop();

        if(row==n-1 && col==m-1) return diff;

        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                int newDiff=max(abs(grid[nrow][ncol]-grid[row][col]),diff);
                if(newDiff<dist[nrow][ncol]){
                    dist[nrow][ncol]=newDiff;
                    pq.push({newDiff,{nrow,ncol}});
                }
            }
        }
    }
    return 0;
    //T.C: O(E log V)
    //S.C: O(rows*cols)
}

int main(){
    vector<vector<int>> grid={{1,2,2},{3,8,2},{5,3,5}}; //output: 2
    //We need to keep the difference maximu in the path to reach the destination.
    //All of the paths will have the minimum value of the maximum difference.
    cout<<findPath(grid)<<endl;
    return 0;
}