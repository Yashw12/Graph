// A minimum spanning tree (MST) is defined as a spanning tree that has the minimum weight 
// among all the possible spanning trees.

//A spanning tree should have n nodes and n-1 edges and only 1 component

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void PrismAlgo(vector<vector<int>>& graph,vector<vector<int>>& mst,int &Sum){

    int V = graph.size();
    int E = graph[0].size();

    // Using a priority queue to store edges in ascending order of weight
    // The priority queue will help us efficiently get the minimum weight edge at each step
    // The pair<int, pair<int, int>> structure is used to store the weight and the edge (node, parent)
    // The first element of the pair is the weight of the edge, and the second element is a pair containing the node and its parent.

    priority_queue<
    pair<int,pair<int,int>>,
    vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>>
    > pq;

    pq.push({0,{0,-1}});
    vector<int> vis(V,0);

    while(!pq.empty()){
        int weight = pq.top().first;
        int node   = pq.top().second.first;
        int parent = pq.top().second.second;
        pq.pop();

        if(vis[node]==1) continue;
        
        vis[node] = 1;
        Sum+=weight;

        if(parent!=-1) mst.push_back({node,parent});

       for(int adj=0;adj<V;adj++){
            if (graph[node][adj] != 0 && !vis[adj]) {
                pq.push({graph[node][adj], {adj, node}});
            }        
       }
    }
}





// Driver's code
int main() {
    vector<vector<int>> graph = { { 0, 2, 0, 6, 0 },
                              { 2, 0, 3, 8, 5 },
                              { 0, 3, 0, 0, 7 },
                              { 6, 8, 0, 0, 9 },
                              { 0, 5, 7, 9, 0 } };

                            
  vector<vector<int>> mst;
  int Sum = 0;
  PrismAlgo(graph,mst,Sum);

  cout << "Edges in MST:\n";
  for (auto& edge : mst) {
      cout << edge[0] << " - " << edge[1] << "\n";
  }

  cout << "Total weight of MST: " << Sum << "\n";

  return 0;
}