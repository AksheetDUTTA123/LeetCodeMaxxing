#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=867 lang=cpp
 *
 * [867] Transpose Matrix
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        res.resize(matrix[0].size(), vector<int>(matrix.size(), 0)); //just have to resize the matrix first

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                res[j][i] = matrix[i][j];
            }
        }
        return res;
    }
};
// @lc code=end

