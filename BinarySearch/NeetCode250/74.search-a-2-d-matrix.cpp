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
        //need two log searches, search once by finding exactly which row it is
        //and then, look through the row do binary search to find it
        int start = 0;
        int targetRow = -1;
        int end = matrix.size() - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(target >= matrix[mid][0] && target <= matrix[mid][matrix[0].size() - 1]){ //if the target is between the first and last element of the row, target must be in this row
                targetRow = mid;
                break;
            }
            else if(matrix[mid][matrix[0].size() - 1] < target){ //need to compare the last element of the row, because if the target is greater than the last element of the row, must be in a row below
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }

            }
            if(targetRow < 0) return false; //couldnt be found, return false

            int left = 0;
            int right = matrix[0].size() - 1;
            while(left <= right){
            int mid = left + (right - left)/2;
            if(target == matrix[targetRow][mid]){
                return true;
            }
            else if(matrix[targetRow][mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }

            }
            return false;

            
    }
};
// @lc code=end

