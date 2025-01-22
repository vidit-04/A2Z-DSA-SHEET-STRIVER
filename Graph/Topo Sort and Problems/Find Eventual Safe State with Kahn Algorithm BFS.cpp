#include <bits/stdc++.h>
using namespace std;

vector<int> eventualSafeNodes(int n, vector<vector<int>>& graph) {
    // Step 1: Reverse the graph
    vector<vector<int>> adjRev(n);
    vector<int> indegree(n, 0);
    
    for (int i = 0; i < n; i++) {
        //i -> it
        //it -> i
        for (auto it : graph[i]) {
            adjRev[it].push_back(i);
            indegree[i]++;
        }
    }

    // Step 2: Topological Sort
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> safeNodes;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        safeNodes.push_back(node);

        for (int neighbor : adjRev[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) q.push(neighbor);
        }
    }

    // Step 3: Sort the result for output
    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
}

int main() {
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    vector<int> safeNodes = eventualSafeNodes(graph.size(), graph);
    // Answer to why reverse the graph:
    // Reversing the graph in this problem ensures that we process the problem backward to identify nodes that eventually lead to a terminal state (i.e., nodes with no outgoing edges in the original graph). This way, we turn the problem into finding nodes with no incoming edges in the reversed graph, allowing us to use topological sorting.

    //As we know topological sort works for those node which have indegree 0 so to identify terminal nodes which dont lead to any cycle we reverse the graph and then apply topological sort

    for (int node : safeNodes) {
        cout << node << " ";
    }
    return 0;
}
