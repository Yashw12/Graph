
/* Intuition: Dijkstra's algorithm is used to find the shortest path from a source node to all other nodes in a weighted graph. 
It works by maintaining a priority queue of nodes to explore, always expanding the least costly node first. */

/* Algorithm Steps:
1. Initialize a distance array with infinity for all nodes except the source.
2. Use a priority queue to explore the graph, starting from the source node.
3. For each node, update the distances to its neighbors if a shorter path is found.
4. Continue until all nodes are processed or the queue is empty.
5. Return the distance array containing the shortest paths from the source. */

/*Queue also works in unweighted graphs, where all edges have the same weight. 
In this case, we can use a simple BFS approach to find the shortest path. */


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
    vector<int> Dijikstra(vector<vector<pair<int,int>>>& adj,int src){
        
        int n  = adj.size();
        vector<int> dis(n,1e9);
        dis[src] = 0;
        queue<pair<int,int>> q;
        //priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        q.push({src,0});

        while(!q.empty()){
            int node = q.front().first;
            int currdis = q.front().second;
            q.pop();
             
            for(auto i:adj[node]){
                int nxtnode = i.first;
                int weight = i.second;
                int l = currdis+weight;

                if(dis[nxtnode]>l){
                    dis[nxtnode] = l;
                    q.push({nxtnode,l});
                }
            }
        }
        return dis;
    }
};

int main() {
    Solution sol;

    int n = 5; // Number of nodes
    vector<vector<pair<int,int>>> adj(n);

    // Define the graph
    adj[0].push_back({1, 2});
    adj[0].push_back({4, 1});
    adj[1].push_back({2, 3});
    adj[2].push_back({3, 6});
    adj[4].push_back({2, 2});
    adj[4].push_back({3, 4});

    int src = 0;
    vector<int> result = sol.Dijikstra(adj, src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < result.size(); ++i) {
        cout << "To node " << i << ": " << result[i] << "\n";
    }

    return 0;
}
