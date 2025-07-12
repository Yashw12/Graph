/*Floyd-Warshall Algorithm: Finding Shortest Paths in a Weighted Graph*/

/*Intuition: The Floyd-Warshall algorithm is a dynamic programming approach 
to find the shortest paths between all pairs of nodes in a weighted graph. 
It works by iteratively improving the path lengths using intermediate nodes.*/

#include <iostream>
#include <vector>
#include <climits> 
const int INF = 1e9;
using namespace std;

class solution {
public:
    vector<vector<int>> floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] == INF || dist[k][j] == INF) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        return dist;
    }
};

int main() {
    // Example graph with 4 nodes (0 to 3)

    vector<vector<int>> graph = {
        {0,     3,     INF,   7},
        {8,     0,     2,     INF},
        {5,     INF,   0,     1},
        {2,     INF,   INF,   0}
    };

    solution sol;
    vector<vector<int>> shortestPaths = sol.floydWarshall(graph);

    cout << "All pairs shortest paths:" << endl;
    for (const auto& row : shortestPaths) {
        for (int val : row) {
            if (val == INF)
                cout << "INF ";
            else
                cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
