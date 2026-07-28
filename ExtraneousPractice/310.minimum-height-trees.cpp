#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //key detail for this problem, we need to find the roots that cannot be leaves
        //USE KAHNS ALGO TOP SORT FOR THIS TO FIND ROOTS THAT CANNOT HAVE DEGREE BELOW 2
        vector<int> degree(n, 0);
        if(n == 1) return {0};
        vector<vector<int>> adj(n);
        queue<int> q;
        vector<int> res;
        int remainingEdges = n;
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        for(int i = 0; i < degree.size(); i++){
            if(degree[i] == 1) q.push(i);
        }

        while(remainingEdges > 2){
            int currNodes = q.size();
            remainingEdges -= currNodes;

            for(int i = 0; i < currNodes; i++){
                auto top = q.front();
                q.pop();

                for(auto edj : adj[top]){
                    degree[edj]--;
                    if(degree[edj] == 1) q.push(edj);
        }

            }
        }

        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }

        return res;
    }
};
// @lc code=end

