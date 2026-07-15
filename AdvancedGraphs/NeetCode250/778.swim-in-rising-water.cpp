#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=778 lang=cpp
 *
 * [778] Swim in Rising Water
 */

// @lc code=start
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int dRow[4] = {-1, 1, 0, 0};
        int dCol[4] = {0, 0, -1, 1};
        vector<vector<int>> map(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        std::priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        map[0][0] = grid[0][0]; //the minimum time to reach the starting cell is the value of the starting cell itself, because we can only enter a cell when the water level is at least equal to the value of that cell, so we need to wait until the water level reaches that value before we can enter the cell
        pq.push({map[0][0], 0, 0});
        while(!pq.empty()){
            auto [currTime, currRow, currCol] = pq.top();
            pq.pop();
            if(currRow == grid.size() - 1 && currCol == grid[0].size() - 1) return currTime;
            if(currTime > map[currRow][currCol]) continue;

            for(int i = 0; i < 4; i++){
                int newRow = currRow + dRow[i];
                int newCol = currCol + dCol[i];
                int newTime = INT_MAX;

                if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size()){
                    newTime = max(currTime, grid[newRow][newCol]); //we want to take the max of the current time and the new cell's time, because we want to find the minimum time to reach the bottom right corner, and we will update the map with the new time if it is less than the current time in the map
                }

                 if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && newTime < map[newRow][newCol]){ //only push to pq if newTime is less than the current time in the map, because we want to find the minimum time to reach the bottom right corner
                    map[newRow][newCol] = newTime;
                    pq.push({newTime, newRow, newCol});
                 }
            }
        }
        return map[map.size() - 1][map[0].size() - 1];
    }
};
// @lc code=end

