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
        if(nums.size() == 1){
            if(nums[0] == target) return true;
            else return false;
        }
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = left + ((right - left)/2);
            if(nums[mid] == target) return true;
            if(nums[left] == nums[mid] && nums[mid] == nums[right]){
                left++;
                right--;
                continue;
            }
            //now, we have to check if left side or right side is sorted
            if(nums[left] <= nums[mid]){
                if(nums[left] <= target && target < nums[mid]){
                    right = mid - 1;
                }
                else{
                    left = mid  + 1;
                }
            }
            else{
                if(nums[mid] < target && target <= nums[right]){
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

