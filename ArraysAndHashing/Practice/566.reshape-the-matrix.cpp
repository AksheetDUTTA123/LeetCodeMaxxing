#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<int> res;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                res.push_back(mat[i][j]);
            }
        }
        if(res.size() != r * c) return mat;
        vector<vector<int>> output(r, vector<int>(c, 0));
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                output[i][j] = res[(i*c) + j];
            }
        }
        return output;
    }
};
// @lc code=end

