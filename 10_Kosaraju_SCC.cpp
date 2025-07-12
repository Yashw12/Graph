#include <iostream>
#include <vector>
using namespace std;
// Kosaraju's algorithm for finding strongly connected components (SCCs)
class solution {
public:
    int count = 0;
    void dfs1(stack<int>& S,vector<vector<int>>& adj,int src,vector<int>& vis){
        vis[src] = 1;
        // Perform DFS and push nodes onto the stack in finishing order
        // This is the first pass of Kosaraju's algorithm
        // It explores all reachable nodes from the source node and marks them as visited.
        // After visiting all nodes reachable from the source, it pushes the source node onto the stack
        // to maintain the finishing order.
        // The stack will be used later to process nodes in reverse finishing order.
        for(auto j:adj[src]){
            if(!vis[j]){
                dfs1(S,adj,j,vis);
            }
        }
        S.push(src);
    }
    vector<int>revdfs(int node,vector<vector<int>>& revadj,vector<int>& vis,vector<int>& temp){
        vis[node] = 1;
        // Perform DFS on the reversed graph
        // This is the second pass of Kosaraju's algorithm
        // It explores all nodes reachable from the current node in the reversed graph
        temp.push_back(node);
        for(auto i:revadj[node]){
            if(!vis[i]){
                revdfs(i, revadj, vis, temp);
            }
        }
        return temp; // Return the component found in this DFS
    }
    
    vector<vector<int>> kosaraju(vector<vector<int>>& adj,int n){
        vector<vector<int>> sccs; // To store strongly connected components
        stack<int> S;   // Stack to store nodes in finishing order
        vector<int> vis(n,0);   // Visited array to track visited nodes

        // First pass: Perform DFS and fill the stack with nodes in finishing order
        for(auto i:vis){
            if(!vis[i]){
                dfs1(S,adj,i,vis);
            }
        }

        fill(vis.begin(),vis.end(),0);  // Reset visited array for the second pass
        vector<vector<int>> revadj(n);  // Reversed adjacency list for the second pass
        for(int i=0;i<n;i++){
            for(auto j:adj[i]){
                revadj[j].push_back(i); // Reverse the edges
            }
        }
        
        while(!S.empty()){
            int node = S.top();
            S.pop();

            if(!vis[node]){
                count++;
                vector<int> temp;
                revdfs(node,revadj,vis,temp);
                sccs.push_back(temp);
            }
        }
        return sccs;
    }

};

int main(){
    vector<vector<int>> adj = {
        {1},       // Node 0 points to node 1
        {2},       // Node 1 points to node 2
        {0, 3},    // Node 2 points to nodes 0 and 3
        {4},       // Node 3 points to node 4
        {5},       // Node 4 points to node 5
        {3}        // Node 5 points back to node 3
    };
    // Example directed graph with 6 nodes (0 to 5)
    int n = adj.size();
    solution sol;

    vector<vector<int>> sccs = sol.kosaraju(adj, n); 

    cout << "Number of strongly connected components (SCCs): " << sol.count << endl;
    cout << "Strongly connected components (SCCs):" << endl;
    for (const auto& scc : sccs) {
        for (int node : scc) {
            cout << node << " ";
        }
        cout << endl;
    }   
    cout << "Kosaraju's algorithm for finding strongly connected components (SCCs) in a directed graph." << endl;
    return 0;
}