#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=323 lang=cpp
 *
 * [323] Number of Connected Components in an Undirected Graph
 */

// @lc code=start
class Solution {
private: 
    unordered_set<int> seen;
    void dfs(int i, vector<vector<int>>& adj){
            seen.insert(i);
            for(int neighbor : adj[i]){
                if(!seen.count(neighbor)){
                    dfs(neighbor, adj);
                }
            }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int currCount = 0;
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for(int i= 0; i < n; i++){
            if(!seen.count(i)){
                currCount++;
                dfs(i, adj);
            }
        }
        return currCount;
    }
};
// @lc code=end

