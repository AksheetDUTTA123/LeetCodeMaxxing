#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //thought process, find the correct row, and then go through the columns
        int low = 0;
        int high = matrix.size()- 1; //access rows, not cols
        int mid = 0;
        int currRow = 0;
        while(low <= high){
            int mid = low + ((high - low) / 2);

            if(target == matrix[mid][0]) return true;
            else if(target < matrix[mid][0]) high = mid - 1;
            else{
                low = mid + 1;
                currRow = mid;
            }
        }

        //at this point, we found the correct Row (we think) we find the correct col now

        int colLow = 0;
        int colHigh = matrix[currRow].size() - 1;
        int colMid = 0;


        while(colLow <= colHigh){
            int colMid = colLow + ((colHigh - colLow) / 2);
            if(matrix[currRow][colMid] == target) return true;
            else if(matrix[currRow][colMid] < target){
                colLow = colMid + 1;
            }
            else{
                colHigh = colMid - 1;
            }
        }
        return false;

    }
};
// @lc code=end

