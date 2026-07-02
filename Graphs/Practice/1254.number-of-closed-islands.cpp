#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1254 lang=cpp
 *
 * [1254] Number of Closed Islands
 */

// @lc code=start
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for(int i = 0; i < grid.size();i++){
            if(grid[i][0]  == 0){
                grid[i][0] = -1;
                q.push({i, 0});
            }
        }
        for(int i = 0; i < grid[0].size();i++){
            if(grid[0][i]  == 0){
                grid[0][i] = -1;
                q.push({0, i});
            }
        }
        for(int i = 0; i < grid.size();i++){
            if(grid[i][grid[0].size() - 1]  == 0){
                grid[i][grid[0].size() - 1] = -1;
                q.push({i, grid[0].size() - 1});
            }
        }
        for(int i = 0; i < grid[0].size();i++){
            if(grid[grid.size() - 1][i]  == 0){
                grid[grid.size() - 1][i] = -1;
                q.push({grid.size() - 1, i});
            }
        }

        int dRow[4] = {-1, 1, 0, 0};
        int dCol[4] = {0, 0, -1, 1};

        int closedIsland = 0;


        while(!q.empty()){
            auto top = q.front();
            q.pop();
            for(int idx = 0; idx < 4; idx++){
                int currRow = top.first + dRow[idx];
                int currCol = top.second + dCol[idx];


                if(currRow >= 0 && currRow < grid.size() && currCol >= 0 && currCol < grid[0].size() && grid[currRow][currCol] == 0){
                    grid[currRow][currCol] = -1;
                    q.push({currRow, currCol});
                }
            }
        }

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0) {
                    closedIsland++;
                //need to do another bfs
                queue<pair<int, int>> islandQ;
                islandQ.push({i, j});
                grid[i][j] = -1;

                while(!islandQ.empty()){
                    auto top = islandQ.front();
                    islandQ.pop();
                    for(int idx = 0; idx < 4; idx++){
                        int currRow = top.first + dRow[idx];
                        int currCol = top.second + dCol[idx];


                if(currRow >= 0 && currRow < grid.size() && currCol >= 0 && currCol < grid[0].size() && grid[currRow][currCol] == 0){
                    grid[currRow][currCol] = -1;
                    islandQ.push({currRow, currCol});
                }
                    }
            }
                }

            }
        }

        return closedIsland;
    }
};
// @lc code=end

