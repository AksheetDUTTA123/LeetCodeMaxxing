#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int MaxIndex = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > MaxIndex) return false;
            MaxIndex = max(nums[i] + i, MaxIndex);
        }
        return true;
    }
};
// @lc code=end

