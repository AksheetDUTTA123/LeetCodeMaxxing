#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=2373 lang=cpp
 *
 * [2373] Largest Local Values in a Matrix
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> maxLocal(grid.size() - 2, vector<int>(grid.size() - 2, -1));
        int startI = 0;
        int startJ = 0;
        for(int i = startI; i < grid.size() - 2; i++){
            for(int j = startJ; j < grid.size() - 2; j++){
                int newmax = -1;
                for(int x = i; x < i + 3; x++){
                    for(int y = j; y < j + 3; y++){
                        if(grid[x][y] > newmax) newmax = grid[x][y];
                    }
                }
                maxLocal[i][j] = newmax;
            }
        }
        return maxLocal;
    }
};
// @lc code=end

