#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) sum += num;
        //start here
        int leftSum = 0;
        int rightSum = sum - nums[0];
        if(leftSum == rightSum) return 0;
        for(int i = 1; i < nums.size(); i++){
            leftSum += nums[i-1];
            rightSum -= nums[i];
            if(leftSum == rightSum) return i;
        }
        return -1;

    }
};
// @lc code=end

