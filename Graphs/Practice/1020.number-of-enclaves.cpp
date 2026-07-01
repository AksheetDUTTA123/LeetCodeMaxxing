#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 */

// @lc code=start
class Solution {

public:
    int numEnclaves(vector<vector<int>>& grid) {
    int ctr = 0;
    queue<pair<int, int>> q;
    for(int i = 0; i < grid.size(); i++){
        if(grid[i][0] == 1){
            q.push({i, 0});
            grid[i][0] = -1;
        }
    }
        for(int i = 0; i < grid[0].size(); i++){
        if(grid[0][i] == 1){
            q.push({0, i});
            grid[0][i] = -1;
        }
    }      
        for(int i = 0; i < grid.size(); i++){
        if(grid[i][grid[0].size() - 1] == 1){
            q.push({i, grid[0].size() - 1});
            grid[i][grid[0].size() - 1] = -1;
        }
    }      
        for(int i = 0; i < grid[0].size(); i++){
        if(grid[grid.size() - 1][i] == 1){
            q.push({grid.size() - 1, i});
            grid[grid.size() - 1][i] = -1;
        }
    }

    int dRow[4] = {-1, 1, 0, 0};
    int dCol[4] = {0, 0, -1, 1};


    while(!q.empty()){
        auto top = q.front();
        q.pop();
        for(int idx = 0; idx < 4; idx++){
            int currRow = top.first + dRow[idx];
            int currCol = top.second + dCol[idx];

            if(currRow >= 0 && currRow < grid.size() && currCol >= 0 && currCol < grid[0].size() && grid[currRow][currCol] == 1){
                q.push({currRow, currCol});
                grid[currRow][currCol] = -1;
            }
        }
    }            

    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == 1) ctr++;
        }
    }
    return ctr;
    }
};
// @lc code=end

