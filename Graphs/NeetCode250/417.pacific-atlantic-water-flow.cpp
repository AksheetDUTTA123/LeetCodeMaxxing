#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<pair<int, int>> atlanticQueue; //need two queues, will be BFS'ing from left top corner and bottom right corner and the edges, REMEMBER THE EDGES
        queue<pair<int, int>> pacificQueue;
        vector<vector<int>> res; //store the positions where water can flow to either atlantic or pacific
        vector<vector<bool>> pacificVisited(heights.size(), vector<bool>(heights[0].size(), false)); //these are all values that can flow to the pacific
        vector<vector<bool>> atlanticVisited(heights.size(), vector<bool>(heights[0].size(), false)); //these are all values that can flow to the atlantic
        int dRow[4] = {-1, 1, 0, 0};
        int dCol[4] = {0, 0, -1, 1};

        //do 4 loops here, have to push the corner edges into the queues and mark them as visited, we will be starting our BFS from here
        for(int i = 0; i < heights.size(); i++){
            pacificQueue.push({i, 0});
            pacificVisited[i][0] = true;
        }
        for(int i = 0; i < heights[0].size(); i++){
            pacificQueue.push({0, i});
            pacificVisited[0][i] = true;
        }
        for(int i = 0; i < heights.size(); i++){
            atlanticQueue.push({i, heights[0].size() - 1});
            atlanticVisited[i][heights[0].size() - 1] = true;
        }
        for(int i = 0; i < heights[0].size(); i++){
            atlanticQueue.push({heights.size() - 1, i});
            atlanticVisited[heights.size() - 1][i] = true;
        }

        //start with pacific, pop, do bfs, push to queue and visit if the surrounding vals are greater(flow from high to low),
        //we havent visited yet, and we are in bounds
        while(!pacificQueue.empty()){
            auto curr = pacificQueue.front();
            pacificQueue.pop();
            for(int idx = 0; idx < 4; idx++){
                int currRow = curr.first + dRow[idx];
                int currCol = curr.second + dCol[idx];


                if(currRow >= 0 && currRow < heights.size() && currCol >= 0 && currCol < heights[0].size() &&
                heights[currRow][currCol] >= heights[curr.first][curr.second] && !pacificVisited[currRow][currCol]){
                    pacificQueue.push({currRow, currCol});
                    pacificVisited[currRow][currCol] = true;
                }
            }
        }

        //do the same for atlantic, pop, do bfs, push to queue and visit if the surrounding vals are greater(flow from high to low),
        //we havent visited yet, and we are in bounds
        while(!atlanticQueue.empty()){
            auto curr = atlanticQueue.front();
            atlanticQueue.pop();
            for(int idx = 0; idx < 4; idx++){
                int currRow = curr.first + dRow[idx];
                int currCol = curr.second + dCol[idx];


                if(currRow >= 0 && currRow < heights.size() && currCol >= 0 && currCol < heights[0].size() &&
                heights[currRow][currCol] >= heights[curr.first][curr.second] && !atlanticVisited[currRow][currCol]){
                    atlanticQueue.push({currRow, currCol});
                    atlanticVisited[currRow][currCol] = true;
                }
            }
        }

        //in this question, push to result if we visited in both pacific and atlantic, this means that the water can flow to either, we determined this from our BFS operations
        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                if(pacificVisited[i][j] && atlanticVisited[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }
};
// @lc code=end

