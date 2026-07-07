#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        obstacleGrid[0][0] = 1;
        for(int i = 1; i < obstacleGrid.size(); i++){
            if(obstacleGrid[i][0] == 1 || obstacleGrid[i - 1][0] == 0 ) {
                obstacleGrid[i][0] = 0; //all before that are 0 means everything later in the top row/side col should be 0'd out too
            }
            else obstacleGrid[i][0] = 1;
        }
        for(int i = 1; i < obstacleGrid[0].size(); i++){
            if(obstacleGrid[0][i] == 1 || obstacleGrid[0][i - 1] == 0 ) {
                obstacleGrid[0][i] = 0;
            }
            else obstacleGrid[0][i] = 1;
        }

        for(int i = 1; i < obstacleGrid.size(); i++){
            for(int j = 1; j < obstacleGrid[0].size(); j++){
                if(obstacleGrid[i][j] == 1) obstacleGrid[i][j] = 0;
                else obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
            }
        }
        return obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};
// @lc code=end

