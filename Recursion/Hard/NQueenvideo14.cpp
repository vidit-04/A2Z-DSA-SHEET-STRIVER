#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<string>board,int row,int col,int n){
    int dupRow=row;
    int dupCol=col;

    while(row>=0 && col>=0){
        if(board[row--][col--]=='Q') return false;
    }
    row=dupRow;
    col=dupCol;
    while(col>=0){
        if(board[row][col--]=='Q') return false;
    }
    row=dupRow;
    col=dupCol;
    while(row<n && col>=0){
        if(board[row++][col--]=='Q') return false;
    }
    return true;
}

void solve(vector<vector<string>>&ans,vector<string>&board,int n,int col){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(board,row,col,n)){
            board[row][col]='Q';
            solve(ans,board,n,col+1);
            board[row][col]='.';
        }
    }
}

void Nqueen(vector<vector<string>> &ans,vector<string> 
    &board,vector<int> &leftRow,vector<int>&upperDiagonal,vector<int>&lowerDiagonal,int col,int n){
    //OPTIMIZED
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+col-row]==0){
            board[row][col]='Q';
            leftRow[row]=1;
            lowerDiagonal[row+col]=1;
            upperDiagonal[n-1+col-row]=1;
            Nqueen(ans,board,leftRow,upperDiagonal,lowerDiagonal,col+1,n);
            board[row][col]='.';
            leftRow[row]=0;
            lowerDiagonal[row+col]=0;
            upperDiagonal[n-1+col-row]=0;
        }
    }
}


int main(){
    int n=4;
    vector<vector<string>>ans;
    vector<string> board(n);
    string s(n,'.');
    for(int i=0;i<board.size();i++){
        board[i]=s;
    }
    // vector<int>leftRow(n,0),upperDiagonal(2*n-1,0), lowerDiagonal(2*n-1,0);
    // Nqueen(ans,board,leftRow,upperDiagonal,lowerDiagonal,0,n);
    solve(ans,board,n,0);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<endl;
        }
    }
    return 0;
}