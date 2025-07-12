#include<iostream>
#include<vector>

using namespace std;

class solutions{
    public:
    int time = 0;
    void dfs(vector<int> &vis,vector<int> &ap,vector<int> &low,
        vector<int> &disc,int parent,int src,vector<vector<int>> &adj){
         
        vis[src] = 1;
        low[src] = disc[src] = time;
        time++;
        int child = 0; // Count of children for the current node
        
        for(auto neighbour:adj[src]){
            if(neighbour == parent) continue;
            if(!vis[neighbour]){
                child++;
                dfs(vis,ap,low,disc,src,neighbour,adj);
                low[src] = min(low[src],low[neighbour]);
                if(low[neighbour]>=disc[src] && parent!=-1){
                    ap[src] = 1;
                }
            }
            else{
                low[src] = min(low[src],disc[neighbour]);
            }
        }
        // If the current node is the root and has more than one child, it is an articulation point
        if(parent == -1 && child > 1){
            ap[src] = 1;
        }
    }
};

int main(){
    vector<vector<int>> adj = {
        {1, 3, 4},  // Node 0 points to nodes 1, 3, and 4
        {0, 2, 3},  // Node 1 points to nodes 0, 2, and 3
        {1, 5},     // Node 2 points to nodes 1 and 5
        {1, 4},     // Node 3 points to node 4
        {0, 3},     // Node 4 points to no one
        {2, 6},     // Node 5 points to node 6
        {5, 7},     // Node 6 points to node 5 and 7
        {6, 5, 8},  // Node 7 points to node 6, 5 and 8
        {7, 9, 10}, // Node 8 points to node 7, 9 and 10
        {8, 10},    // Node 9 points to node 8 and 10
        {8, 9}      // Node 10 points to node 8 and 9
  };
    int n = adj.size();
    vector<int> vis(n, 0); // Visited array to track visited nodes
    vector<int> ap(n,0);        // Vector to store articulation points
    vector<int> low(n, 0); // Low values for articulation point detection
    vector<int> disc(n, 0); // Discovery times of visited vertices
    vector<int> parent(n,-1);
    solutions sol;
    sol.dfs(vis,ap,low,disc,-1,0,adj);
    cout << "Articulation Points in the graph are:\n";
    for(int i=0;i<n;i++){
        if(ap[i]) cout<<"Articulation point found at: "<<i<<endl;
    }
    return 0;
}