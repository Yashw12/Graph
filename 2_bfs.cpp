#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Perform BFS on the graph represented as an adjacency matrix
void bfs(const vector<vector<int>>& adjMatrix, int startNode) {
    int n = adjMatrix.size();
    vector<bool> visited(n, false); // Track visited nodes
    queue<int> q;                   // Queue for BFS

    // Start BFS from the given node
    visited[startNode] = true;
    q.push(startNode);

    cout << "BFS traversal: ";

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();

        cout << currentNode << " ";

        // Check all neighbors of the current node
        for (int i = 0; i < n; ++i) {
            if (adjMatrix[currentNode][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    cout << endl;
}

int main() {
    // Example adjacency matrix
    vector<vector<int>> adjMatrix = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    int startNode = 0; // Starting node for BFS
    bfs(adjMatrix, startNode);

    return 0;
}
