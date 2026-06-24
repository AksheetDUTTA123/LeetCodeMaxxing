#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0) return false;
        int target = totalSum / 2;
        //if target can be formed for one subset, then the other subset will also have the same sum, because totalSum = 2 * target
        vector<bool> dp(target + 1, false);
        dp[0] = true; // base case, sum 0 can always be formed

        for(int num : nums){
            for(int i = target; i >= num; i--){ //traverse backwards to avoid using the same number multiple times
                if(dp[i-num]) dp[i] = true; //if we can form the sum i-num, then we can form the sum i by adding num to it
            }
        }
return dp[target];
    }
};
// @lc code=end

