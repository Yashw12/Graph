#include <stdio.h>
#include<iostream>
#include <vector>
using namespace std;
class DisjointSet {
    vector<int> rank, parents,size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1);
        parents.resize(n+1);
        for(int i=0;i<=n;i++){
            parents[i]=i;
            size[i]=1;
        }
    }    

    int findUPar(int node){
        if(node==parents[node]) return node;
        return parents[node] = findUPar(parents[node]);
    }

    void unionByRank(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parents[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v]< rank[ulp_u]){
            parents[ulp_v] = ulp_u;
        }
        else{
            parents[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parents[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parents[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
int main() {
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);  
    ds.unionByRank(5,6); 

    if(ds.findUPar(3)==ds.findUPar(7)){
        cout << "Same\n";
    }else cout << "Not\n";

    ds.unionByRank(3,7);

    if(ds.findUPar(3)==ds.findUPar(7)){
        cout << "Same\n";
    }else cout << "Not\n";    

    return 0;
}