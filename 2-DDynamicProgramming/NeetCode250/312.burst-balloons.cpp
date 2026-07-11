#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));//dp[left][right] = max coins we can get from bursting all the balloons between left and right, exclusive

        for(int length = 1; length < nums.size() - 1; length++){ //length represents the length of the subarray we are considering, we start from length 1 because we want to consider the smallest subarrays first, and build up to larger subarrays
            for(int left = 1; left < nums.size() - length; left++){ //go from left to right, we start from 1 because we don't want to consider the first balloon, and we go to nums.size() - length because we don't want to consider the last balloon
                int right = left + length - 1; //right is the boundary of the subarray we are considering, we subtract 1 because we want to consider the last balloon in the subarray
                //this subarray represents the balloons we are considering to burst, and we want to find the maximum coins we can get from bursting all the balloons in this subarray

                for(int i = left; i <= right; i++){
                    int currCoins = nums[left - 1] * nums[i] * nums[right+ 1] + dp[left][i-1] + dp[i+1][right];
                    //currcoins is the coins we get from bursting the balloon at index i, plus the coins we get from bursting all the balloons to the left of i, plus the coins we get from bursting all the balloons to the right of i
                    //nums[left - 1] and nums[right + 1] are the balloons that are adjacent to the subarray we are considering, and they will be the last balloons to be burst in the subarray, so we multiply them together with nums[i] to get the coins we get from bursting the balloon at index i
                    //dp[left][i-1] and dp[i+1][right] are the coins we get from bursting all the balloons to the left and right of i, respectively, and we add them together to get the total coins we get from bursting all the balloons in the subarray
                    dp[left][right] = max(dp[left][right], currCoins);
                }
            }
        }
        return dp[1][nums.size() - 2];
    }
};
// @lc code=end

