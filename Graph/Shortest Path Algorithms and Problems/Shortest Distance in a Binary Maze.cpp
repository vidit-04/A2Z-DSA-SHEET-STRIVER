#include<bits/stdc++.h>
using namespace std;

int ShortestDistanceInBinaryMaze(vector<vector<int>>& grid,int srow,int scol,int drow,int dcol){
    int rows=grid.size();
    int cols=grid[0].size();
    //we can use queue here instead of priortiy queue because here we are considering the weight of each transition as 1.
    // and that's why we can use queue here because it will be already sorted
    queue<pair<int,pair<int,int>>>q; // {dist,{row,col}}
    vector<vector<int>> dist(rows,vector<int>(cols,1e9));
    dist[srow][scol]=0;
    q.push({0,{srow,scol}});

    vector<int>delrow={-1,0,1,0};
    vector<int>delcol={0,1,0,-1};

    while(!q.empty()){
        int dis=q.front().first;
        int row=q.front().second.first;
        int col=q.front().second.second;
        q.pop();

        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<rows && ncol>=0 && ncol<cols && grid[nrow][ncol]==1 && dis+1< dist[nrow][ncol]){
                dist[nrow][ncol]=dis+1;
                if(nrow==drow && ncol==dcol) break;
                q.push({dis+1,{nrow,ncol}});
            }
        }
    }
    return dist[drow][dcol];
    //T.C: O(rows*cols)
    //S.C: O(rows*cols)
}

int main(){
    vector<vector<int>> grid={{1,1,1,1},{1,1,0,1},{1,1,1,1},{1,1,0,0},{1,0,0,0}};
    int srow=0;
    int scol=1;
    int drow=2;
    int dcol=2;
    cout<<ShortestDistanceInBinaryMaze(grid,srow,scol,drow,dcol)<<endl;
    return 0;
}