#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution {
private:
int maxIslandSize = 0;
int currIslandSize(vector<vector<int>>& grid, int i, int j){
    int sizeCurr = 1; //come back to this, have to count the starting as size 1
    grid[i][j] = 0; //and now we also have to set it to 0 so we dont double count it/infinite loop
    int dRow[4] = {-1, 1, 0, 0};
    int dCol[4] = {0, 0, -1, 1};
    queue<pair<int, int>> q;
    q.push({i, j});
    while(!q.empty()){
        auto top = q.front();
        q.pop();
        for(int idx = 0; idx < 4; idx++){
            int currRow = top.first + dRow[idx];
            int currCol = top.second + dCol[idx];

            if(currRow >= 0 && currRow < grid.size() && currCol >= 0 && currCol < grid[0].size() && grid[currRow][currCol] == 1){
                q.push({currRow, currCol});
                grid[currRow][currCol] = 0;
                sizeCurr++;
            }
        }
    }
    return sizeCurr;
}
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    maxIslandSize = max(maxIslandSize, currIslandSize(grid, i, j));
                }
            }
        }
        return maxIslandSize;
    }
};
// @lc code=end

