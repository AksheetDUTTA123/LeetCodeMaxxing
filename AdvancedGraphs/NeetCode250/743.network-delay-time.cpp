#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */

// @lc code=start
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> minTime(n + 1, INT_MAX); //store minTimes 
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto edge : times){ //map edge to {edge, weight}
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        minTime[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;//store {currMinTime, node}

        pq.push({0, k});

        while(!pq.empty()){
            int currMinDist = pq.top().first;
            int currNode = pq.top().second;

            pq.pop();

            if(currMinDist > minTime[currNode]) continue; //if the current distance is greater than the minimum distance we have already found for this node, we can skip processing it, because we have already found a shorter path to this node

            for(auto neighbor : adj[currNode]){
                int currDist = neighbor.second + currMinDist; //neighbor.second is the weight of the edge from currNode to neighbor.first, and currMinDist is the minimum distance to reach currNode, so currDist is the total distance to reach neighbor.first through currNode

                if(currDist < minTime[neighbor.first]){
                    minTime[neighbor.first] = currDist;
                    pq.push({currDist, neighbor.first});
                }

            }

        }

        int currMinTime = -1;
        for(int i =1; i <= n; i++){
            if(minTime[i] == INT_MAX) return -1;
            currMinTime = max(currMinTime, minTime[i]);
        }
        return currMinTime;

    }
};
// @lc code=end

