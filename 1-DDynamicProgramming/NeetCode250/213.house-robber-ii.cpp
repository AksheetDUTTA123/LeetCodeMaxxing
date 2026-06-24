#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
private:
    int robCalc(vector<int>& nums, int start, int end){
        int prev = 0;
        int prevPrev = 0;
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        for(int i = start; i < end; i++){
            int robCurr = prevPrev + nums[i];
            int skipCurr = prev;
            int maxProf = max(robCurr, skipCurr);
            prevPrev = prev;
            prev = maxProf; 
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        return max(robCalc(nums, 1, nums.size()), robCalc(nums,0, nums.size() - 1));
        //the only real trick for this question is consider two cases
        //1. include the first element and dont include the last element
        //2. dont include the first element and include the last element
    }
};
// @lc code=end

