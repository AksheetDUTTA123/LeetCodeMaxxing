#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currMin = nums[0];
        int globalMin = nums[0];
        int currMax = nums[0];
        int globalMax = nums[0];
        int totalSum  = 0;

        for(int i = 0; i < nums.size(); i++) totalSum += nums[i];

        for(int i = 1; i < nums.size(); i++){
            currMin = min(nums[i], currMin + nums[i]);
            globalMin = min(globalMin, currMin);

            currMax = max(nums[i], currMax + nums[i]);
            globalMax = max(currMax, globalMax); 
        }

        if(globalMax < 0){ //need this because if all numbers are negative, 
        //then totalSum - globalMin will be 0, which is not the correct answer. In this case, we just return the maximum number in the array, which is globalMax.
            return globalMax;
        }
        //taking the sum of the whole array and subtracting the minimum subarray sum will give us the maximum circular subarray sum.
        return max(globalMax, totalSum - globalMin);
    }
};
// @lc code=end

