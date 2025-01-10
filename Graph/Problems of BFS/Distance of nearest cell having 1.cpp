#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> DistanceOfNearest1(vector<vector<int>>& adj){
    int n = adj.size();
    int m = adj[0].size();
    vector<vector<int>> ans(n,vector<int>(m,0));
    vector<vector<int>> vis(n,vector<int>(m,0));

    queue<pair<pair<int,int>,int>> q; //{{row,col},distance}
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(adj[i][j]==1){
                q.push({{i,j},0});
                vis[i][j]=1;
            }
        }
    }

    vector<int>delrow={-1,0,1,0};
    vector<int>delcol={0,1,0,-1};

    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int dist=q.front().second;
        q.pop();

        ans[row][col]=dist;
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
                q.push({{nrow,ncol},dist+1});
                vis[nrow][ncol]=1;
            }
        }
    }
    return ans;
    //T.C>->O(N*M)
    //S.C.->O(N*M)
}

int main(){
    vector<vector<int>> adj={
        {0,0,0},
        {0,1,0},
        {1,0,1}
    };
    vector<vector<int>> ans=DistanceOfNearest1(adj);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}