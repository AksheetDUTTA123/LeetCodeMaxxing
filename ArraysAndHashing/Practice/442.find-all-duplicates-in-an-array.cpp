#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
        int val = abs(nums[i]);
        int targetIdx = val - 1;
        if(nums[targetIdx] < 0) res.push_back(val);
        else nums[targetIdx] = -nums[targetIdx];
        }
        return res;
    }
};
// @lc code=end

