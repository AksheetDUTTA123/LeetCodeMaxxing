#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1514 lang=cpp
 *
 * [1514] Path with Maximum Probability
 */

// @lc code=start
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }
        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            if(top.second == end_node) return top.first;

            if(top.first < maxProb[top.second]) continue;


            for(auto neighbor : adj[top.second]){
                double currProb = neighbor.second * top.first;

                if(currProb > maxProb[neighbor.first]){
                    maxProb[neighbor.first] = currProb;
                    pq.push({currProb, neighbor.first});
                }
            }

        }

        return 0.0;
    }
};
// @lc code=end

