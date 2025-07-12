#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool dfs(int src, int parent, vector<int>& vis, vector<vector<int>>& adj) {
        vis[src] = 1;

        for (auto &node : adj[src]) {
            if (!vis[node]) {
                if (dfs(node, src, vis, adj)) return true;
            }
            else if (node != parent) { 
                return true; // Cycle detected
            }
        }
        return false;
    }

    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i] && dfs(i, -1, vis, adj)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n);
    cout << "Enter edges (u v) for an undirected graph:\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Since it's an undirected graph
    }

    Solution sol;
    if (sol.isCycle(adj)) {
        cout << "Graph contains a cycle.\n";
    } else {
        cout << "Graph does not contain a cycle.\n";
    }

    return 0;
}
