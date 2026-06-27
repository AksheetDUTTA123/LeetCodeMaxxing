#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
private:
void islandCheck(vector<vector<char>>& grid, int i , int j){
    int dRow[4] = {-1, 1, 0, 0}; //preload the row and column changes for the four directions (up, down, left, right)
    int dCol[4] = {0, 0, -1, 1}; 
queue<pair<int, int>> q; //use a BFS here, so a queue can be used to keep track of the current island's coordinates
q.push({i , j}); //push the current point, this is the starting point of the island
grid[i][j] = '0';
while(!q.empty()){
    auto top = q.front();
    q.pop(); //pop from queue, now we check neighbors and we check if they are land, if they are land, we push them into the queue and mark them as water
    for(int idx = 0; idx < 4; idx++){
        int newRow = top.first + dRow[idx];
        int newCol =  top.second + dCol[idx];

        if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == '1'){
            q.push({newRow, newCol}); //push the new point into the queue, this is a neighbor of the current point and is land
            grid[newRow][newCol] = '0'; //mark the new point as water, so we don't visit it again
        }
    }
}
}
public:
    int numIslands(vector<vector<char>>& grid) {
        int islandCount = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    islandCount++;
                    islandCheck(grid, i, j);
                    //if the queue is empty, then we have finished checking the current island, and we can move on to the next point in the grid
                }
            }
        }
        return islandCount;
    }
};
// @lc code=end

