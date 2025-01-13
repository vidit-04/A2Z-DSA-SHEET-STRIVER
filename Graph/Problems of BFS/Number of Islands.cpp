#include <bits/stdc++.h>
using namespace std;

// Helper function to perform BFS traversal
void bfs(int n, int m, int row, int col, vector<vector<int>> &grid, vector<vector<int>> &visited) {
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = 1;

    while (!q.empty()) {
        int currRow = q.front().first;
        int currCol = q.front().second;
        q.pop();

        // Loop to traverse in 8 directions
        for (int delRow = -1; delRow <= 1; delRow++) {
            for (int delCol = -1; delCol <= 1; delCol++) {
                int newRow = currRow + delRow;
                int newCol = currCol + delCol;

                // Check bounds and if the cell is land and unvisited
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    grid[newRow][newCol] == 1 && !visited[newRow][newCol]) {
                    visited[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }
}

// Function to count the number of islands
int numOfIslands(int n, int m, vector<vector<int>> &grid) {
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int islandCount = 0;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            // If the cell is land and not visited, start a new BFS
            if ( !visited[row][col] && grid[row][col] == 1) {
                islandCount++;
                bfs(n, m, row, col, grid, visited);
            }
        }
    }
    return islandCount;
    //T.C.-O(n^2)
    //S.C.-O(n^2)+O(n^2)
}

int main() {
    vector<vector<int>> grid = {
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 1}
    };

    cout << numOfIslands(5, 4, grid) << endl;
    return 0;
}
