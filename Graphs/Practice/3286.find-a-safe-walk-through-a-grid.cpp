#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3286 lang=cpp
 *
 * [3286] Find a Safe Walk Through a Grid
 */

// @lc code=start
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();   
        int n = grid[0].size();
        int dRow[4] = {-1, 1, 0, 0};
        int dCol[4] = {0, 0, -1, 1};

        queue<tuple<int, int, int>> q;
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(health + 1, false)));

        q.push({0, 0, health - grid[0][0]});
        if (health - grid[0][0] <= 0) return false; 
        visited[0][0][health - grid[0][0]] = true;

        while (!q.empty()){
            auto [first, second, third] = q.front();
            q.pop();

            if(first == grid.size() - 1 && second == grid[0].size() - 1 && third > 0){
                return true;
            }

            for(int idx = 0; idx < 4; idx++){
                int currRow = first + dRow[idx];
                int currCol = second + dCol[idx];


                if(currRow >= 0 && currRow < grid.size() && currCol >= 0 && currCol < grid[0].size() && third - grid[currRow][currCol] > 0 && visited[currRow][currCol][third - grid[currRow][currCol]] == false){
                    int currHealth = third - grid[currRow][currCol];
                    visited[currRow][currCol][currHealth] = true;
                    q.push({currRow, currCol, currHealth});
                }
            }
        }
        return false;
    }
};
// @lc code=end

