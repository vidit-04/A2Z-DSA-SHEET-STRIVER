#include<bits/stdc++.h>
using namespace std;

void dfs(int row,int col, vector<vector<char>>& adj, vector<vector<int>>& vis){
    vis[row][col]=1;
    int n=adj.size();
    int m=adj[0].size();
    vector<int>delrow={-1,0,1,0};
    vector<int>delcol={0,1,0,-1};
    for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && adj[nrow][ncol]=='O' && !vis[nrow][ncol]){
            dfs(nrow,ncol,adj,vis);
        }
    }
}

vector<vector<char>> Replace(vector<vector<char>>& adj){
    int n = adj.size();
    int m = adj[0].size();
    vector<vector<char>> ans=adj;
    vector<vector<int>> vis(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i==0 || i==n-1 || j==0 || j==m-1) && adj[i][j]=='O' && !vis[i][j]){
                dfs(i,j,adj,vis);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(adj[i][j]=='O' && !vis[i][j]){
                ans[i][j]='X';
            }
        }
    }
    return ans;
}

int main(){
    //FROM BOUNDARY WE FIND O'S AND THEN WE DO DFS ON THEM AND MARK THEM AS VISITED
    //THEN WE TRAVERSE THE WHOLE MATRIX AND IF WE FIND O'S WHICH ARE NOT VISITED THEN WE MARK THEM AS X
    vector<vector<char>> adj={
        {'X','X','X','X','X'},
        {'X','O','O','X','O'},
        {'X','X','O','X','O'},
        {'X','O','X','O','X'},
        {'O','O','X','X','X'}
        };
    vector<vector<char>> ans=Replace(adj);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}