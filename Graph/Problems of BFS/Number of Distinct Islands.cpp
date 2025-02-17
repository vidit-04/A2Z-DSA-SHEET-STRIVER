#include<bits/stdc++.h>
using namespace std;

void bfs(int row,int col,vector<vector<int>>& matrix,vector<vector<int>>& visited,set<vector<pair<int,int>>>& s,vector<int>& delrow,vector<int>& delcol,int n,int m){
    queue<pair<int,int>> q;
    q.push({row,col});
    visited[row][col]=1;
    vector<pair<int,int>> v;
    while(!q.empty()){
        int currRow=q.front().first;
        int currCol=q.front().second;
        q.pop();
        v.push_back({currRow-row,currCol-col});
        for(int i=0;i<4;i++){
            int nRow=currRow+delrow[i];
            int nCol=currCol+delcol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && matrix[nRow][nCol]==1 && !visited[nRow][nCol]){
                visited[nRow][nCol]=1;
                q.push({nRow,nCol});
            }
        }
    }
    s.insert(v);
}

//THhis way you can avoid the extra space of queue
// void bfs2(int row,int col,vector<vector<int>>& matrix,vector<vector<int>>& visited,set<vector<pair<int,int>>>& s,vector<int>& delrow,vector<int>& delcol,int n,int m,int row0,int col0){
//     visited[row][col]=1;
//     vector<pair<int,int>> v;
//     v.push_back({row-row0,col-col0});
//     for (int i = 0; i < 4; i++){
//         int nRow=row+delrow[i];
//         int nCol=col+delcol[i];
//         if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && matrix[nRow][nCol]==1 && !visited[nRow][nCol]){
//             bfs2(nRow,nCol,matrix,visited,s,delrow,delcol,n,m,row0,col0);
//         }
//     }
//     s.insert(v);
// }

int numDistinctIslands(vector<vector<int>>& matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    set<vector<pair<int,int>>> s;
    vector<int>delrow={-1,0,+1,0};
    vector<int>delcol={0,+1,0,-1};
    vector<vector<int>> visited(n,vector<int> (m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==1 && !visited[i][j]){
                bfs(i,j,matrix,visited,s,delrow,delcol,n,m);
            }
        }
    }
    return s.size();
    //T.C>-O(n*m)+O(n*m*4)
    //S.C.-O(n*m)+O(n*m)
}

int main(){
    vector<vector<int>> matrix={
        {1, 1, 0, 1, 1},
            {1,0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}};
    cout<<numDistinctIslands(matrix);
    return 0;
}