#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=2812 lang=cpp
 *
 * [2812] Find the Safest Path in a Grid
 */

// @lc code=start
class Solution {
private:
    bool isValidPath(vector<vector<int>>& dist, int minSafe){

        //here, we use BFS to check if the potential path we can take will be at least as big as the minumum safety score we are looking for
         if(dist[0][0] < minSafe || dist[dist.size() - 1][dist[0].size() -1] < minSafe) return false;
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(dist.size(), vector<bool>(dist[0].size(), false));
        q.push({0, 0});
        visited[0][0] = true;
        int dRow[4] = {-1, 1, 0, 0};
        int dCol[4] = {0, 0, -1, 1};
        while (!q.empty()){
        auto top = q.front();
        q.pop();
        if(top.first == dist.size() - 1 && top.second == dist[0].size() - 1) return true;
        for(int idx = 0; idx < 4; idx++){
            int currRow = top.first + dRow[idx];
            int currCol = top.second + dCol[idx];

            if(currRow >= 0 && currRow < dist.size() && currCol >= 0 && currCol < dist[0].size() && !visited[currRow][currCol]
            && dist[currRow][currCol] >= minSafe){
                visited[currRow][currCol] = true;
                q.push({currRow, currCol});
            }
        }
        }
        return false;

    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        //first, do bfs from multi sources, the sources being the thieves
        if(grid[0][0] == 1 || grid[grid.size() - 1][grid[0].size() -1] == 1) return 0;
        queue<pair<int, int>> q;
        vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), -1));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid.size(); j++){
                if (grid[i][j] == 1) {
                    q.push({i, j});
                dist[i][j] = 0;
                }
            }
        }
    int dRow[4] = {-1, 1, 0, 0};
    int dCol[4] = {0, 0, -1, 1};

    int currDist = 0;
    while (!q.empty()){
        auto top = q.front();
        q.pop();
        if(grid[top.first][top.second] == 1) currDist = 0;
        for(int idx = 0; idx < 4; idx++){
            int currRow = top.first + dRow[idx];
            int currCol = top.second + dCol[idx];

            if(currRow >= 0 && currRow < grid.size() && currCol >= 0 && currCol < grid[0].size() && dist[currRow][currCol] == -1){
                dist[currRow][currCol] = dist[top.first][top.second] + 1;
                q.push({currRow, currCol});
            }
        }
        }  

    //now, lets do binary search, we know what the highest possible safety val is so we can BS this

    int low = 0;
    int high = 2 * grid.size();
    int ans = -1;

    while(low <= high){
        int mid = low + (high - low)/2;
        if(isValidPath(dist, mid)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;

    }
};
// @lc code=end

