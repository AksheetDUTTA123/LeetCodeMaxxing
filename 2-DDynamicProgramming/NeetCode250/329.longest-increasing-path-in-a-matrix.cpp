#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */

// @lc code=start
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));

        //lets do this with iterative dfs + memo

        int dRow[4] = {-1, 1, 0, 0};
        int dCol[4] = {0, 0, -1, 1};
        int maxPath = 0;

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(dp[i][j] != 0) continue; //if we have already computed the longest increasing path starting from this cell, skip it
                stack<pair<int, int>> s;

                s.push({i, j});


                while(!s.empty()){
                    auto curr = s.top();

                    if(dp[curr.first][curr.second] > 0){
                        s.pop();
                        continue; //here, we are checking if we have already computed the longest increasing path starting from this cell, if we have, we can skip it
                    }

                    if(dp[curr.first][curr.second] == -1){ //if -1, we are visiting for the second time, neighbors are calculated so we can solve for longest path here
                        s.pop();
                        int longestHere = 1;
                        for(int idx = 0; idx < 4; idx++){
                            int newRow = curr.first + dRow[idx];
                            int newCol = curr.second + dCol[idx];

                            if(newRow >= 0 && newRow < matrix.size() && newCol >= 0 && newCol < matrix[0].size() && matrix[newRow][newCol] > matrix[curr.first][curr.second]){
                                longestHere = max(longestHere, 1 + dp[newRow][newCol]);
                            }
                        }
                        dp[curr.first][curr.second] = longestHere; //store the longest increasing path starting from this cell in the dp array, store after checking all neighbors, because we want to make sure we have the longest path from this cell
                        maxPath = max(maxPath, longestHere);
                        continue;
                    }

                    dp[curr.first][curr.second] = -1; //this is the first time we are visiting
                    //now we push in unvisited neighbors into the stack

                    for(int idx = 0; idx < 4; idx++){
                            int newRow = curr.first + dRow[idx];
                            int newCol = curr.second + dCol[idx];

                            if(newRow >= 0 && newRow < matrix.size() && newCol >= 0 && newCol < matrix[0].size() && matrix[newRow][newCol] > matrix[curr.first][curr.second] && dp[newRow][newCol] == 0){
                                s.push({newRow, newCol});
                            }
                        }
                }

            }
        }

        return maxPath;
    }
};
// @lc code=end

