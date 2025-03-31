#include<bits/stdc++.h>
using namespace std;

int func(vector<vector<int>>& grid, int& n, int& m, int row, int col1, int col2,vector<vector<vector<int>>>& dp) {
    if(col1<0 || col1>=m || col2<0 || col2>=m) return -1e8;
    if(row==n-1) {
        if(col1==col2) return grid[row][col1];
        else return grid[row][col1]+grid[row][col2];
    }
    if(dp[row][col1][col2]!=-1) return dp[row][col1][col2];
    int maxi=0;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(col1==col2) maxi= max(maxi,grid[row][col1]+func(grid,n,m,row+1,col1+i,col2+j,dp));
            else maxi= max(maxi,grid[row][col1]+grid[row][col2]+func(grid,n,m,row+1,col1+i,col2+j,dp));
        }
    }
    return dp[row][col1][col2]=maxi;
}

int tabulation(int n,int m, vector<vector<int>>& grid){
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1e9)));
    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2) dp[n-1][j1][j2]=grid[n-1][j1];
            else dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
        }
    }
    for(int i=n-2;i>=0;i--){
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                int maxi=INT_MIN;
                for(int x=-1;x<=1;x++){
                    for(int y=-1;y<=1;y++){
                        int value=0;
                        if(j1==j2) value= grid[i][j1];
                        else value= grid[i][j1]+grid[i][j2];
                        
                        if(j1+x>=0 && j1+x<m && j2+y>=0 && j2+y<m){
                            value+=dp[i+1][j1+x][j2+y];
                        }
                        else value+=-1e8;
                        maxi=max(maxi,value);
                    }
                }
                dp[i][j1][j2]=maxi;
            }
        }
    }
    return dp[0][0][m-1];
}

int solve(int n, int m, vector<vector<int>>& grid) {
    // vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
    // return func(grid, n, m, 0, 0, m - 1,dp);
    return tabulation(n,m,grid);
}

int main(){
    int n=4,m=3;
    vector<vector<int>>grid={{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    cout<<solve(n,m,grid)<<endl;
    return 0;
}