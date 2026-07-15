#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1631 lang=cpp
 *
 * [1631] Path With Minimum Effort
 */

// @lc code=start
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int dRow[4] = {-1, 1, 0, 0};
        int dCol[4] = {0, 0, -1, 1};
        vector<vector<int>> map(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        //in this map, we will store the minimum effort required to reach each cell in the heights matrix, and we will initialize it to INT_MAX, because we want to find the minimum effort path, and we will update it as we explore the matrix
        map[0][0] = 0; //difference at starting distance is 0
        //our priority queue has to store effort, row, col
        std::priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        //a priority queue is needed in djikstra's algorithm, because we want to explore the cell with the minimum effort first, 
        //and we will use a min heap to store the cells in the priority queue, and we will use a tuple to store the effort, row, and col of each cell, and we will use a greater comparator to make it a min heap
        pq.push({0, 0, 0});
        while(!pq.empty()){
            auto [currEffort, currRow, currCol] = pq.top();
            pq.pop();

            if(currRow == heights.size() -1 && currCol == heights[0].size() - 1) return currEffort;
            if(currEffort > map[currRow][currCol]) continue; //this path will not produce the minEffortPath

            for(int i = 0; i < 4; i++){
                int newRow = currRow + dRow[i];
                int newCol = currCol + dCol[i];
                int newCurrEffort = INT_MAX;
                if(newRow >= 0 && newRow < heights.size() && newCol >= 0 && newCol < heights[0].size()){
                    newCurrEffort = max(currEffort, abs(heights[currRow][currCol] - heights[newRow][newCol]));
                } //we want to take the max of the current effort and the absolute difference between the current cell and the new cell, because we want to find the path with the minimum effort, and we will update the map with the new effort if it is less than the current effort in the map

                if(newRow >= 0 && newRow < heights.size() && newCol >= 0 && newCol < heights[0].size() && newCurrEffort < map[newRow][newCol]){ //have to check if newCurrEffort is less than the current effort in the map, 
                //because we want to find the minimum effort path, and if it is less, then we will update the map and push the new cell into the priority queue
                    map[newRow][newCol] = newCurrEffort;
                    pq.push({newCurrEffort, newRow, newCol});
                }
            }
        }

        return map[heights.size()- 1][heights[0].size() - 1];
    }
};
// @lc code=end

