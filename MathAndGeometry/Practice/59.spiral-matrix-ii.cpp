#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int top = 0;
        int bottom  = n - 1;
        int left = 0;
        int right = n-1;
        int currNum = 1;
        while(top <= bottom && left <= right){
            for(int i = left; i <= right; i++){
                matrix[top][i] = currNum;
                currNum++;
            }
            top++;

            for(int i = top; i <= bottom; i++){
                matrix[i][right] = currNum;
                currNum++;
            }
            right--;
            if(top <= bottom){
                for(int i = right; i >= left; i--){
                    matrix[bottom][i] = currNum;
                    currNum++;
                }
                bottom--;
            }

            if (left <= right){
                for(int i = bottom; i >= top; i--){
                    matrix[i][left] = currNum;
                    currNum++;
                }
                left++;
            }
        }
        return matrix;
    }
};
// @lc code=end

