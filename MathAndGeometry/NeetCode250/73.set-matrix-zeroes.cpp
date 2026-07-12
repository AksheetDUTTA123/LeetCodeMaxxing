#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRowZero = false; //check if the first row has a zero, if so, we will need to set the entire first row to zero at the end
        bool firstColZero = false; //check if the first column has a zero, if so, we will need to set the entire first column to zero at the end
        for(int i = 0; i < matrix.size(); i++){
            if (matrix[i][0] == 0) firstColZero = true; //if we find a 0 in the first column, we set firstColZero to true
        }
        for(int i = 0; i < matrix[0].size(); i++){
            if (matrix[0][i] == 0) firstRowZero = true;
        }

        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0; //if we find a 0 , set the indicator row/col to 0
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < matrix.size(); i++){
            if(matrix[i][0] == 0){
                for(int j = 1; j < matrix[0].size(); j++){
                    matrix[i][j] = 0;
                    //if we found a 0 in the indicator row/col, we set the entire row/col to 0
                }
            }
        }

        for(int j = 1; j < matrix[0].size(); j++){
            if(matrix[0][j] == 0){
                for(int i = 1; i < matrix.size(); i++){
                    matrix[i][j] = 0;
                }
            }
        }

        if(firstColZero){
            for(int i = 0; i < matrix.size(); i++) matrix[i][0] = 0; //found a 0 originally in the indicator row/col, so we set the entire row/col to 0
        }
        if(firstRowZero){
            for(int i = 0; i < matrix[0].size(); i++) matrix[0][i] = 0;
        }
    }
};
// @lc code=end

