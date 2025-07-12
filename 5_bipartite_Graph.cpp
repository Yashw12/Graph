/*Bipartite graphs are graphs that can be colored using two colors such 
that no two adjacent vertices share the same color.*/

/*Intuition: We can use DFS or BFS to color the graph. Start from any uncolored node, 
color it with one color, and then color all its adjacent nodes with the other color. 
If we ever find a node that is already colored with the same color as the current node, 
then the graph is not bipartite.*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool dfs(int src, vector<int>& vis, vector<vector<int>>& graph) {
        if (vis[src] == -1) vis[src] = 0; // Assign first color
        
        for (auto i : graph[src]) {
            if (vis[i] == -1) { // If not visited, color it with opposite color
                vis[i] = !vis[src];
                if (!dfs(i, vis, graph)) return false;
            }
            else if (vis[i] == vis[src]) return false; // Conflict in coloring
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1); // -1 means unvisited

        for (int i = 0; i < n; i++) {
            if (vis[i] == -1 && !dfs(i, vis, graph)) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    
    // Example: Graph represented as adjacency list
    vector<vector<int>> graph1 = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    vector<vector<int>> graph2 = {
        {1, 2, 3},
        {0, 2},
        {0, 1, 3},
        {0, 2}
    };

    cout << "Graph 1 is Bipartite: " << (sol.isBipartite(graph1) ? "Yes" : "No") << endl;
    cout << "Graph 2 is Bipartite: " << (sol.isBipartite(graph2) ? "Yes" : "No") << endl;

    return 0;
}
