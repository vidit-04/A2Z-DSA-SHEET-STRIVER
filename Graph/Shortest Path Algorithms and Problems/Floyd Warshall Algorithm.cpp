#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> FloydWarshall(vector<vector<int>> adjList){
    int n = adjList.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adjList[i][j]==-1){
                adjList[i][j]=1e9;
            }
        }
    }
    //For every node k, we check if we can minimize the distance between i and j by including k as intermediate node
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                adjList[i][j]=min(adjList[i][j],adjList[i][k]+adjList[k][j]);
            }
        }
    }

    //If there is a negative cycle then there will be a negative value in the diagonal of the matrix
    // for(int i=0;i<n;i++){
    //     if(adjList[i][i]<0){
    //         cout<<"Negative Cycle Detected"<<endl;
    //         break;
    //     }
    // }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adjList[i][j]==1e9){
                adjList[i][j]=-1;
            }
        }
    }
    return adjList;
    //Time Complexity: O(n^3)
    //Space Complexity: O(n^2)

    //If we are confirm that there are no negative edgeweight then we can use Dijkstra Algorithm to find shortest path between all pairs of vertices its time complexity will be O(v)*O(Elog V)
}

int main(){
    //Floyd Warshall Algorithm is multisource shortest path algorithm
    //It is used to find shortest path between all pairs of vertices in a graph
    //It is also used to detect negative cycle in a graph
    //If given graph is undirected then we can convert it into directed graph by adding reverse edge of each edge
    vector<vector<int>> adjList={{0,1,43},{1,0,6},{-1,-1,0}};
    vector<vector<int>> ans=FloydWarshall(adjList);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}