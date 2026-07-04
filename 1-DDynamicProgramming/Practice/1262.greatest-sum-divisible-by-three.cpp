#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1262 lang=cpp
 *
 * [1262] Greatest Sum Divisible by Three
 */

// @lc code=start
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // vector<int> divMod1;
        // vector<int> divMod2;
        // vector<int> divMod0;
        // int sum = 0;
        // for(int i = 0; i < nums.size(); i++){
        //     sum += nums[i];
        //     if(nums[i] % 3 == 0) divMod0.push_back(nums[i]);
        //     else if (nums[i] % 3 == 1) divMod1.push_back(nums[i]);
        //     else divMod2.push_back(nums[i]);
        // }

        // sort(divMod1.begin(), divMod1.end());
        // sort(divMod2.begin(), divMod2.end());
        // if (sum % 3 == 1){
        //     int op1 = INT_MAX;
        //     if(divMod1.size() > 0){
        //         op1 = divMod1[0];
        //     }
        //     int op2 = INT_MAX;
        //     if(divMod2.size() > 1){
        //         op2 = divMod2[0] + divMod2[1];
        //     }

        //     sum -= min(op1, op2);
        //     return sum;
        // }
        // else if (sum % 3 == 2){

        //     int op1 = INT_MAX;
        //     if(divMod2.size() > 0){
        //         op1 = divMod2[0];
        //     }
        //     int op2 = INT_MAX;
        //     if(divMod1.size() > 1){
        //         op2 = divMod1[0] + divMod1[1];
        //     }
        //     sum -= min(op1, op2);
        //     return sum;
        // }
        // else{
        //     return sum;
        // }
        // return sum;

        //doing the dp sum now

        vector<int> dp = {0, -1, -1}; 

        for(int num : nums){
            vector<int> copy = dp;
            for(int i = 0; i < 3; i++){
                if(dp[i] == -1) continue; //if the current sum is not possible, we cannot add the current number to it, so we skip it
                int newSum = dp[i] + num;
                int newRem = newSum % 3;
                copy[newRem] = max(copy[newRem], newSum);
            }
            dp = copy;
        }
        return dp[0];
    }
};
// @lc code=end

