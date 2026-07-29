#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3446 lang=cpp
 *
 * [3446] Sort Matrix by Diagonals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        if(grid.size() == 1) return grid;
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                mp[i-j].push_back(grid[i][j]);
            }
        }
        for (auto& [key, vec] : mp){
            if(key >=0){
                sort(vec.begin(), vec.end(), greater<int>());
            }
            else{
                sort(vec.begin(), vec.end());
            }
        }
        for(int i = grid.size() - 1; i >= 0; i--){
            for(int j = grid[0].size() - 1; j >= 0; j--){
                grid[i][j] = mp[i-j].back();
                mp[i-j].pop_back();
            }
        }
        return grid;
    }
};
// @lc code=end

