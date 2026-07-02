#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=323 lang=cpp
 *
 * [323] Number of Connected Components in an Undirected Graph
 */

// @lc code=start

class UnionFind{
    private:
        vector<int> parent;
        vector<int> rank;
    public:
        UnionFind(int n){
            parent.resize(n);
            rank.resize(n, 0);
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int i){
            //path compression
            if(parent[i] == i) return i;
            return parent[i] = find(parent[i]);
        }

        bool unite(int i , int j){
            int rootI = find(i);
            int rootJ = find(j);

            if(rootI == rootJ) return false; //alr in same component

            if(rank[rootI] < rank[rootJ]){
                parent[rootI] = rootJ;
            }
            else if(rank[rootI] > rank[rootJ]){
                parent[rootJ] = rootI;
            }
            else{
                parent[rootJ] = rootI;
                rank[rootI]++;
            }
            return true;
        }

};
class Solution {

    //this is the dfs solution, but can be optimized by doing Union Find
// private: 
//     unordered_set<int> seen;
//     void dfs(int i, vector<vector<int>>& adj){
//             seen.insert(i);
//             for(int neighbor : adj[i]){
//                 if(!seen.count(neighbor)){
//                     dfs(neighbor, adj);
//                 }
//             }
//     }
// public:
//     int countComponents(int n, vector<vector<int>>& edges) {
//         int currCount = 0;
//         vector<vector<int>> adj(n);
//         for(auto edge : edges){
//             adj[edge[0]].push_back(edge[1]);
//             adj[edge[1]].push_back(edge[0]);
//         }
//         for(int i= 0; i < n; i++){
//             if(!seen.count(i)){
//                 currCount++;
//                 dfs(i, adj);
//             }
//         }
//         return currCount;
//     }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind dsu(n);
        int components = n;

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            if(dsu.unite(u,v)) components--;
        }
        return components;
    }
};
// @lc code=end

