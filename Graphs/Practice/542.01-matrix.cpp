#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int dRow[4] = {-1, 1, 0, 0};
        int dCol[4] = {0, 0, 1, -1};
        std:queue<tuple<int, int, int>> q;
        vector<vector<int>> res(mat.size(), vector<int>(mat[0].size(), 0));
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j] == 0) {
                    q.push({i, j, 0});
                    mat[i][j] = -1;
                }
            }
        }
    //added all 0's to the queue
    while(!q.empty()){
        auto [currRow, currCol, currDist] = q.front();
        q.pop();
        res[currRow][currCol] = currDist;
        for(int i = 0; i < 4; i++){
            int newRow = currRow + dRow[i];
            int newCol = currCol + dCol[i];

            if(newRow >=0 && newRow < mat.size() && newCol >= 0 && newCol < mat[0].size() && mat[newRow][newCol] != -1){
                q.push({newRow, newCol, currDist + 1});
                mat[newRow][newCol] = -1;
            }
        }
    }
    return res;
    }
};
// @lc code=end

