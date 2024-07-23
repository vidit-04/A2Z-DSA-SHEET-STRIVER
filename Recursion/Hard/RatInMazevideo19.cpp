#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>a,vector<string> &ans,vector<vector<int>> &vis,int n,int i,int j,string move){
    if(i==n-1 && j==n-1){
        ans.push_back(move);
        return;
    }
    //downward
    if(i+1<n && !vis[i+1][j] && a[i+1][j]==1){
        vis[i][j]=1;
        solve(a,ans,vis,n,i+1,j,move+'D');
        vis[i][j]=0;
    }
    //left
    if(j-1>=0 && !vis[i+1][j] && a[i][j-1]==1){
        vis[i][j]=1;
        solve(a,ans,vis,n,i,j-1,move+'L');
        vis[i][j]=0;
    }
    //right
    if(j+1<n && !vis[i+1][j] && a[i][j+1]==1){
        vis[i][j]=1;
        solve(a,ans,vis,n,i,j+1,move+'L');
        vis[i][j]=0;
    }
    //upward
    if(i-1>=0 && !vis[i+1][j] && a[i-1][j]==1){
        vis[i][j]=1;
        solve(a,ans,vis,n,i-1,j,move+'U');
        vis[i][j]=0;
    }

}

int main(){
    vector<vector<int>>a={{1,0,0,0},{1,1,0,0},{1,1,0,0},{0,1,1,1}};
    int n=a.size();
    vector<string>ans;
    vector<vector<int>> vis(n,vector<int>(n,0));
    if(a[0][0]==1) solve(a,ans,vis,n,0,0,"");
    for(auto i:ans){
        cout<<i<<endl;
    }
    return 0;
}