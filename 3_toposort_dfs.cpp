/*Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that 
for every directed edge u-v, vertex u comes before v in the ordering.*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    // Function to perform DFS and push nodes into the stack in topological order
    void dfs(int node, vector<int>& vis, stack<int>& s, vector<vector<int>>& adj) {
        vis[node] = 1; // Mark the current node as visited
        for (auto i : adj[node]) {
            if (!vis[i]) {
                dfs(i, vis, s, adj); // Visit unvisited neighbors
            }
        }
        s.push(node); // Push the current node onto the stack after processing its neighbors
    }

    // Function to perform topological sorting of the graph
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0); // Visited array to track visited nodes
        vector<int> ans;       // Result vector to store the topological order
        stack<int> s;          // Stack to store nodes in reverse topological order

        // Perform DFS for every unvisited node
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, s, adj);
            }
        }

        // Extract nodes from the stack to get the topological order
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};

// Driver function to test the solution
int main() {
    // Create a directed graph using adjacency list
    vector<vector<int>> adj = {
        {1, 2},  // Node 0 points to nodes 1 and 2
        {2, 3},  // Node 1 points to nodes 2 and 3
        {},      // Node 2 points to no one
        {4},     // Node 3 points to node 4
        {}       // Node 4 points to no one
    };

    Solution sol;
    vector<int> result = sol.topologicalSort(adj);

    // Print the topological order
    cout << "Topological Order: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
