#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expSum = nums.size() * (nums.size() + 1) / 2; //expected sum of numbers from 0 to n
        int currSum = accumulate(nums.begin(), nums.end(), 0); //current sum of numbers in the array;
        return expSum - currSum;
    }
};
// @lc code=end

