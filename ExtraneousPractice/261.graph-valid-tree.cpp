#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=261 lang=cpp
 *
 * [261] Graph Valid Tree
 */

// @lc code=start
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;
        vector<bool> visited(n + 1, false);

        vector<vector<int>> adj(n);
        int visitedCount = 0;
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            visitedCount++;

            for(int i = 0; i < adj[top].size(); i++){
                if(!visited[adj[top][i]]){
                visited[adj[top][i]] = true;
                q.push(adj[top][i]);
            }
            }
        }
    return visitedCount == n;
    }
};
// @lc code=end

