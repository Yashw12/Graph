#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfshelper(int start,vector<vector<int>>& adjMatrix,vector<int>& vis){
       vis[start] = 1;
       cout<< start << " ";
       for(int i=0;i<adjMatrix.size();i++){
            if(adjMatrix[start][i]==1 && !vis[i]){
                dfshelper(i,adjMatrix,vis);
            }
       }
}

void dfs(vector<vector<int>>& adjMatrix){
    int n = adjMatrix.size();
    vector<int> vis(n,0);
    int start = 0;
    cout << "dfs traversal :";
    dfshelper(start,adjMatrix,vis);
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

    dfs(adjMatrix);
    cout << endl; 
    return 0;
}