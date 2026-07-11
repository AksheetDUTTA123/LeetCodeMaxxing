#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //xor everything, result will be the one that appears once

        int xorSum = 0;

        for(int i = 0; i < nums.size(); i++){
            xorSum ^= nums[i];
        }

        return xorSum;
    }
};
// @lc code=end

