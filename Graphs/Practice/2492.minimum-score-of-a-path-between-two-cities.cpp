#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=2492 lang=cpp
 *
 * [2492] Minimum Score of a Path Between Two Cities
 */

// @lc code=start
class Solution {
private:
    unordered_set<int> seen;
    int minVal = INT_MAX;
    void dfs(int i, vector<vector<pair<int, int>>>& adj){
        seen.insert(i);
        for(auto& [neighbor, distance] : adj[i]){
            if(distance < minVal) minVal = distance;
            if(!seen.count(neighbor)){
                dfs(neighbor, adj);
            }
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto edge : roads){
        int u = edge[0];
        int v = edge[1];
        int dist = edge[2];
        
        adj[u].push_back({v, dist});
        adj[v].push_back({u, dist});
        }

       dfs(1, adj); //for this question, we can start the dfs from city 1, and find the minimum distance of all the edges in the connected component that contains city 1. 
       //Since we are guaranteed that there is a path between city 1 and city n, we can just find the minimum distance of all the edges in the connected component that contains city 1, and return that as the answer.

       //dont need to loop thorugh all cities, because if a city is not connected to city 1, then it cannot be part of the path from city 1 to city n, so we can just ignore it.
    return minVal;
    }

};
// @lc code=end

