#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

// @lc code=start
class Solution {
private:
    int perimeter = 0;

    void perimeterCheck(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()){
            perimeter++;
            return;
        } 
        if(grid[i][j] == 0){
            perimeter++;
        }
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    perimeterCheck(grid, i+1, j);
                    perimeterCheck(grid, i-1, j);
                    perimeterCheck(grid, i, j+1);
                    perimeterCheck(grid, i, j - 1);
                }
            }
        }
        return perimeter;
    }
};
// @lc code=end

