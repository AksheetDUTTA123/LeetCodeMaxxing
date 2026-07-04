#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];
        if(nums.size() == 1) return nums[0];

        for(int i = 1; i < nums.size(); i++){
            currentSum = std::max(nums[i], nums[i] + currentSum); //currentSum checks the largest possible sum you can have at index i
            maxSum = max(currentSum, maxSum);
        }
        return maxSum;
    }
};
// @lc code=end

