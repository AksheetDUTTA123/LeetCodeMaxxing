#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.size() == 0) return res;
        if (nums.size() == 1) {
            res.push_back(to_string(nums[0]));
            return res;
        }
        int rangeStart = 0;
        int rangeEnd = 1;
        while(rangeEnd < nums.size()){
            while(rangeEnd < nums.size() && nums[rangeEnd] == nums[rangeEnd -1] + 1){
                rangeEnd++;
            }
            if(rangeEnd - rangeStart == 1){
                res.push_back(to_string(nums[rangeStart]));
                rangeStart = rangeEnd;
                rangeEnd = rangeEnd + 1;
            }
            else{
                res.push_back(to_string(nums[rangeStart]) + "->" + to_string(nums[rangeEnd - 1]));
                rangeStart = rangeEnd;
                rangeEnd = rangeEnd + 1;
            }
        }

        if(rangeStart < nums.size()){
            res.push_back(to_string(nums[rangeStart]));
        }
    return res;
    }
};
// @lc code=end

