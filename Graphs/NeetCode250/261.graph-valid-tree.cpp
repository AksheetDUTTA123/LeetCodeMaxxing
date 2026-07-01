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

        stack<pair<int, int>> st;
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            
        }
        
        unordered_set<int> visited;
        st.push({0, -1}); //store as {curr pos, parent pos}
        visited.insert(0);
        while(!st.empty()){
            auto top = st.top();
            st.pop();
            for(int neighbor : adj[top.first]){
                if(top.second == neighbor) continue;
                if(visited.count(neighbor)) return false;
                visited.insert(neighbor);
                st.push({neighbor, top.first});
            }

        }
        return visited.size() == n;
    }
};
// @lc code=end

