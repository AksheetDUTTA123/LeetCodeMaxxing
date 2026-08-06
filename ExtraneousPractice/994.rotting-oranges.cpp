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
        int time = 0;
        //multi source BFS, we want to add all of the rotten oranges in the queue First
        int dRow[4] = {-1, 1, 0, 0};
        int dCol[4] = {0, 0, -1, 1};
        queue<pair<int, int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2) q.push({i, j});
            }
        }

        //we have all the first rotten oranges being tracked now

        while(!q.empty()){
            int qSize = q.size();

            for(int i = 0; i < qSize; i++){
                auto orangeCord = q.front();
                q.pop();

                for(int j = 0; j < 4; j++){
                    int newRow = orangeCord.first + dRow[j];
                    int newCol = orangeCord.second + dCol[j];

                    if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == 1){
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                    }
                }
            }
            time++;
        }

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        if(time == 0) return 0;
        else return time - 1;
    }
};
// @lc code=end

