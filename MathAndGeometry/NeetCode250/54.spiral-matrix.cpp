#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int top = 0; 
        int left = 0;
        int bottom = matrix.size() - 1;
        int right = matrix[0].size() - 1;

        while(top <= bottom && left <= right){ //keep going until we have covered all rows and columns
            for(int i = left; i <= right; i++){
                res.push_back(matrix[top][i]); //push the top row from left to right
            }
            top++;
            for(int i = top; i <= bottom; i++){
                res.push_back(matrix[i][right]); //push the right column from top to bottom
            }
            right--;

            if(top <= bottom){ //check if we still have rows to cover, if so, push the bottom row from right to left
            for(int i = right; i >=left; i--){
                res.push_back(matrix[bottom][i]);
            }
            bottom--;}

            if(left <= right) //check if we still have columns to cover, if so, push the left column from bottom to top
            {for(int i = bottom; i >= top; i--){
                res.push_back(matrix[i][left]);
            }
            left++;}
        }
    return res;
    }
};
// @lc code=end

