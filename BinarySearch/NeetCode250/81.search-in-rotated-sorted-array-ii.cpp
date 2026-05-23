#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                return true;
            }

            //key point here, if there are duplicates, we can't determine which half of the array is sorted, so we can just move the left and right pointer until duplicates arent there
            //key note: duplicates exist in this problem!
            if(nums[mid] == nums[left] && nums[mid] == nums[right]){
                left++;
                right--;
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
        return false;
    }
};
// @lc code=end

