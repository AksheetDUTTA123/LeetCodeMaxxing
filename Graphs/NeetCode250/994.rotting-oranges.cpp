#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int minMinutes = 0;
        int dRow[4] = {-1, 1, 0 , 0};
        int dCol[4] = {0, 0, -1, 1};

        queue<pair<int, int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()){
            int currsize = q.size();
            bool rottedThisTime = false;
            for(int iterations = 0; iterations < currsize; iterations++){
                auto top = q.front();
                q.pop();
            
            for(int idx = 0; idx < 4; idx++){
                int currRow = top.first + dRow[idx];
                int currCol = top.second + dCol[idx];

                while(currRow >= 0 && currRow < grid.size() && currCol >= 0 && currCol < grid[0].size() && grid[currRow][currCol] == 1){
                    grid[currRow][currCol] = 2;
                    rottedThisTime = true;
                    q.push({currRow, currCol});
                }
            }
        }
        if(rottedThisTime){
         minMinutes++;
        }
        }


        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return minMinutes;
    }
};
// @lc code=end

