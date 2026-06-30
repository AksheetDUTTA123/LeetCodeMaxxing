#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1572 lang=cpp
 *
 * [1572] Matrix Diagonal Sum
 */

// @lc code=start
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int leftToRight = 0;
        int rightToLeft = 0;
        int totalSum = 0;
        for(int i = 0; i < mat.size(); i++){
            // for(int j = 0; j < mat[0].size(); j++){
            //     if(i - j == 0) leftToRight += mat[i][j];
            // }
            totalSum += mat[i][i];
            totalSum += mat[i][mat.size() - i - 1];
        }
        // for(int i = mat.size() -1; i >= 0; i--){
        //     for(int j = 0; j < mat[0].size(); j++){
        //         if(i + j == mat[0].size()- 1) rightToLeft += mat[i][j];
        //     }
        // }
        if(mat.size() % 2 != 0){
            totalSum -= mat[(mat.size() - 1) / 2][(mat[0].size() - 1) / 2];
            return totalSum;
        }else{
            return totalSum;
        }
        
    }
};
// @lc code=end

