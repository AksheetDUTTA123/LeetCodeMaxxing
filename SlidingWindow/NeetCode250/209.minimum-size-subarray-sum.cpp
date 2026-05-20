#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int leftPtr= 0;
        int total = 0;
        int minLen = INT_MAX;
        for(int i = 0; i< nums.size(); i++){
            total += nums[i];

            while(total >= target){
                minLen = min(minLen, i - leftPtr + 1);
                total -= nums[leftPtr];
                leftPtr++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};
// @lc code=end

