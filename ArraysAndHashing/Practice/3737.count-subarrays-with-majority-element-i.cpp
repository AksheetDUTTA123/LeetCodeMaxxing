#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3737 lang=cpp
 *
 * [3737] Count Subarrays With Majority Element I
 */

// @lc code=start
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){ nums[i] =  1;} //logic, if the sum is greater than 0, then that element appeared the most in that substring
            else { nums[i] = -1;}
        }
        int totalCtr = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){ //o(n^2) in this question is acceptable.
            sum = 0;
            for(int j = i; j < nums.size(); j++){
                sum += nums[j];
                if (sum > 0) totalCtr++;
            }
        }
        return totalCtr;
    }
};
// @lc code=end

