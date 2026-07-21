#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1260 lang=cpp
 *
 * [1260] Shift 2D Grid
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if(k % (grid.size() * grid[0].size()) == 0) return grid;
        k = k % (grid.size() * grid[0].size());

        int total = grid.size() * grid[0].size();
        vector<vector<int>> res(grid.size(), vector<int>(grid[0].size()));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                int oldIdx = i * grid[0].size() + j; //convert 2D index to 1D index
                int newIdx = (oldIdx + k) % total;

                res[newIdx / grid[0].size()][newIdx % grid[0].size()] = grid[i][j];
            }
        }
        return res;

    }
};
// @lc code=end

