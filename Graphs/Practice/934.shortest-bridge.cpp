#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=934 lang=cpp
 *
 * [934] Shortest Bridge
 */

// @lc code=start
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int dRow[4] = {-1, 1, 0, 0};
        int dCol[4] = {0, 0, -1, 1};

        queue<pair<int, int>> q;
        queue<pair<int, int>> bridgeQ;
        bool found = false;
        for(int i = 0; i < grid.size(); i++){
            if (found) break;
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    grid[i][j] = 2;
                    found = true;
                    break;
                }
            }
        }

        //we found an island, now BFS and find all in the island

        while(!q.empty()){
            auto [currRow, currCol] = q.front();
            q.pop();
            bridgeQ.push({currRow, currCol});
            for(int i = 0; i < 4; i++){
                int newRow = currRow + dRow[i];
                int newCol = currCol + dCol[i];

                if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == 1){
                    q.push({newRow, newCol});
                    grid[newRow][newCol] = 2;
                }
            }
        }
        int dist = 0;
        while(!bridgeQ.empty()){
            int currLayer = bridgeQ.size();
            for(int i = 0; i < currLayer; i ++){
                auto [currRow, currCol] = bridgeQ.front();
                bridgeQ.pop();
                for(int j = 0; j < 4; j++){
                    int newRow = currRow + dRow[j];
                    int newCol = currCol + dCol[j];

                if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size()){
                    if(grid[newRow][newCol] == 1) return dist;
                    else if(grid[newRow][newCol] == 0){
                    bridgeQ.push({newRow, newCol});
                    grid[newRow][newCol] = 2;
                }
                }
                }
            }
            dist++;
        }
        return dist;
    }
};
// @lc code=end

