#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1929 lang=cpp
 *
 * [1929] Concatenation of Array
 */

// @lc code=start
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int numsSize = nums.size();
        for(int i = 0; i < numsSize; i++){
            nums.push_back(nums[i]);
        }
        return nums;
    }
};
// @lc code=end

