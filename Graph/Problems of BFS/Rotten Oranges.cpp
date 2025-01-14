#include<bits/stdc++.h>
using namespace std;

int RottenOranges(vector<vector<int>> matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    int cntFresh=0;

    queue<pair<pair<int,int>,int>> q;  //{{row,col},time}
    vector<vector<int>> visited(n,vector<int>(m,0));
    for(int row=0;row<n;row++){
        for(int col=0;col<m;col++){
            if(matrix[row][col]==2){
                q.push({{row,col},0});
                visited[row][col]=2;
            }
            else if(matrix[row][col]==1){
                cntFresh++;
            }
        }
    }
    
    vector<int>delrow={-1,0,+1,0};
    vector<int>delcol={0,+1,0,-1};
    int time=0;
    int cnt=0;
    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int t=q.front().second;
        time=max(time,t);
        q.pop();

        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && matrix[nrow][ncol]==1 && visited[nrow][ncol]==0){
                visited[nrow][ncol]=2;
                q.push({{nrow,ncol},t+1});
                cnt++;
            }
        }
            
        
    }
    // for(int row=0;row<n;row++){
    //     for(int col=0;col<m;col++){
    //         if(visited[row][col]!=2 && matrix[row][col]==1) return -1;
    //     }
    // }

    if(cntFresh!=cnt) return -1;
    return time;
    //T.C.-O(n*m)
    //SC-O(n*m)
}

int main(){
    vector<vector<int>> matrix={{0,1,2},{0,1,2},{2,1,1}};
    cout<<RottenOranges(matrix);
    return 0;
}