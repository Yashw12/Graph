#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n = adj.size();

        vector<int> indegree(n, 0);
        vector<int> ans;       // Result vector to store the topological order
        queue<int> q;          // Stack to store nodes in reverse topological order

        for(auto& i:adj){     // Create Indegree i.e no of edges coming in a node
            for(auto& j: i){
                indegree[j]++;
            }
        }
        // Perform DFS for every unvisited node
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Extract nodes from the queue to get the topological order
        while (!q.empty()) {
            int temp = q.front();
            ans.push_back(temp);
            q.pop();
            for(auto& i:adj[temp]){
                indegree[i]--;
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }

        }
        // If the size of the answer vector is not equal to the number of nodes,
        // it indicates that there is a cycle in the graph.
        if (ans.size() != n) {
            cout << "The graph contains a cycle!" << endl;
            return {};
        }
        // If the graph is acyclic, return the topological order
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