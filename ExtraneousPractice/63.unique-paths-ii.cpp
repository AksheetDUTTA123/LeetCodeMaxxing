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
        //first thing we can do, traverse top row and left col, if there is a 1, replace everything with a 0
        if(obstacleGrid[0][0] == 1) return 0;
        if(obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] == 1) return 0;
        obstacleGrid[0][0] = 1; //1 way to get here, grid will store # of possibilities
        for(int i = 1; i < obstacleGrid.size(); i++){
                if(obstacleGrid[i][0] == 1) {
                    obstacleGrid[i][0] = 0;
                    for(int j = i; j < obstacleGrid.size(); j++){
                        obstacleGrid[j][0] = 0;
                    }
                    break;
                }
                obstacleGrid[i][0] = 1;
        }
        for(int i = 1; i < obstacleGrid[0].size(); i++){
                if(obstacleGrid[0][i] == 1) {
                    obstacleGrid[0][i] = 0;
                for(int j = i; j < obstacleGrid[0].size(); j++){
                        obstacleGrid[0][j] = 0;
                    }
                    break;
                }
                obstacleGrid[0][i] = 1;
        }

        for(int i = 1; i < obstacleGrid.size(); i++){
            for(int j = 1; j < obstacleGrid[0].size(); j++){
                if(obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = 0;
                    continue;
                } //first check, if obstacle, mark it as 0, cannot reach it
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
            }
        }

        return obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};
// @lc code=end

