#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
//use binary search to find the kth smallest element in a sorted matrix, 
//we can use the fact that the matrix is sorted to our advantage. 
//We can use binary search on the range of values in the matrix, and for each mid value,
// we can count how many elements are less than or equal to mid. If that count is greater than or equal to k,
// we know that the kth smallest element must be less than or equal to mid, so we can adjust our search range accordingly. 
//Otherwise, we know that the kth smallest element must be greater than mid, so we adjust our search range in the other direction.
class Solution {
private:
    int countLess(vector<vector<int>>& matrix, int mid){
        int count = 0;
        int row = matrix.size() - 1;
        int col = 0;


        while(row>= 0 && col < matrix.size()){
            if(matrix[row][col] <= mid){
                count += (row + 1); //this checks how many numbers are less than or equal to mid in the current column, 
                //and adds that to the count
                col++; //we increment the column because we know that all the numbers in the current column are less than or equal to mid,
            }
            else{
                row--; //we decrement the row because we know that all the numbers in the current row are greater than mid, so we need to check the previous row and see how many numbers are less than or
                // equal to mid in that row
            }
        }
        return count;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int low = matrix[0][0];
        int high = matrix[matrix.size() -1][matrix[0].size()-1];
        int ans = low;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(countLess(matrix, mid) >= k){ //check if mid is the kth smallest element, 
            //if it is, we can adjust our search range to find a smaller value that is also the kth smallest element
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }

    return ans;
    }
};
// @lc code=end

