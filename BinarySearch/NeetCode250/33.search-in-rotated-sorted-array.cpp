#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] >= nums[left]){ //if mid is greater than or equal to left, then the left half of the array is sorted.
                if(nums[mid] > target  && target >= nums[left]){ //if target is less than mid and greater than or equal to left, then the target must be in the left half of the array
                    right = mid -1;
                }
                else{ //if the target is greater than mid or less than left, then the target must be in the right half of the array
                    left = mid + 1;
                }
            }
            else{ // if mid is less than left, then the right half of the array is sorted
                if(nums[mid] < target && target <= nums[right]){ //if target is greater than mid and less than or equal to right, then the target must be in the right half of the array
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

