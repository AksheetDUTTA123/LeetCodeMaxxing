#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        //have to build prefix sum table here
        prefixSum.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for(int i = 0; i < matrix.size(); i++){
         for(int j = 0; j < matrix[0].size(); j++){
            prefixSum[i+1][j+1] = matrix[i][j] + prefixSum[i][j+1] + prefixSum[i+1][j] - prefixSum[i][j];
         }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        sum = prefixSum[row2+1][col2+1] - prefixSum[row1][col2+1] -  prefixSum[row2+1][col1] + prefixSum[row1][col1]; 
        return sum;
    }

    private:
    vector<vector<int>> prefixSum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

