#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1584 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
 */

// @lc code=start
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //We used an optimized version of Prim's algorithm to find the minimum spanning tree of the graph formed by the points, where the weight of the edge between two points is the Manhattan distance between them.
        // We keep track of the points that are already in the minimum spanning tree and the minimum distance to connect each point to the tree. At each step, we add the point with the minimum distance to the tree and update the distances for the remaining points.
        //We repeat this process until all points are included in the tree, and we return the total cost of connecting all points.
        vector<bool> inMST(points.size(), false);
        vector<int> minDist(points.size(), INT_MAX);
        int totalCost = 0;
        int edgesUsed = 0;
        minDist[0] = 0;
        while(edgesUsed < points.size()){
            int currMinDist = INT_MAX;
            int currNode = -1;
            for(int i = 0; i < points.size(); i++){
                if(!inMST[i] && minDist[i] < currMinDist){
                    currMinDist = minDist[i];
                    currNode = i;
                }
            }

            //at the end of this loop, currMinDist will be the minimum distance to connect a new point to the MST, and currNode will be the index of that point

            inMST[currNode] = true;
            totalCost += currMinDist;
            edgesUsed++;

            //update the minDist array for the remaining points that are not in the MST
            //at each iteration, minDist will get updated to reflect the minimum distance to connect each point to the current MST
            for(int i = 0; i < points.size(); i++){
                if(!inMST[i]){
                    int dist = abs(points[currNode][0] - points[i][0]) + abs(points[currNode][1] - points[i][1]);
                    minDist[i] = min(minDist[i], dist);
                }
            }
        }

        return totalCost;
    }
};
// @lc code=end

