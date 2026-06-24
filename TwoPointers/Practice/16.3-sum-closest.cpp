#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int closestSum = 9999999;
        int closest = 99999;
        for(int i = 0; i < nums.size() - 2; i++){
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                if(abs(target - (nums[i] + nums[left] + nums[right])) < closestSum){
                    closest = nums[i] + nums[left] + nums[right];
                }
                closestSum = min(closestSum, abs(target - (nums[i] + nums[left] + nums[right])));
                if((nums[i] + nums[left] + nums[right]) < target){
                    left++;
                }
                else{
                    right--;
                }
            }

        }
        return closest;
    }
};
// @lc code=end

