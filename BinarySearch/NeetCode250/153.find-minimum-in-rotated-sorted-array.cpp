#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right){
            int mid = left + (right - left) / 2;

            if(nums[mid] > nums[right]){ //have to compare with right and not left because if mid is greater than right, then we know that the minimum value must be in the right half of the array. 
            //If we compared with left, we wouldn't be able to determine which half of the array contains the minimum value because the left half could still be sorted and contain the minimum value, or it could be rotated and contain the minimum value as well. 
            //By comparing with right, we can determine that the minimum value must be in the right half of the array if mid is greater than right, and if mid is less than or equal to right, then the minimum value must be in the left half of the array.

                left = mid + 1; //min is in the right half
            }
            else{
                right = mid; //min is in the left half
            }
            /*
            Your assumption that "if left half is sorted, minimum must be in right half" is FALSE when:

            The array isn't rotated (minimum at left)
            The rotation point is in the right half (left half is sorted but minimum is actually at the very left)
            
            */

        }
        return nums[left];
    }
};
// @lc code=end

